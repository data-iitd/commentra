public class TreeTraversal {
    static class Node {
        int l, r, par;
    }

    static Node[] N = new Node[25];

    public static void main(String[] args) {
        int n, i, id, l, r;
        int p;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        init(n);

        for (i = 0; i < n; i++) {
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

        for (i = 0; i < n; i++) {
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
    }

    public static void init(int n) {
        for (int i = 0; i < n; i++) {
            N[i] = new Node();
            N[i].par = N[i].l = N[i].r = -1;
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
}
