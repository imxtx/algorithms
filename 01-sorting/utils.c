/**
 * @file utils.c
 * @author imxtx
 * @brief Some helpers
 * @version 0.1
 * @date 2021-11-10
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 输出数组
 *
 * @param arr 数组
 * @param len 长度
 */
void print_arr(int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

/**
 * @brief 测试一个排序结果
 *
 * @param arr 排序后的数组
 * @param n 长度
 * @return int 0正确，1错误
 */
int check(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] != i)
            return 1;
    return 0;
}

/**
 * @brief 测试排序算法
 *
 * @param func_ptr 被测试函数的指针
 */
void test(void (*func_ptr)(int[], int))
{
    int nums[100] = {0};  // 用于存储一行数字
    int tmps[100] = {0};  // 存储行备份

    // 打开数字文件
    FILE *fp = fopen("../numbers.txt", "r");
    if (fp == NULL)  // 文件不存在或者其他错误
    {
        printf("fail to load text file\n");
        exit(EXIT_FAILURE);
    }

    // 测试排序结果
    char *line = NULL;  // 存储读入的一行字符串
    ssize_t nread;
    size_t len;
    while ((nread = getline(&line, &len, fp)) != -1)
    {
        int i = 0;
        char *pos = NULL;
        // 读取一行数字，存到数组
        while (1)
        {
            tmps[i] = strtol(line, &pos, 10);
            nums[i] = tmps[i];
            i += 1;
            if (*pos == '\n')
                break;
            line = pos;
        }
        // 排序
        (*func_ptr)(nums, i);
        // 检查
        if (check(nums, i))
        {
            printf("Test failed on: ");
            print_arr(tmps, i);
            exit(0);
        }
    }
    printf("All tests passed\n");

    fclose(fp);
}

/**
 * @brief 交换变量值
 *
 * @param a 第一个数字
 * @param b 第二个数字
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}