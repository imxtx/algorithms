#include "../utils.h"

void insertion_sort(int arr[], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        // 往后挪动比key小的值
        for (j = i; j >= 1 && key < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
        // 将key放到正确位置
        arr[j] = key;
    }
}

int main(int argc, char const *argv[])
{
    test(&insertion_sort);
    return 0;
}
