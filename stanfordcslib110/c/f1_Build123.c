/*
// 1st
struct node* Build123() {
  struct node *two = newNode(2), *one = newNode(1), *three = newNode(3);
  two->left = one, two->right = three;
}

// 2th
struct node* Build123() {
  struct node *two = newNode(2);
  two->left = newNode(1), two->right = newNode(3);
}
*/

// 3th
struct node* Build123() {
  struct node *root;
  root = insert(root, 2), insert(root, 1), insert(root, 3);
  return root;
}
