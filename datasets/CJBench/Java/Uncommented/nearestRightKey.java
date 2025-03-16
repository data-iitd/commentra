
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
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
                root = current; 
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
    public static int nearestRightKey(NRKTree root, int x0) {
        if (root == null) {
            return 0;
        } else {
            if (root.data > x0) {
                int temp = nearestRightKey(root.left, x0);
                if (temp == 0) {
                    return root.data;
                }
                return temp;
            } else {
                return nearestRightKey(root.right, x0);
            }
        }
    }
}
class NRKTree {
    public NRKTree left;
    public NRKTree right;
    public int data;
    NRKTree(int x) {
        this.left = null;
        this.right = null;
        this.data = x;
    }
}
