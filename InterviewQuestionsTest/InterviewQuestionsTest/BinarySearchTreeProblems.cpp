// library includes
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

struct Node
{
    Node* left;
    Node* right;
    int val;
} typedef Node;

Node* Insert(Node* i_root, int i_val)
{
	if (!i_root)
	{
		i_root = new Node();
		i_root->left = nullptr;
		i_root->right = nullptr;
		i_root->val = i_val;
	}
	else if (i_val < i_root->val)
	{
		i_root->left = Insert(i_root->left, i_val);
	}
	else
	{
		i_root->right = Insert(i_root->right, i_val);
	}
	return i_root;
}

void Delete(Node* i_root)
{
	assert(i_root);

	if (i_root->left)
	{
		Delete(i_root->left);
		i_root->left = nullptr;
	}
	if (i_root->right)
	{
		Delete(i_root->right);
		i_root->right = nullptr;
	}

	delete i_root;
}

void GetHeight(size_t& o_height, Node* i_root, size_t i_height = 0)
{
    if (i_root)
    {
        GetHeight(o_height, i_root->left, i_height + 1);
        GetHeight(o_height, i_root->right, i_height + 1);
        o_height = i_height > o_height ? i_height : o_height;
    }
}

void VisitInOrder(Node* i_root)
{
	if (i_root->left)
	{
		VisitInOrder(i_root->left);
	}

	printf("%d ", i_root->val);
	
	if (i_root->right)
	{
		VisitInOrder(i_root->right);
	}
}

void VisitPreOrder(Node* i_root)
{
	printf("%d ", i_root->val);
	
	if (i_root->left)
	{
		VisitPreOrder(i_root->left);
	}
	
	if (i_root->right)
	{
		VisitPreOrder(i_root->right);
	}
}

void VisitPostOrder(Node* i_root)
{
	if (i_root->left)
	{
		VisitPostOrder(i_root->left);
	}

	if (i_root->right)
	{
		VisitPostOrder(i_root->right);
	}

	printf("%d ", i_root->val);
}

void VisitLevel(Node* i_root, size_t i_level)
{
    if (i_root)
    {
        if (i_level == 0)
        {
            printf("%d ", i_root->val);
        }
        else
        {
            VisitLevel(i_root->left, i_level - 1);
            VisitLevel(i_root->right, i_level - 1);
        }
    }
}

void VisitLevelOrder(Node* i_root)
{
    size_t height = 0;
    GetHeight(height, i_root, 0);

    for (size_t i = 0; i <= height; ++i)
    {
        VisitLevel(i_root, i);
    }
}

void TestBinaryTree()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const size_t num_values = 9;
    int values[num_values] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    Node* root = Insert(nullptr, values[0]);

    for (size_t i = 1; i < num_values; ++i)
    {
        Insert(root, values[i]);
    }

    size_t max_depth = 0;
    GetHeight(max_depth, root, max_depth);
    printf("Maximum depth of tree shown above:%zu\n", max_depth);

    printf("In-order:");
    VisitInOrder(root);
    printf("\n");

    printf("Pre-order:");
    VisitPreOrder(root);
    printf("\n");

    printf("Post-order:");
    VisitPostOrder(root);
    printf("\n");

    printf("Level-order:");
    VisitLevelOrder(root);
    printf("\n");

    Delete(root);
    root = nullptr;

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}

