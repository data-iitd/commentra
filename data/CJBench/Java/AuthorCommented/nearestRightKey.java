
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * This program builds a binary tree from user input and finds the nearest key
 * on the right side of a given input key (x0) in the binary tree.
 */
public class nearestRightKey {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Map<Integer, NRKTree> nodeMap = new HashMap<>();
        NRKTree root = null;

        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();
            int left = sc.nextInt();
            int right = sc.nextInt();

            nodeMap.putIfAbsent(value, new NRKTree(value));
            NRKTree current = nodeMap.get(value);

            if (root == null) {
                root = current; // Assign the first node as the root
            }

            if (left != -1) {
                nodeMap.putIfAbsent(left, new NRKTree(left));
                current.left = nodeMap.get(left);
            }
            if (right != -1) {
                nodeMap.putIfAbsent(right, new NRKTree(right));
                current.right = nodeMap.get(right);
            }
        }

        int inputX0 = sc.nextInt();

        int toPrint = nearestRightKey(root, inputX0);
        if (toPrint == 0) {
            System.out.println("No nearest right key found.");
        } else {
            System.out.println("Nearest Right Key: " + toPrint);
        }

        sc.close();
    }

    /*
     * Finds the nearest key on the right side of a given key (x0) in the binary tree.
     *
     * @param root The root node of the binary tree.
     * @param x0   The input key to find the nearest right key.
     * @return The nearest right key if found, otherwise 0.
     */
    public static int nearestRightKey(NRKTree root, int x0) {
        // Check whether tree is empty
        if (root == null) {
            return 0;
        } else {
            if (root.data > x0) {
                // Go left
                int temp = nearestRightKey(root.left, x0);
                if (temp == 0) {
                    return root.data;
                }
                return temp;
            } else {
                // Go right
                return nearestRightKey(root.right, x0);
            }
        }
    }
}

/**
 * Class representing a node in the binary tree.
 */
class NRKTree {
    public NRKTree left;
    public NRKTree right;
    public int data;

    /**
     * Constructor to initialize a tree node with a value.
     *
     * @param x The value of the node.
     */
    NRKTree(int x) {
        this.left = null;
        this.right = null;
        this.data = x;
    }
}
