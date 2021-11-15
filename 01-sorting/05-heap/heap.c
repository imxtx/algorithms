#include "../utils.h"

/**
 * 维护堆的性质
 * @param arr 存储堆的数组
 * @param len 数组长度
 * @param i 待维护节点的下标
 */
void heapify(int arr[], int len, int i)
{
    int largest = i;
    int lson = i * 2 + 1;
    int rson = i * 2 + 2;

    if (lson < len && arr[largest] < arr[lson])
        largest = lson;
    if (rson < len && arr[largest] < arr[rson])
        largest = rson;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, len, largest);
    }
}

// 堆排序入口
void heap_sort(int arr[], int len)
{
    int i;
    // 建堆
    for (i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);

    // 排序
    for (i = len - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    test(&heap_sort);
    return 0;
}
