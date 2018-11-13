void printTill(int *path, int len) {
  for( int i = 0; i < len; i++) {
    printf("%d ", path[i]);
  }
  puts("");
}

void recurPath(struct node* root, int *path, int currLen) {
  if (root == NULL) return; // Guard

  path[currLen] = root->data, currLen++;

  if(root->left == NULL && root->right == NULL) {
    printTill(path, currLen);
  }
  else {
    recurPath(root->left, path, currLen);
    recurPath(root->right, path, currLen);
  }

}

#define maxNode 1000
void printPaths(struct node *root) {
  int initializer[maxNode];
  recurPath(root, initializer, 0);
}
