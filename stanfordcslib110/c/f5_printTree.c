// Ascending order
void printTree(struct node *root) {
  if (root == NULL) return;
  else {
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
  }
}
