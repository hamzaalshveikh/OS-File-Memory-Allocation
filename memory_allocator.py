from dataclasses import dataclass
from typing import List, Tuple, Optional

MEM_SIZE = 100
Segment = Tuple[int, int]

def merge_free_list(free_list: List[Segment]) -> List[Segment]:
    free_list.sort()
    merged = []

    for start, size in free_list:
        if not merged or merged[-1][0] + merged[-1][1] < start:
            merged.append((start, size))
        else:
            last_start, last_size = merged[-1]
            merged[-1] = (last_start, last_size + size)

    return merged

@dataclass
class Allocator:
    free_list: List[Segment]
    next_fit_index: int = 0

    @staticmethod
    def new():
        return Allocator([(0, MEM_SIZE)])

    def allocate_best_fit(self, size: int) -> Optional[int]:
        candidates = [(i, seg) for i, seg in enumerate(self.free_list) if seg[1] >= size]
        if not candidates:
            return None
        idx, (start, length) = min(candidates, key=lambda x: x[1][1])
        self.free_list[idx] = (start + size, length - size)
        return start

    def allocate_worst_fit(self, size: int) -> Optional[int]:
        idx, (start, length) = max(self.free_list, key=lambda x: x[1])
        if length < size:
            return None
        self.free_list.remove((start, length))
        self.free_list.append((start + size, length - size))
        return start

    def allocate_next_fit(self, size: int) -> Optional[int]:
        n = len(self.free_list)
        for i in range(n):
            idx = (self.next_fit_index + i) % n
            start, length = self.free_list[idx]
            if length >= size:
                self.free_list[idx] = (start + size, length - size)
                self.next_fit_index = idx
                return start
        return None
