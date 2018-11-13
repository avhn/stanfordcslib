void doubleTree(struct node *root) {
  if (root == 0) return;
  doubleTree(root->left), doubleTree(root->right);

  struct node *new = newNode(root->data);
  new->left = root->left, root->left = new;
}
