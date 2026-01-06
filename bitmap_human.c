#include <stdio.h>

#define DISK_SIZE 32

int disk[DISK_SIZE];

void reset_disk() {
    for (int i = 0; i < DISK_SIZE; i++)
        disk[i] = 0;
}

int allocate_bitmap(int size) {
    int free_count = 0;
    int start = -1;

    for (int i = 0; i < DISK_SIZE; i++) {
        if (disk[i] == 0) {
            if (free_count == 0)
                start = i;

            free_count++;

            if (free_count == size) {
                for (int j = start; j < start + size; j++)
                    disk[j] = 1;
                return start;
            }
        } else {
            free_count = 0;
        }
    }
    return -1;
}

void print_disk() {
    for (int i = 0; i < DISK_SIZE; i++)
        printf("%d ", disk[i]);
    printf("\n");
}

int main() {
    reset_disk();

    int requests[15] = {2,3,5,2,4,6,1,3,5,2,4,3,2,1,5};

    printf("Bitmap Allocation (Human-written)\n");

    for (int i = 0; i < 15; i++) {
        allocate_bitmap(requests[i]);
        print_disk();
    }
    return 0;
}
