// Error prone
int isBST(struct node *root) {
  if (root == 0) return 1;
  else if ( (root->left == 0 || minValue(root) <= root->data) && (root->right == 0 || maxValue(root) > root->data) ) {
    return isBST(root->left) && isBST(root->right);
  }
  else return 0;
}
