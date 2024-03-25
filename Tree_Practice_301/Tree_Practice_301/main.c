#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;
struct node
{
	Node* left;
	Node* right;
	int value;
};

Node* tree_insert(Node* root, int value);
void reference_tree_insert(Node** pRoot, int value);

void in_order_traversal(Node* root);
void pre_order_traversal(Node* root);
void post_order_traversal(Node* root);

void destroy_tree(Node* root);

int tree_depth(Node* root);

int main(int argc, char* argv[])
{ 
	Node* root = NULL;
	// 27 22 42 14 53 9 72 87 37 25
	/*
	root = tree_insert(root, 27);
	root = tree_insert(root, 22);
	root = tree_insert(root, 42);
	root = tree_insert(root, 14);
	root = tree_insert(root, 53);
	root = tree_insert(root, 9);
	root = tree_insert(root, 72);
	root = tree_insert(root, 87);
	root = tree_insert(root, 37);
	root = tree_insert(root, 25);
	*/

	reference_tree_insert(&root, 27);
	reference_tree_insert(&root, 22);
	reference_tree_insert(&root, 42);
	reference_tree_insert(&root, 14);
	reference_tree_insert(&root, 53);
	reference_tree_insert(&root, 9);
	reference_tree_insert(&root, 72);
	reference_tree_insert(&root, 87);
	reference_tree_insert(&root, 37);
	reference_tree_insert(&root, 25);

	printf("%d\n", root->right->left->value);
	//TREE Insert Function

	printf("The depth of the tree is %d", tree_depth(root));

	return 0;
}

Node* tree_insert(Node* root, int value)
{
	Node* temp;
	if (root == NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("Failed to allocate for Root\n");
			exit(1);
		}
		temp->value = value;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else if(value < root->value)
	{
		root->left = tree_insert(root->left, value);
	}
	else if (value > root->value)
	{
		root->right = tree_insert(root->right, value);
	}
	else
	{
		;//same as the root?
	}
	return root;
}

void reference_tree_insert(Node** pRoot, int value)
{
	if (*pRoot == NULL)
	{
		*pRoot = (Node*) malloc(sizeof(Node));
		if (*pRoot == NULL)
		{
			printf("Failed to allocate for Root\n");
			exit(1);
		}
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
		(*pRoot)->value = value;
	}
	else if (value < (*pRoot)->value)
	{
		reference_tree_insert( &((*pRoot)->left), value);
	}
	else if (value > (*pRoot)->value)
	{
		reference_tree_insert(&((*pRoot)->right), value);
	}
	else
	{
		;//Ignore Dupes
	}
}

void in_order_traversal(Node* root)
{
	//LSR - Recursively

	if (root != NULL)
	{
		in_order_traversal(root->left);
		printf("%d\n", root->value);
		in_order_traversal(root->right);
	}
}
void pre_order_traversal(Node* root)
{
	//SLR - Recursively
	if (root != NULL)
	{
		printf("%d\n", root->value);
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}
void post_order_traversal(Node* root)
{
	//LRS - Recursively
	if (root != NULL)
	{
		post_order_traversal(root->left);
		post_order_traversal(root->right);
		printf("%d\n", root->value);
	}
}
// EXAM QUESTION - Copy a tree

void destroy_tree(Node* root)
{
	//LRS Destroy
	if (root != NULL)
	{
		destroy_tree(root->left);
		destroy_tree(root->right);
		free(root);
	}
}

int tree_depth(Node* root)
{
	if (root != NULL)
	{
		int depth_of_left_subtree = tree_depth(root->left);
		int depth_of_right_subtree = tree_depth(root->right);

		return 1 + ((depth_of_left_subtree > depth_of_right_subtree) ? depth_of_left_subtree : depth_of_right_subtree);
	}
	else
	{
		return 0;
	}
}

// Immediate Predecessor - Most likely Leaf node
// Each node in the binary tree can hold any data type, including vectors and structures.

// Measure the "Badness" of a tree
// Balance Factor = Depth of the Right Subtree - Depth of the Left Subtree
// Depth = How many steps to get to the bottom
// Right rotation = Right child becomes root