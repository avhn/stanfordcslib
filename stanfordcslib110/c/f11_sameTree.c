int sameTree(struct node *a, struct node *b) {
  if (a == 0 && b == 0) return 1;
  else if (a == 0 && b != 0 || a != 0 && b == 0) return 0;
  else if (a->data != b->data) return 0;
  else return (sameTree(a->left, b->left) && sameTree(a->right, b->right));
}
