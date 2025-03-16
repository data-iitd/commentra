import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Scanner;
class HuffmanNode {
    int data;
    char c;
    HuffmanNode left;
    HuffmanNode right;
}
class MyComparator implements Comparator<HuffmanNode> {
    @Override
    public int compare(HuffmanNode x, HuffmanNode y) {
        return x.data - y.data;
    }
}
public final class Huffman {
    private Huffman() {
    }
    public static void printCode(HuffmanNode root, String s) {
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + ": " + s);
            return;
        }
        printCode(root.left, s + "0");
        printCode(root.right, s + "1");
    }
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
        PriorityQueue<HuffmanNode> q = new PriorityQueue<>(n, new MyComparator());
        for (int i = 0; i < n; i++) {
            HuffmanNode hn = new HuffmanNode();
            hn.c = charArray[i];
            hn.data = charfreq[i];
            hn.left = null;
            hn.right = null;
            q.add(hn);
        }
        HuffmanNode root = null;
        while (q.size() > 1) {
            HuffmanNode x = q.poll();
            HuffmanNode y = q.poll();
            HuffmanNode f = new HuffmanNode();
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
