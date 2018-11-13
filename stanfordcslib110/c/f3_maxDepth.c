int maxDepth(struct node *root)  {
  if (root == NULL) return 0;
  else {
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    if (left >= right) return 1 + left;
    else return 1 + right;
  }
}
