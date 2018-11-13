// Loop ver.
int minValue(struct node *root) {
  assert(root);

  struct node *current = root;
  for (; current->left != NULL; current = current->left);
  return current->data;
}

/*
// Recursive ver.
int minValue(struct node *root) {
  assert(root);

  if (root->left == NULL) return root->data;
  else return minValue(root->left);
}
*/

int maxValue(struct node *root) {
  assert(root);

  if (root->right == 0) return root->data;
  else return maxValue(root->right);
}
