import java.util.Scanner;

class Node {
    int l, r, par;

    Node() {
        this.par = this.l = this.r = -1;
    }
}

public class BinaryTree {
    static final int MAX = 25;
    static Node[] N = new Node[MAX];

    public static void init(int n) {
        for (int i = 0; i < n; i++) {
            N[i] = new Node();
        }
    }

    public static void Preorder(int p) {
        if (p != -1) {
            System.out.print(" " + p);
            Preorder(N[p].l);
            Preorder(N[p].r);
        }
    }

    public static void Inorder(int p) {
        if (p != -1) {
            Inorder(N[p].l);
            System.out.print(" " + p);
            Inorder(N[p].r);
        }
    }

    public static void Postorder(int p) {
        if (p != -1) {
            Postorder(N[p].l);
            Postorder(N[p].r);
            System.out.print(" " + p);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, id, l, r, p = -1;

        n = scanner.nextInt();
        init(n);

        for (int i = 0; i < n; i++) {
            id = scanner.nextInt();
            l = scanner.nextInt();
            r = scanner.nextInt();

            if (l != -1) {
                N[id].l = l;
                N[l].par = id;
            }
            if (r != -1) {
                N[id].r = r;
                N[r].par = id;
            }
        }

        for (int i = 0; i < n; i++) {
            if (N[i].par == -1) {
                p = i;
                break;
            }
        }

        System.out.println("Preorder");
        Preorder(p);
        System.out.println();

        System.out.println("Inorder");
        Inorder(p);
        System.out.println();

        System.out.println("Postorder");
        Postorder(p);
        System.out.println();

        scanner.close();
    }
}

// <END-OF-CODE>
