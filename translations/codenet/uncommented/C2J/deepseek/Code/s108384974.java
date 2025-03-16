public class Main {
    static class Node {
        int key;
        Node p;
        Node l;
        Node r;
    }

    static Node r, NIL;

    static Node find(Node x, int k) {
        while (x != NIL && k != x.key) {
            if (k < x.key) {
                x = x.l;
            } else {
                x = x.r;
            }
        }
        return x;
    }

    static void insert(int k) {
        Node y = NIL;
        Node x = r;

        Node z = new Node();
        z.key = k;
        z.l = NIL;
        z.r = NIL;

        while (x != NIL) {
            y = x;
            if (z.key < x.key) {
                x = x.l;
            } else {
                x = x.r;
            }
        }
        z.p = y;

        if (y == NIL) {
            r = z;
        } else if (z.key < y.key) {
            y.l = z;
        } else {
            y.r = z;
        }
    }

    static void inorder(Node u) {
        if (u == NIL) {
            return;
        }
        inorder(u.l);
        System.out.print(" " + u.key);
        inorder(u.r);
    }

    static void preorder(Node u) {
        if (u == NIL) {
            return;
        }
        System.out.print(" " + u.key);
        preorder(u.l);
        preorder(u.r);
    }

    static void print() {
        inorder(r);
        System.out.println("");
        preorder(r);
        System.out.println("");
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            if (s.equals("f")) {
                int x = scanner.nextInt();
                Node t = find(r, x);
                if (t == NIL) System.out.println("no");
                else System.out.println("yes");

            } else if (s.equals("i")) {
                int z = scanner.nextInt();
                insert(z);
            } else {
                print();
            }
        }
    }
}
