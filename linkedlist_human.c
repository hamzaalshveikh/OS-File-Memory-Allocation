#include <stdio.h>

#define DISK_SIZE 32

int used[DISK_SIZE];
int next[DISK_SIZE];
int free_start;

void init_disk() {
    for (int i = 0; i < DISK_SIZE; i++) {
        used[i] = 0;
        next[i] = i + 1;
    }
    next[DISK_SIZE - 1] = -1;
    free_start = 0;
}

void allocate_list(int size) {
    int current = free_start;
    int prev = -1;

    for (int i = 0; i < size; i++) {
        if (current == -1)
            return;

        used[current] = 1;

        if (prev != -1)
            next[prev] = next[current];
        else
            free_start = next[current];

        prev = current;
        current = free_start;
    }
}

void print_disk() {
    for (int i = 0; i < DISK_SIZE; i++)
        printf("%d ", used[i]);
    printf("\n");
}

int main() {
    init_disk();

    int requests[15] = {2,3,5,2,4,6,1,3,5,2,4,3,2,1,5};

    printf("Linked List Allocation (Human-written)\n");

    for (int i = 0; i < 15; i++) {
        allocate_list(requests[i]);
        print_disk();
    }
    return 0;
}
