class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

class Main {
    public int diameterOfTree(Node root) {
        int[] diameter = new int[1];
        diameter[0] = 0;
        height(root, diameter);

        return diameter[0];
    }

    public int height(Node root, int[] diameter) {
        if (root == null) {
            return 0;
        }
        int[] lh = new int[1];
        int[] rh = new int[1];
        lh[0] = height(root.left, diameter);
        rh[0] = height(root.right, diameter);
        int maxD = lh[0] + rh[0];
        diameter[0] = Math.max(maxD, diameter[0]);

        return 1 + Math.max(lh[0], rh[0]);
    }

    public static void main(String[] args) {

    }
}