void mirror(struct node *root) {
  if (root == 0) return;

  mirror(root->left), mirror(root->right);

  struct node *temp = root->right;
  root->right = root->left, root->left = temp;
}
