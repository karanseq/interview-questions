// library includes
#include <assert.h>
#include <math.h>
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

//double AtoF(const char* i_str)
//{
//    assert(i_str);
//
//    double result = 0, fraction = 0;
//    bool found_number = false, is_negative = false;
//    uint8_t i = 0;
//
//    while (*(i_str + i) != '\0')
//    {
//        if (*(i_str + i) > 47 && *(i_str + i) < 58)
//        {
//            if (!found_number)
//            {
//                is_negative = (i > 0 && *(i_str + i - 1) == '-');
//            }
//            found_number = true;
//
//            result = result * 10 + (*(i_str + i) - 48);
//            fraction *= 10;
//        }
//        else if (*(i_str + i) == '.')
//        {
//            fraction = 1;
//        }
//        else if (found_number)
//        {
//            break;
//        }
//
//        ++i;
//    }
//
//    result = result / (fraction > 0 ? fraction : 1);
//    result *= (is_negative ? -1 : 1);
//
//    return result;
//}

double AtoF(const char* i_str)
{
    assert(i_str);

    double result = 0, fraction = 0, exponent = 0;
    bool found_digit = false, found_exponent = false, is_result_negative = false, is_exponent_negative = false;

    uint8_t i = 0;
    while (*(i_str + i) != '\0')
    {
        if (*(i_str + i) > 47 && *(i_str + i) < 58)
        {
            if (!found_exponent)
            {
                if (!found_digit)
                {
                    is_result_negative = i > 0 && *(i_str + i - 1) == '-';
                }
                found_digit = true;

                result = result * 10 + *(i_str + i) - 48;
                fraction *= 10;
            }
            else
            {
                exponent = exponent * 10 + *(i_str + i) - 48;
            }
        }
        else if (*(i_str + i) == '.' && fraction == 0)
        {
            fraction = 1;
        }
        else if (*(i_str + i) == 'e' || *(i_str + i) == 'E')
        {
            found_exponent = true;
            is_exponent_negative = *(i_str + i + 1) == '-';
            i += is_exponent_negative ? 1 : 0;
        }
        else if (found_digit)
        {
            break;
        }

        ++i;
    } // end of while

    result = result / (fraction > 0 ? fraction : 1) * (is_result_negative ? -1 : 1) * pow(10.0, (is_exponent_negative ? -1 : 1) * exponent);

    return result;
}

void TestAtoF()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const char* num1 = "1234.56789";
    printf("String:%s  Float:%f\n", num1, float(AtoF(num1)));

    const char* num2 = "asd12..4asd56";
    printf("String:%s  Float:%f\n", num2, float(AtoF(num2)));

    const char* num3 = "-asd123";
    printf("String:%s  Float:%f\n", num3, float(AtoF(num3)));

    const char* num4 = "a-1.23d6";
    printf("String:%s  Float:%f\n", num4, float(AtoF(num4)));

    const char* num5 = "-1.236";
    printf("String:%s  Float:%f\n", num5, float(AtoF(num5)));

    const char* num6 = ".236";
    printf("String:%s  Float:%f\n", num6, float(AtoF(num6)));

    const char* num7 = " -2309.12E-15";
    printf("String:%s  Float:%e\n", num7, float(AtoF(num7)));

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

