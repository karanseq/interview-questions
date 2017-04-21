// library includes
#include <stdio.h>
#include <stdint.h>

// windows only libraries
#if defined(_WIN64) || defined(_WIN32)
#include <conio.h>
#include <crtdbg.h>
#endif

// Linked list problems
void TestReverseLinkedList();
void TestIsCircularLinkedList();

// Binary search tree problems
void TestGetMaxDepthOfBinaryTree();

// String problems
void TestReverseWords();
void TestStringLength();
void TestStringCompare();
void TestStringNCompare();
void TestStrStr();
void TestReverseString();
void TestRemoveCharFromString();
void TestRemoveAdjacentDuplicatesFromString();
void TestSplitSentenceIntoWords();

// Number problems
void TestMoveZerosToEnd();
void TestAtoI();
void TestItoA();
void TestAtoF();

/*
    TODO:
    - Delete all the nodes in a linked list given a pointer to a function that returns true if the link data should be removed.
    - Hard: You are given a linked list where the link nodes contain not only a next pointer but an additional pointer to another random node in the list. Write a function that creates a deep copy of this list.
*/

int main()
{
    printf("InterviewQuestionsTest\n");

    // TestReverseLinkedList();
    // printf("\n");

    // TestIsCircularLinkedList();
    // printf("\n");

    // TestReverseWords();
    // printf("\n");

    // TestStringLength();
    // printf("\n");

    // TestStringCompare();
    // printf("\n");

    // TestStringNCompare();
    // printf("\n");

    // TestStrStr();
    // printf("\n");

    // TestReverseString();
    // printf("\n");

    // TestRemoveCharFromString();
    // printf("\n");

    // TestRemoveAdjacentDuplicatesFromString();
    // printf("\n");

    // TestSplitSentenceIntoWords();
    // printf("\n");

    TestMoveZerosToEnd();
    printf("\n");

    //TestGetMaxDepthOfBinaryTree();
    //printf("\n");

    //TestAtoI();
    //printf("\n");

    //TestItoA();
    //printf("\n");

    // TestAtoF();
    // printf("\n");

//  Windows only code
#if defined(_WIN64) || defined(_WIN32)
     _getch();
#if defined(_DEBUG)
    _CrtDumpMemoryLeaks();
#endif // _DEBUG
#endif // _WIN64 || _WIN32

    return 0;
}