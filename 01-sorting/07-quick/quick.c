#include "../utils.h"

/**
 * @brief 快速排序
 *        大体思想：把比pivot小的换到前面
 *
 * @param arr 数组
 * @param low 最左边索引
 * @param high 最右边索引
 * @return int 划分位置
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        // 比pivot小的，全部换到前面去
        if (arr[j] < pivot)
            swap(&arr[j], &arr[i++]);
    }
    // 此时，i指向的元素一定大于等于pivot
    swap(&arr[high], &arr[i]);
    return i;
}

/**
 * @brief 递归划分
 *
 * @param arr 数字
 * @param low 左边界下标
 * @param high 右边界下标
 */
void qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        qsort(arr, low, mid - 1);
        qsort(arr, mid + 1, high);
    }
}

/**
 * @brief 快速排序入口
 *
 * @param arr 数组
 * @param len 长度
 */
void quick_sort(int arr[], int len)
{
    qsort(arr, 0, len - 1);
}

int main(int argc, char const *argv[])
{
    test(&quick_sort);
    return 0;
}
