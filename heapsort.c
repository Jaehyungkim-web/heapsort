#include <stdio.h>

typedef int element;

void SWAP(element* pa, element* pb) {
    element temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
    int ab = 3;
}

void percolateDown(element* pArr, int root, int end) {
    int child;
    while ((child = 2 * root + 1) <= end) {
        if (child < end && pArr[child] < pArr[child + 1]) {
            child++;
        }
        if (pArr[root] < pArr[child]) {
            SWAP(pArr + root, pArr + child);
            root = child;
        } else {
            break;
        }
    }
}

void heapSort(element* pArr, int num) {
    // 힙 생성
    for (int i = (num / 2) - 1; i >= 0; i--) {
        percolateDown(pArr, i, num - 1);
    }
    // 힙 정렬
    for (int i = num - 1; i > 0; i--) {
        SWAP(&pArr[0], &pArr[i]);
        percolateDown(pArr, 0, i - 1);
    }
}

void PRINT(element* pArr, const int num) {
    for (int i = 0; i < num; i++) {
        printf("%3d ", *(pArr + i));
    }
    printf("\n");
}

void abc() {
    printf("hello");
}

int main() {
    element arr[] = { 42, 66, 86, 2, 51, 60, 60, 10, 64, 46 };
    int num = sizeof(arr) / sizeof(arr[0]);
    printf("정렬 전: ");
    PRINT(arr, num);
    heapSort(arr, num);
    printf("정렬 후: ");
    PRINT(arr, num);
    return 0;
}