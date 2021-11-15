#include "../utils.h"

// 希尔排序
void shell_sort(int arr[], int len)
{
    int i, j, inc, key;
    // 初始增量：len/2，每一趟之后除以二
    for (inc = len / 2; inc > 0; inc /= 2)
    {
        // 每一趟采用插入排序
        for (i = inc; i < len; i++)
        {
            key = arr[i];
            for (j = i; j >= inc && key < arr[j - inc]; j -= inc)
                arr[j] = arr[j - inc];
            arr[j] = key;
        }
    }
}

int main(int argc, char const *argv[])
{
    test(&shell_sort);
    return 0;
}
