#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 二分查找
 * 
 * @param target 要查找的数
 * @param arr 待查找的数组
 * @param len 数组长度
 * @return int 存在返回下标, 否则返回-1
 */
int my_bsearch(int target, int arr[], int len)
{
    int l = 0, r = len - 1;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] < target)  
            l = mid + 1;
        else if (target < arr[mid])
            r = mid - 1;
        else
            return mid;
    }
    // return l; // 返回插入位置
    return -1;
}

int main(int argc, char const *argv[])
{
    if (argc < 3) 
        return 0;
    
    int target = atoi(argv[1]); // 要查找的数
    int len = argc - 2;         // 数组长度
    int *arr = (int *)malloc(sizeof(int)*len); // 后面的参数作为数组
    for (size_t i = 0; i < len; i++)
        arr[i] = atoi(argv[i+2]);

    // int arr[] = {1, 2, 4, 6, 7, 10, 11, 19, 24, 30};
    printf("target: %d, pos: %d\n", target, my_bsearch(target, arr, len));
    
    return 0;
}
