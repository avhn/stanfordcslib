void printPostorder(struct node *root) {
  if (root == NULL) return;
  else {
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
  }
}
