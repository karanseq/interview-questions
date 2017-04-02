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

/*
Find the maximum depth of a binary tree.
*/
void GetMaxDepthOfBinaryTree(Node* i_node, const uint16_t i_depth, uint16_t& o_max_depth)
{
    if (!i_node)
    {
        o_max_depth = i_depth > o_max_depth ? i_depth : o_max_depth;
        return;
    }

    GetMaxDepthOfBinaryTree(i_node->left, i_depth + 1, o_max_depth);
    GetMaxDepthOfBinaryTree(i_node->right, i_depth + 1, o_max_depth);
}

void TestGetMaxDepthOfBinaryTree()
{
    printf("-------------------- %s started --------------------\n", __FUNCTION__);

    const uint16_t num_values = 9;
    int values[num_values] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    Node* root = Insert(nullptr, values[0]);
	
	for (uint16_t i = 1; i < num_values; ++i)
	{
		Insert(root, values[i]);
	}

    printf("In-order:");
    VisitInOrder(root);
    printf("\n");
    
    printf("Pre-order:");
    VisitPreOrder(root);
    printf("\n");
    
    printf("Post-order:");
    VisitPostOrder(root);
    printf("\n");

    uint16_t max_depth = 0;
    GetMaxDepthOfBinaryTree(root, max_depth, max_depth);

    printf("Maximum depth of tree shown above:%d\n", max_depth);

    Delete(root);
    root = nullptr;

    printf("-------------------- %s ended --------------------\n", __FUNCTION__);
}
