// library includes
#include <stdio.h>
#include <stdint.h>

// windows only libraries
//#include <conio.h>
//#include <crtdbg.h>

// Linked list problems
void TestReverseLinkedList();
void TestIsCircularLinkedList();

// Binary search tree problems
void TestGetMaxDepthOfBinaryTree();

// String problems
void TestReverseWords();
void TestStringCompare();
void TestReverseString();
void TestRemoveCharFromString();
void TestRemoveAdjacentDuplicatesFromString();
void TestSplitSentenceIntoWords();

// Number problems
void TestMoveZerosToEnd();

/*
    TODO:
    - Delete all the nodes in a linked list given a pointer to a function that returns true if the link data should be removed.
    - Hard: You are given a linked list where the link nodes contain not only a next pointer but an additional pointer to another random node in the list. Write a function that creates a deep copy of this list.
    - Find the maximum depth of a binary tree.
    - Implement the CRT itoa(): const char * itoa( int i_int );
*/

int main()
{
    printf("InterviewQuestionsTest\n");

    // TestReverseLinkedList();
    // printf("\n\n");

    // TestIsCircularLinkedList();
    // printf("\n\n");

    // TestReverseWords();
    // printf("\n\n");

    // TestStringCompare();
    // printf("\n\n");

    // TestReverseString();
    // printf("\n\n");

    // TestRemoveCharFromString();
    // printf("\n\n");

    // TestRemoveAdjacentDuplicatesFromString();
    // printf("\n\n");

    // TestSplitSentenceIntoWords();
    // printf("\n\n");

    // TestMoveZerosToEnd();
    // printf("\n\n");

    TestGetMaxDepthOfBinaryTree();
    printf("\n\n");

//  Windows only code
//     _getch();

// #if defined(_DEBUG)
//     _CrtDumpMemoryLeaks();
// #endif // _DEBUG

    return 0;
}