

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

class BinaryTree {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
}

/* The following class implements a vertical order traversal
in a tree from top to bottom and left to right, so for a tree :
           1
          / \
         2   3
        / \   \
       4   5   6
        \     / \
         7   8   10
          \
           9
 the sequence will be :
 4 2 7 1 5 9 3 8 6 10
 */
public class VerticalOrderTraversal {
    /*Function that receives a root Node and prints the tree
        in Vertical Order.*/
    public static ArrayList<Integer> verticalTraversal(BinaryTree.Node root) {
        if (root == null) {
            return new ArrayList<>();
        }

        /*Queue to store the Nodes.*/
        Queue<BinaryTree.Node> queue = new LinkedList<>();
        /*Queue to store the index of particular vertical
                 column of a tree , with root at 0, Nodes on left
                 with negative index and Nodes on right with positive
                 index. */
        Queue<Integer> index = new LinkedList<>();
        /*Map of Integer and ArrayList to store all the
                 elements in a particular index in a single arrayList
                 that will have a key equal to the index itself. */
        Map<Integer, ArrayList<Integer>> map = new HashMap<>();

        /* min and max stores leftmost and right most index to
                 later print the tree in vertical fashion.*/
        int max = 0, min = 0;
        queue.offer(root);
        index.offer(0);

        while (!queue.isEmpty()) {
            BinaryTree.Node node = queue.poll();
            int idx = index.poll();

            map.putIfAbsent(idx, new ArrayList<>());
            map.get(idx).add(node.data);

            max = Math.max(max, idx);
            min = Math.min(min, idx);

            if (node.left != null) {
                /*Adding the left Node if it is not null
                                and its index by subtracting 1 from it's
                                parent's index*/
                queue.offer(node.left);
                index.offer(idx - 1);
            }
            if (node.right != null) {
                /*Adding the right Node if it is not null
                                and its index by adding 1 from it's
                                parent's index*/
                queue.offer(node.right);
                index.offer(idx + 1);
            }
        }

        /*Finally map data is printed here which has keys
                from min to max. Each ArrayList represents a
                vertical column that is added in ans ArrayList.*/
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = min; i <= max; i++) {
            result.addAll(map.get(i));
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        BinaryTree.Node[] nodes = new BinaryTree.Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new BinaryTree.Node(i);
        }

        for (int i = 0; i < n - 1; i++) {
            int parent = scanner.nextInt();
            int child = scanner.nextInt();
            String direction = scanner.next();

            if (direction.equals("L")) {
                nodes[parent].left = nodes[child];
            } else if (direction.equals("R")) {
                nodes[parent].right = nodes[child];
            }
        }

        ArrayList<Integer> result = verticalTraversal(nodes[1]);

        for (int value : result) {
            System.out.print(value + " ");
        }

        scanner.close();
    }
}
