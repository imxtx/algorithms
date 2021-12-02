#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils.h"

/**
 * @brief 计数排序
 *
 * @param arr 数组
 * @param len 元素个数
 */
void counting_sort(int arr[], int len)
{
    if (len < 1) return;

    // 寻找最大的元素
    int max = arr[0];
    for (size_t i = 1; i < len; i++)
        if (arr[i] > max) max = arr[i];

    // 分配一个长度为max+1的数组存储计数，并初始化为0
    int *count = (int *)malloc(sizeof(int) * (max + 1));
    memset(count, 0, sizeof(int) * (max + 1));

    // 计数
    for (size_t i = 0; i < len; i++)
        count[arr[i]]++;

    // 统计计数的累计值
    for (size_t i = 1; i < max + 1; i++)
        count[i] += count[i - 1];

    // 创建一个临时数组保存结果
    int *output = (int *)malloc(sizeof(int) * len);

    // 将元素放到正确的位置上
    for (size_t i = 0; i < len; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 将结果复制回原数组
    for (size_t i = 0; i < len; i++)
        arr[i] = output[i];
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 1, 2, 5, 3, 4, 8, 7};
    print_arr(arr, 9);
    counting_sort(arr, 9);
    print_arr(arr, 9);
    return 0;
}
