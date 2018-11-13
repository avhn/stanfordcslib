/*
int isBSTrecur(struct node *node, int min, int max) {
  if (node == 0) return 1;
  else if (min < node->data && max >= node->data) {
    return isBSTrecur(node->left, min, node->data) && isBSTrecur(node->right, node->data, max);
  }
  else return 0;
}
*/
int isBSTrecur(struct node *node, int min, int max) {
  if (node == 0) return 1;
  else if (min > node->data || node->data > max) return 0; 
  else return isBSTrecur(node->left, min, node->data) && isBSTrecur(node->right, node->data + 1, max);  // +1 for root !>= max
}

int isBST2(struct node *root) {
  return isBSTrecur(root, minValue(root), maxValue(root));
}
