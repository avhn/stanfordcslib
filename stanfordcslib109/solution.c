#include <stdlib.h>
#include <stdio.h>


typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;


void printList(node* head) {
	node* walker = head;
	do {
		printf("%d ", walker->data);
		walker = walker->right;
	} while(walker != head);
	printf("\n");
}


node* newNode(int data) {
	node* item = (node *)malloc(sizeof(node));
	item->left = NULL;
	item->right = NULL;
	item->data = data;

	return item;
}


void join(node* left, node* right) {
	left->right = right;
	right->left = left;
}


node* makeList(node* head) {
	// make circular linked list
	// with one node

	head->left = head;
	head->right = head;
	return head;
}


node* add(node* aHead, node* bHead) {
	// add 2 circular linked lists

	if (aHead == NULL) return bHead;
	if (bHead == NULL) return aHead;

	node* aTail = aHead->left;
	node* bTail = bHead->left;
	join(aTail, bHead), join(bTail, aHead);

	return aHead;
}


node* treeToList(node* root) {
	if (root == NULL) return NULL;

	node* left = treeToList(root->left);
	node* right = treeToList(root->right);

	if (left == NULL && right == NULL) {
		return makeList(root);
	} else {
		left = add(left, makeList(root));
		return add(left, right);
	}
}


int main() {

}
