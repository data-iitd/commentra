import java.util.*;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;

// Represents a node in a binary tree
class TreeNode {
    int key;
    TreeNode left;
    TreeNode right;
    TreeNode(int key) {
        this.key = key;
        left = null;
        right = null;
    }
}

// Used to store node and its horizontal distance
class QItem {
    TreeNode node;
    int hd;
    QItem(TreeNode n, int h) {
        node = n;
        hd = h;
    }
}

// Represents a binary tree
class Tree {
    TreeNode root;
    Tree(TreeNode n) {
        root = n;
    }

    // Prints the top view of the binary tree
    public void printTopView() {
        if (root == null) {
            return;
        }
        HashSet<Integer> set = new HashSet<>();
        Queue<QItem> queue = new LinkedList<>();
        queue.add(new QItem(root, 0));
        while (!queue.isEmpty()) {
            QItem qi = queue.poll();
            int hd = qi.hd;
            TreeNode n = qi.node;
            if (!set.contains(hd)) {
                set.add(hd);
                System.out.print(n.key + " ");
            }
            if (n.left != null) {
                queue.add(new QItem(n.left, hd - 1));
            }
            if (n.right != null) {
                queue.add(new QItem(n.right, hd + 1));
            }
        }
    }
}

// Main class to run the program
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Integer, TreeNode> nodeMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int key = scanner.nextInt();
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            nodeMap.putIfAbsent(key, new TreeNode(key));
            TreeNode currentNode = nodeMap.get(key);
            if (left != -1) {
                nodeMap.putIfAbsent(left, new TreeNode(left));
                currentNode.left = nodeMap.get(left);
            }
            if (right != -1) {
                nodeMap.putIfAbsent(right, new TreeNode(right));
                currentNode.right = nodeMap.get(right);
            }
        }
        int rootKey = scanner.nextInt();
        Tree t = new Tree(nodeMap.get(rootKey));
        System.out.println("Top view of the binary tree:");
        t.printTopView();
        scanner.close();
    }
}
