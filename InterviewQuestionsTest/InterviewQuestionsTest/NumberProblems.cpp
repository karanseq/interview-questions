// library includes
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void PrintIntArray(int* i_arr, const int i_length)
{
    assert(i_arr);

    uint16_t i = 0;
    while (i < i_length)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%d", *(i_arr + i));
        ++i;
    }
    printf("\n");
}

/*
Given an array of ints move all the 0's to the end while maintaining the order of the non 0's in the list. Do this in place.
*/
void MoveZerosToEnd(int* i_arr, const int i_length)
{
    assert(i_arr);

    uint16_t i = 0;
    while (i < i_length)
    {
        if (*(i_arr + i) == 0)
        {
            uint16_t j = i + 1;
            while (j < i_length)
            {
                if (*(i_arr + j) != 0)
                {
                    int swap = *(i_arr + i);
                    *(i_arr + i) = *(i_arr + j);
                    *(i_arr + j) = swap;
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

int AtoI(const char* i_str)
{
    assert(i_str);

    int result = 0;

    bool found_number = false;
    int sign = 1;

    uint16_t i = 0;
    while (*(i_str + i) != '\0')
    {
        // is this character numeric?
        if (*(i_str + i) > 47 && *(i_str + i) < 59)
        {
            // is this the first numeric character we've found?
            if (!found_number)
            {
                // check previous character for sign
                if (i > 0 && *(i_str + i - 1) == '-')
                {
                    sign = -1;
                }
            }
            found_number = true;

            result = (result * 10 + (*(i_str + i) - 48));
        }
        // once a number is found, we stop scanning if we reach a non-numeric character
        else if (found_number)
        {
            break;
        }
        ++i;
    }

    return result * sign;
}

void TestAtoI()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const char* num1 = "123456789";
    printf("String:%s  Integer:%d\n", num1, AtoI(num1));

    const char* num2 = "asd124asd56";
    printf("String:%s  Integer:%d\n", num2, AtoI(num2));

    const char* num3 = "-asd123";
    printf("String:%s  Integer:%d\n", num3, AtoI(num3));

    const char* num4 = "a-123d6";
    printf("String:%s  Integer:%d\n", num4, AtoI(num4));

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

char* ItoA(int i_number)
{
    if (i_number == 0)
    {
        char* result = (char*)malloc(2);
        *(result) = '0';
        *(result + 1) = '\0';
        return result;
    }

    // count the number of digits
    uint8_t num_digits = 0;
    int num = i_number;
    while (num != 0)
    {
        ++num_digits;
        num /= 10;
    }

    bool is_negative = i_number < 0;

    // reserve memory for the result
    char* result = (char*)malloc(num_digits + (is_negative ? 1 : 0) + 1);

    // add the numbers one digit at a time
    num = i_number * (is_negative ? -1 : 1);
    uint16_t temp_num_digits = num_digits;

    while (num != 0)
    {
        *(result + temp_num_digits - (is_negative ? 0 : 1)) = 48 + num % 10;
        num /= 10;
        --temp_num_digits;
    }

    // add the sign if needed
    *(result) = is_negative ? '-' : *(result);

    // add null-termination
    *(result + num_digits + (is_negative ? 1 : 0)) = '\0';

    return result;
}

void TestItoA()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    int num1 = 345;
    char* str1 = ItoA(num1);
    printf("Number:%d  String:%s\n", num1, str1);
    free(str1);

    int num2 = -12345;
    char* str2 = ItoA(num2);
    printf("Number:%d  String:%s\n", num2, str2);
    free(str2);

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

