#include <stdlib.h>
#include <assert.h> // function assertions

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* newNode(int data) {
  struct node *node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL, node->right = NULL;
}

struct node* insert(struct node *node, int data) {
  if (node == NULL) return newNode(data);
  else {
    if (data > node->data) node->right = insert(node->right, data);
    else node->left = insert(node->left, data);
    return node;
  }
}
