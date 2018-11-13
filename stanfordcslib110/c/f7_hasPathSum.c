/*
// Bug, Stanford solution
int hasPathSum(struct node* node, int sum) {
  // return true if we run out of tree and sum==0
  if (node == NULL) {
    return(sum == 0);
  }
  else {
  // otherwise check both subtrees
    int subSum = sum - node->data;
    return(hasPathSum(node->left, subSum) ||
    hasPathSum(node->right, subSum));
  }
}
*/
// Proper solution
int hasPathSum(struct node *root, int sum) {
  if (root == NULL) return 0; // Check exception, non-end empty pointers

  int newSum = sum - root->data;

  if (root->left == NULL && root->left == NULL) return (newSum == 0); // Check end node case
  else {
    return (hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum) );
  }
}
