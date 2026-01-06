#include <stdio.h>

#define DISK_SIZE 32

int owner[DISK_SIZE];
int next_block[DISK_SIZE];
int free_head;

void init_disk() {
    for (int i = 0; i < DISK_SIZE; i++) {
        owner[i] = -1;
        next_block[i] = i + 1;
    }
    next_block[DISK_SIZE - 1] = -1;
    free_head = 0;
}

void allocate_blocks(int size) {
    int prev = -1;

    for (int i = 0; i < size; i++) {
        if (free_head == -1)
            return;

        int block = free_head;
        free_head = next_block[block];

        owner[block] = 1;
        next_block[block] = -1;

        if (prev != -1)
            next_block[prev] = block;

        prev = block;
    }
}

void print_disk() {
    for (int i = 0; i < DISK_SIZE; i++)
        printf("%d ", owner[i] != -1);
    printf("\n");
}

int main() {
    init_disk();

    int sizes[15] = {2,3,5,2,4,6,1,3,5,2,4,3,2,1,5};

    printf("Linked List Allocation (AI)\n");

    for (int i = 0; i < 15; i++) {
        allocate_blocks(sizes[i]);
        print_disk();
    }
    return 0;
}
