#include "../utils.h"

void selection_sort(int arr[], int len)
{
    int i, j, min;
    for (i = 0; i < len; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    test(&selection_sort);
    return 0;
}
