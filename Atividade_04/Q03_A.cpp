#include <iostream>

using namespace std;
struct Node {
	int data;
	int rcount;
	int lcount;
	struct Node* left;
	struct Node* right;
};
bool isPBT(int count)
{
	count = count + 1;
	while (count % 2 == 0)
		count = count / 2;
	
	if (count == 1)
		return true;
	else
		return false;
}
struct Node* newNode(int data)
{
	struct Node* temp =
	(struct Node*)malloc(
		sizeof(struct Node)
	);
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	temp->rcount = 0;
	temp->lcount = 0;
}
struct Node* insert(struct Node* root,
					int data)
{
	if (root == NULL) {
		struct Node* n = newNode(data);
		return n;
	}
	if (root->rcount == root->lcount) {
		root->left = insert(root->left, data);
		root->lcount += 1;
	}
	else if (root->rcount < root->lcount) {
		if (isPBT(root->lcount)) {
			root->right = insert(root->right, data);
			root->rcount += 1;
		}
		else {
			root->left = insert(root->left, data);
			root->lcount += 1;
		}
	}
	return root;
}
void inorder(struct Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
int main()
{
	int arr[] = { 8, 6, 7, 12, 5, 1, 9 };
	int size = sizeof(arr) / sizeof(int);
	struct Node* root = NULL;
	for (int i = 0; i < size; i++)
		root = insert(root, arr[i]);
	inorder(root);
	return 0;
}
