import java.util.*;

public class BinaryTree {
    Integer maxNode = 1000;
    Node root = null;
    public BinaryTree(){
    }

    public void insert(Integer data) {
        if (root == null) this.root = new Node(data);
        else insert(root, data);
    }

    public Node insert(Node root, Integer data) {
        if (root == null) {
            root = new Node(data);
        } else {
            if (data > root.data) root.right = insert(root.right, data);
            else root.left = insert(root.left, data);
        }
        return root;
    }

    public boolean lookUp(Integer data) {
        return lookUp(root, data);
    }

    public boolean lookUp(Node root, Integer data) {
        if (root == null) return false;
        if (root.data == data) return true;

        if (root.data < data) return lookUp(root.right, data);
        else return lookUp(root.left, data);
    }

    public void build123() {
        root = new Node(2);
        root.right = new Node(3);
        root.left = new Node(1);
    }

    public int size() {
        return size(root);
    }

    public int size(Node root) {
        if (root == null) return 0;
        return (1 + size(root.left) + size(root.right));
    }

    public int maxDepth() {
        return maxDepth(root);
    }

    public int maxDepth(Node root) {
        if (root == null) return 0;

        int left = maxDepth(root.left);
        int right = maxDepth(root.right);

        return (1 + Math.max(left, right));
    }

    public int minValue() {
        return minValue(root);
    }

    public int minValue(Node root) {
        if (root.left == null) return root.data;
        else return minValue(root.left);
    }

    public int maxValue() {
        return maxValue(root);
    }

    public int maxValue(Node root) {
        if (root.right == null) return root.data;
        else return maxValue(root.right);
    }

    public void printTree() {
        printTree(root);
    }

    public void printTree(Node root) {
        if (root == null) return;

        printTree(root.left);
        System.out.print(root.data + " ");
        printTree(root.right);
    }

    public void printPostorder() {
        printPostorder(root);
    }

    public void printPostorder(Node root) {
        if (root == null) return;

        printPostorder(root.left);
        printPostorder(root.right);
        System.out.print(root.data + " ");
    }

    public boolean hasPathSum(Integer sum) {
        return hasPathSum(root, sum);
    }

    public boolean hasPathSum(Node root, Integer sum) {
        if (root == null) return(sum == 0);

        Integer newSum = sum - root.data;
        return ( hasPathSum(root.left, newSum) || hasPathSum(root.right, newSum) );
    }

    public void printTill(ArrayList<Integer> path) {
        for (Integer data : path) {
            System.out.print(data + " ");
        }
        System.out.println();
    }

    public void recurPath(Node root, ArrayList<Integer> path) {
        assert root != null;

        path.add(root.data);
        if ( root.right == null && root.left == null ) {
            printTill(path);
            return;
        } else {
            ArrayList<Integer> leftClone = (ArrayList<Integer>)path.clone();
            ArrayList<Integer> rightClone = (ArrayList<Integer>)path.clone();

            recurPath(root.left, leftClone);
            recurPath(root.right, rightClone);
        }
    }

    public void printPaths() {
        printPaths(root);
    }

    public void printPaths(Node root) {
        ArrayList<Integer> path = new ArrayList<Integer>(maxNode);
        recurPath(root, path);
    }

    public void mirror() {
        mirror(root);
    }

    public void mirror(Node root) {
        if (root == null) return;

        mirror(root.right);
        mirror(root.left);

        Node temp = root.right;
        root.right = root.left;
        root.left = temp;
    }

    public void doubleTree() {
        doubleTree(root);
    }

    public void doubleTree(Node root) {
        if (root == null) return;
        doubleTree(root.left);
        doubleTree(root.right);

        Node left = root.left;
        root.left = new Node(root.data);
        root.left.left = left;
    }

    public boolean sameTree(Node a, Node b) {
        if (a == null && b == null) return true;
        else if (a == null || b == null) return false;
        else {
            return ( a.data == b.data &&
            sameTree(a.right, b.right) && sameTree(a.left, b.left)
            );
        }
    }

    public Integer countTrees(Integer nodeNum) {

        if (nodeNum <= 1) return 1;
        else {
            Integer sum = 0;
            for (Integer r = 1; r <= nodeNum; r++) {
                Integer right = countTrees(r - 1);
                Integer left = countTrees(nodeNum - r);
                sum += right * left;
            }
            return sum;
        }
    }

    public boolean isBST() {
        return isBST(root);
    }

    public boolean isBST(Node root) {
        if (root == null || (root.right == null && root.left == null)) return true;
        if ( (root.right != null && maxValue(root) < root.data) || (root.left != null && minValue(root) > root.data) ) return false;

        return isBST(root.right) && isBST(root.left);
    }

    public boolean isBST2() {
        return isBST2(root, minValue(root), maxValue(root));
    }

    public boolean isBST2(Node root, Integer min, Integer max) {
        if (root == null || (root.right == null && root.left == null)) return true;
        if (min > root.data || max < root.data) return false;
        return ( isBST2(root.left, min, root.data) && isBST2(root.right, root.data + 1, max) );
    }
}