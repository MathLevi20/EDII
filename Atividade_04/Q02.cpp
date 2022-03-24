﻿
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	bool isThreaded;
};

Node *createThreaded(Node *root)
{

	if (root == NULL)
		return NULL;
	if (root->left == NULL &&
		root->right == NULL)
		return root;
	if (root->left != NULL)
	{
		Node* l = createThreaded(root->left);
		l->right = root;
		l->isThreaded = true;
	}
	if (root->right == NULL)
		return root;
	return createThreaded(root->right);
}
Node *leftMost(Node *root)
{
	while (root != NULL && root->left != NULL)
		root = root->left;
	return root;
}
void inOrder(Node *root)
{
	if (root == NULL) return;
	Node *cur = leftMost(root);
	while (cur != NULL)
	{
		cout << cur->data << " ";
		if (cur->isThreaded)
			cur = cur->right;
			cur = leftMost(cur->right);
	}

}
void preorder(struct Node *root) {
   if (root != NULL) {
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
   }
}
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = key;
	return temp;
}
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	createThreaded(root);

	cout << "threaded tree is\n";
	inOrder(root);
	preorder(root);
	return 0;
}
