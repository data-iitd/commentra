
import java.util.*;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;

// Class for a tree node
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

// A class to represent a queue item. The queue is used to do Level
// order traversal. Every Queue item contains node and horizontal
// distance of node from root
class QItem {
    TreeNode node;
    int hd;

    QItem(TreeNode n, int h) {
        node = n;
        hd = h;
    }
}

// Class for a Binary Tree
class Tree {
    TreeNode root;

    Tree(TreeNode n) {
        root = n;
    }

    // This method prints nodes in top view of binary tree
    public void printTopView() {
        // base case
        if (root == null) {
            return;
        }

        // Creates an empty hashset
        HashSet<Integer> set = new HashSet<>();

        // Create a queue and add root to it
        Queue<QItem> queue = new LinkedList<>();
        queue.add(new QItem(root, 0));

        // Standard BFS or level order traversal loop
        while (!queue.isEmpty()) {
            // Remove the front item and get its details
            QItem qi = queue.poll();
            int hd = qi.hd;
            TreeNode n = qi.node;

            // If this is the first node at its horizontal distance,
            // then this node is in top view
            if (!set.contains(hd)) {
                set.add(hd);
                System.out.print(n.key + " ");
            }

            // Enqueue left and right children of current node
            if (n.left != null) {
                queue.add(new QItem(n.left, hd - 1));
            }
            if (n.right != null) {
                queue.add(new QItem(n.right, hd + 1));
            }
        }
    }
}

// Driver class to test above methods
public class PrintTopViewofTree {

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
