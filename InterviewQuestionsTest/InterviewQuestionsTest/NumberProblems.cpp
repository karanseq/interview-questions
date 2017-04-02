// library includes
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

void PrintIntArray(int* arr, const int length)
{
    assert(arr);

    uint16_t i = 0;
    while (i < length)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%d", *(arr + i));
        ++i;
    }
    printf("\n");
}

/*
Given an array of ints move all the 0's to the end while maintaining the order of the non 0's in the list. Do this in place.
*/
void MoveZerosToEnd(int* arr, const int length)
{
    assert(arr);

    uint16_t i = 0;
    while (i < length)
    {
        if (*(arr + i) == 0)
        {
            uint16_t j = i + 1;
            while (j < length)
            {
                if (*(arr + j) != 0)
                {
                    int swap = *(arr + i);
                    *(arr + i) = *(arr + j);
                    *(arr + j) = swap;
                    break;
                }
                ++j;
            }
        }
        ++i;
    }
}

void TestMoveZerosToEnd()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    int arr1[] = { 0, 1, 0, 2, 0, 3, 0 };

    printf("Array before moving zeros to end:\n");
    PrintIntArray(arr1, 7);

    MoveZerosToEnd(arr1, 7);

    printf("Array after moving zeros to end:\n");
    PrintIntArray(arr1, 7);

    int arr2[] = { 0, 0, 0, 0, 1, 2, 3 };

    printf("Array before moving zeros to end:\n");
    PrintIntArray(arr2, 7);

    MoveZerosToEnd(arr2, 7);

    printf("Array after moving zeros to end:\n");
    PrintIntArray(arr2, 7);

    int arr3[] = { 6, 5, 0, 0, 1, 2, 3 };

    printf("Array before moving zeros to end:\n");
    PrintIntArray(arr3, 7);

    MoveZerosToEnd(arr3, 7);

    printf("Array after moving zeros to end:\n");
    PrintIntArray(arr3, 7);

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

