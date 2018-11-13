int size(struct node* root) {
  if (root == NULL) return 0;
  else return size(root->left) + 1 + size(root->right);
}
