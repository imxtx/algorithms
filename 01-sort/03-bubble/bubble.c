#include "../utils.h"

/**
 * 冒泡排序
 * @param arr 待排序数组
 * @param len 数组长度
 */
void bubble_sort(int arr[], int len)
{
    // 外层循环：逐趟扫描
    // i>1的原因：只有一个元素的数组自然有序
    for (int i = len; i > 1; i--)
    {
        int swapped = 0;  // 是否发生了交换的标志
        // 一趟扫描
        for (int j = 1; j < i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;  // 若无交换发生，结束
    }
}

int main(int argc, char const *argv[])
{
    test(&bubble_sort);
    return 0;
}
