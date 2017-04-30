// library includes
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

struct Node
{
    Node* next;
    int val;
} typedef Node;

Node* CreateLinkedList(int* i_array, int num_nodes)
{
    assert(i_array);

    Node* head = new Node;
    head->next = nullptr;
    head->val = *(i_array + num_nodes - 1);

    for (int i = num_nodes - 2; i > -1; --i)
    {
        Node* new_head = new Node;
        new_head->next = head;
        new_head->val = *(i_array + i);
        head = new_head;
    }

    return head;
}

void DestroyLinkedList(Node* i_head)
{
    assert(i_head);

    while (i_head)
    {
        Node* curr = i_head;
        i_head = i_head->next;
        delete curr;
    }
}

void PrintLinkedList(Node* head)
{
    Node* curr = head;
    while (curr != nullptr)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

void PrintLinkedList(Node* head, const size_t num_nodes)
{
    Node* curr = head;
    for (uint32_t i = 0; curr && i < num_nodes; ++i)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

/*
Reverse a linked list in place.
*/
Node* ReverseLinkedList(Node* head)
{
    if (!head)
    {
        return head;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void TestReverseLinkedList()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    // create linked list
    Node* head = new Node;
    head->next = nullptr;
    head->val = 0;

    const size_t num_nodes = 4;
    for (uint8_t i = 0; i < num_nodes; ++i)
    {
        Node* node = new Node;
        node->next = head;
        node->val = i + 1;
        head = node;
    }

    // print newly created linked list
    printf("Linked list before reverse: ");
    PrintLinkedList(head);
    printf("\n");

    // reverse linked list
    head = ReverseLinkedList(head);

    // print reversed linked list
    printf("Linked list after reverse: ");
    PrintLinkedList(head);
    printf("\n");

    while (head)
    {
        Node* next = head->next;
        delete head;
        head = next;
    }
    head = nullptr;

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
Detect if a linked list is circular.
*/
bool IsCircularLinkedList(Node* head)
{
    if (!head)
    {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    do
    {
        if (!fast->next)                        return false;

        if (!fast->next->next)                  return false;
        fast = (fast->next)->next;

        if (!slow->next)                        return false;
        slow = slow->next;

        if (slow == fast)                       return true;

    } while (true);

    return false;
}

void TestIsCircularLinkedList()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    Node* head = new Node;
    head->next = nullptr;
    head->val = 0;
    Node* first = head;

    const size_t num_nodes = 4;
    for (uint8_t i = 0; i < num_nodes; ++i)
    {
        Node* node = new Node;
        node->next = head;
        node->val = i + 1;
        head = node;
    }
    first->next = head;

    // print newly created linked list
    printf("Linked list: ");
    PrintLinkedList(head, 1 + num_nodes * 2);
    printf("\n");

    bool is_circular = IsCircularLinkedList(head);
    printf("%s circular!\n", is_circular ? "Is" : "Is not");

    for (uint8_t i = 0; i < num_nodes + 1; ++i)
    {
        Node* next = head->next;
        delete head;
        head = next;
    }
    head = first = nullptr;

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

/*
You're given the pointer to the head nodes of two sorted linked lists. 
The data in both lists will be sorted in ascending order. 
Change the next pointers to obtain a single, merged linked list which also has data in ascending order. 
Either head pointer given may be null meaning that the corresponding list is empty.
*/
Node* MergeLists(Node *headA, Node* headB)
{
    Node *prevA = nullptr, *currA = headA, *prevB = nullptr, *currB = headB, *headM = nullptr;

    if (headA && headB)
    {
        if (headA->val < headB->val)
        {
            headM = headA;
            prevA = headA;
            currA = headA->next;
        }
        else
        {
            headM = headB;
            prevB = headB;
            currB = headB->next;
        }
    }
    else if (headA)
    {
        headM = headA;
        prevA = headA;
        currA = headA->next;
    }
    else if (headB)
    {
        headM = headB;
        prevB = headB;
        currB = headB->next;
    }
    else
    {
        return nullptr;
    }

    while (1)
    {
        if (currA && currB)
        {
            if (currA->val < currB->val)
            {
                if (prevB)
                {
                    if (!prevA || prevB->val > prevA->val)
                    {
                        prevB->next = currA;
                    }
                }

                if (currA->next && currA->next->val > currB->val)
                {
                    Node* currA_next = currA->next;
                    currA->next = currB;

                    prevA = currA;
                    currA = currA_next;

                    prevB = currB;
                    currB = currB->next;
                }
                else
                {
                    prevA = currA;
                    currA = currA->next;
                }
            }
            else
            {
                if (prevA)
                {
                    if (!prevB || prevA->val > prevB->val)
                    {
                        prevA->next = currB;
                    }
                }

                if (currB->next && currB->next->val > currA->val)
                {
                    Node* currB_next = currB->next;
                    currB->next = currA;

                    prevB = currB;
                    currB = currB_next;
                
                    prevA = currA;
                    currA = currA->next;
                }
                else
                {
                    prevB = currB;
                    currB = currB->next;
                }
            }
        }
        else if (currA && prevB)
        {
            if (currA->val < prevB->val)
            {
                if (prevA)
                {
                    prevA->next = currA;
                }
                Node* currA_next = currA->next;
                currA->next = prevB;
                
                prevA = currA;
                currA = currA_next;

                prevB = currB;
            }
            else
            {
                prevB->next = currA;
                
                prevA = currA;
                currA = currA->next;
            }
        }
        else if (currB && prevA)
        {
            if (currB->val < prevA->val)
            {
                if (prevB)
                {
                    prevB->next = currB;
                }
                Node* currB_next = currB->next;
                currB->next = prevA;

                prevB = currB;
                currB = currB_next;

                prevA = currA;
            }
            else
            {
                prevA->next = currB;

                prevB = currB;
                currB = currB->next;
            }
        }
        else
        {
            break;
        }
    }

    return headM;
}

void TestMergeLists()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    {
        int data_1[4] = { 1, 3, 5, 6 };
        Node* head_1 = CreateLinkedList(data_1, 4);

        int data_2[3] = { 2, 4, 7 };
        Node* head_2 = CreateLinkedList(data_2, 3);

        PrintLinkedList(head_1);
        printf("\n");
        PrintLinkedList(head_2);
        printf("\n");

        Node* head_merged = MergeLists(head_1, head_2);
        PrintLinkedList(head_merged);
        printf("\n");

        DestroyLinkedList(head_merged);
        printf("\n");
    }

    {
        int data_1[4] = { 2, 5, 7, 8 };
        Node* head_1 = CreateLinkedList(data_1, 4);

        int data_2[4] = { 1, 3, 4, 9 };
        Node* head_2 = CreateLinkedList(data_2, 4);

        PrintLinkedList(head_1);
        printf("\n");
        PrintLinkedList(head_2);
        printf("\n");

        Node* head_merged = MergeLists(head_1, head_2);
        PrintLinkedList(head_merged);
        printf("\n");

        DestroyLinkedList(head_merged);
        printf("\n");
    }

    {
        int data_1[1] = { 15 };
        Node* head_1 = CreateLinkedList(data_1, 1);

        int data_2[1] = { 12 };
        Node* head_2 = CreateLinkedList(data_2, 1);

        Node* head_merged = MergeLists(head_1, head_2);
        PrintLinkedList(head_merged);
        printf("\n");

        DestroyLinkedList(head_merged);
        printf("\n");
    }

    {
        int data_1[5] = { 25, 125, 222, 234, 567 };
        Node* head_1 = CreateLinkedList(data_1, 5);

        int data_2[1] = { 456 };
        Node* head_2 = CreateLinkedList(data_2, 1);

        Node* head_merged = MergeLists(head_1, head_2);
        PrintLinkedList(head_merged);
        printf("\n");

        DestroyLinkedList(head_merged);
        printf("\n");
    }

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

