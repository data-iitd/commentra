
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] N = new Node[n];
        for (int i = 0; i < n; i++) {
            N[i] = new Node();
        }
        for (int i = 0; i < n; i++) {
            N[i].id = i;
            N[i].l = N[i].r = -1;
        }
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            int l = sc.nextInt();
            int r = sc.nextInt();
            if (l!= -1) {
                N[id].l = l;
                N[l].par = id;
            }
            if (r!= -1) {
                N[id].r = r;
                N[r].par = id;
            }
        }
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (N[i].par == -1) {
                p = i;
                break;
            }
        }
        System.out.println("Preorder");
        preorder(N, p);
        System.out.println();
        System.out.println("Inorder");
        inorder(N, p);
        System.out.println();
        System.out.println("Postorder");
        postorder(N, p);
        System.out.println();
    }

    public static void preorder(Node[] N, int p) {
        if (p!= -1) {
            System.out.print(" " + p);
            preorder(N, N[p].l);
            preorder(N, N[p].r);
        }
    }

    public static void inorder(Node[] N, int p) {
        if (p!= -1) {
            inorder(N, N[p].l);
            System.out.print(" " + p);
            inorder(N, N[p].r);
        }
    }

    public static void postorder(Node[] N, int p) {
        if (p!= -1) {
            postorder(N, N[p].l);
            postorder(N, N[p].r);
            System.out.print(" " + p);
        }
    }
}

class Node {
    int id, l, r, par;
}

