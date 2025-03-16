import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Scanner;

// Define the MainNode class
// This class represents a node in the Huffman tree. It contains:
// - data: an integer representing the frequency of the character.
// - c: a character.
// - left and right: references to the left and right children of the node.
class MainNode {
    int data;
    char c;
    MainNode left;
    MainNode right;
}

// Define the MyComparator class
// This class implements the Comparator interface to compare MainNode objects based on their data field.
class MyComparator implements Comparator<MainNode> {
    @Override
    public int compare(MainNode x, MainNode y) {
        return x.data - y.data;
    }
}

// Define the Main class
// This class contains the main method for the Huffman coding program.
public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Implement the printCode method
    // This method takes a root node and a String representing the code, and recursively prints the Huffman codes for each character.
    public static void printCode(MainNode root, String s) {
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + ": " + s);
            return;
        }
        printCode(root.left, s + "0");
        printCode(root.right, s + "1");
    }

    // Implement the main method
    // This method reads the input, creates a priority queue of MainNode objects, constructs the Huffman tree, and finally prints the Huffman codes.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); 
        char[] charArray = new char[n];
        int[] charfreq = new int[n];
        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split(" ");
            charArray[i] = input[0].charAt(0);
            charfreq[i] = Integer.parseInt(input[1]);
        }
        PriorityQueue<MainNode> q = new PriorityQueue<>(n, new MyComparator());
        for (int i = 0; i < n; i++) {
            MainNode hn = new MainNode();
            hn.c = charArray[i];
            hn.data = charfreq[i];
            hn.left = null;
            hn.right = null;
            q.add(hn);
        }
        MainNode root = null;
        while (q.size() > 1) {
            MainNode x = q.poll();
            MainNode y = q.poll();
            MainNode f = new MainNode();
            f.data = x.data + y.data;
            f.c = '-';
            f.left = x;
            f.right = y;
            root = f;
            q.add(f);
        }
        printCode(root, "");
        sc.close();
    }
}
