// library includes
#include <stdio.h>
#include <stdint.h>

struct Node
{
    Node* next;
    int val;
} typedef Node;

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
        if (!fast->next)						return false;

        if (!fast->next->next)					return false;
        fast = (fast->next)->next;

        if (!slow->next)						return false;
        slow = slow->next;

        if (slow == fast)						return true;

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
