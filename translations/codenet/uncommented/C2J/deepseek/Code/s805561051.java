public class Main {
    static class BT {
        int parent;
        int right;
        int left;
    }

    static BT[] bt = new BT[26];
    static int n;

    static void Preorder(int a) {
        if (a == -1) return;

        System.out.print(" " + a);
        Preorder(bt[a].left);
        Preorder(bt[a].right);
    }

    static void Inorder(int a) {
        if (a == -1) return;

        Inorder(bt[a].left);
        System.out.print(" " + a);
        Inorder(bt[a].right);
    }

    static void Postorder(int a) {
        if (a == -1) return;

        Postorder(bt[a].left);
        Postorder(bt[a].right);
        System.out.print(" " + a);
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        for (int i = 0; i < 26; ++i) {
            bt[i] = new BT();
            bt[i].parent = -1;
        }

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            bt[num].left = scanner.nextInt();
            bt[num].right = scanner.nextInt();

            if (bt[num].left != -1 && bt[num].right != -1) {
                bt[bt[num].left].parent = num;
                bt[bt[num].right].parent = num;
            } else if (bt[num].left != -1) {
                bt[bt[num].left].parent = num;
            } else if (bt[num].right != -1) {
                bt[bt[num].right].parent = num;
            }
        }

        int rootIndex = 0;
        for (int i = 0; bt[i].parent != -1; ++i) {
            rootIndex = i;
        }

        System.out.println("Preorder");
        Preorder(rootIndex);
        System.out.println();

        System.out.println("Inorder");
        Inorder(rootIndex);
        System.out.println();

        System.out.println("Postorder");
        Postorder(rootIndex);
        System.out.println();
    }
}
