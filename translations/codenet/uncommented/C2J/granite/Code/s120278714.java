
import java.util.Scanner;

public class s120278714{
    static final int MAX = 25;
    static Node[] N = new Node[MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        init(n);
        for (int i = 0; i < n; i++) {
            int id = scanner.nextInt();
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            N[id].l = l;
            N[id].r = r;
            if (l!= -1) {
                N[l].par = id;
            }
            if (r!= -1) {
                N[r].par = id;
            }
        }
        int p = -1;
        for (int i = 0; i < n; i++) {
            if (N[i].par == -1) {
                p = i;
                break;
            }
        }
        System.out.println("Preorder");
        preorder(p);
        System.out.println();
        System.out.println("Inorder");
        inorder(p);
        System.out.println();
        System.out.println("Postorder");
        postorder(p);
        System.out.println();
    }

    static void init(int n) {
        for (int i = 0; i < n; i++) {
            N[i] = new Node();
            N[i].par = N[i].l = N[i].r = -1;
        }
    }

    static void preorder(int p) {
        if (p!= -1) {
            System.out.print(" " + p);
            preorder(N[p].l);
            preorder(N[p].r);
        }
    }

    static void inorder(int p) {
        if (p!= -1) {
            inorder(N[p].l);
            System.out.print(" " + p);
            inorder(N[p].r);
        }
    }

    static void postorder(int p) {
        if (p!= -1) {
            postorder(N[p].l);
            postorder(N[p].r);
            System.out.print(" " + p);
        }
    }

    static class Node {
        int par, l, r;
    }
}
