#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DISK_SIZE 32

typedef struct {
    int start;
    int size;
    int valid;
} Allocation;

int bitmap[DISK_SIZE];

void init_bitmap() {
    for (int i = 0; i < DISK_SIZE; i++) {
        bitmap[i] = 0;
    }
}

Allocation bitmap_allocate(int size) {
    Allocation a = {-1, size, 0};
    int count = 0;
    int start = -1;

    for (int i = 0; i < DISK_SIZE; i++) {
        if (bitmap[i] == 0) {
            if (count == 0)
                start = i;
            count++;

            if (count == size) {
                for (int j = start; j < start + size; j++)
                    bitmap[j] = 1;

                a.start = start;
                a.valid = 1;
                return a;
            }
        } else {
            count = 0;
        }
    }
    return a;
}

void print_bitmap() {
    for (int i = 0; i < DISK_SIZE; i++)
        printf("%d ", bitmap[i]);
    printf("\n");
}

int main() {
    init_bitmap();

    int sizes[15] = {2,3,5,2,4,6,1,3,5,2,4,3,2,1,5};

    printf("Bitmap Allocation (AI)\n");

    for (int i = 0; i < 15; i++) {
        bitmap_allocate(sizes[i]);
        print_bitmap();
    }
    return 0;
}
1s  
