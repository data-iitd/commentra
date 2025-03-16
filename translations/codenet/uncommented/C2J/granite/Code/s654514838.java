
import java.io.*;
import java.util.*;

class s654514838 {
    static class Node {
        int key;
        int priority;
        Node right, left;

        Node(int key, int priority) {
            this.key = key;
            this.priority = priority;
            right = left = null;
        }
    }

    static Node root;

    static Node rightRotate(Node t) {
        Node s = t.left;
        t.left = s.right;
        s.right = t;
        return s;
    }

    static Node leftRotate(Node t) {
        Node s = t.right;
        t.right = s.left;
        s.left = t;
        return s;
    }

    static Node insert(Node t, int key, int priority) {
        if (t == null) return new Node(key, priority);
        if (key == t.key) return t;

        if (key < t.key) {
            t.left = insert(t.left, key, priority);
            if (t.priority < t.left.priority) t = rightRotate(t);
        } else {
            t.right = insert(t.right, key, priority);
            if (t.priority < t.right.priority) t = leftRotate(t);
        }

        return t;
    }

    static Node _delete(Node t, int key) {
        if (t == null) return null;
        if (key < t.key) t.left = _delete(t.left, key);
        else if (key > t.key) t.right = _delete(t.right, key);
        else {
            if (t.left == null && t.right == null) return null;
            else if (t.left == null) t = leftRotate(t);
            else if (t.right == null) t = rightRotate(t);
            else {
                if (t.left.priority > t.right.priority)
                    t = rightRotate(t);
                else t = leftRotate(t);
            }
            return _delete(t, key);
        }
        return t;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().split(" ");
            String order = s[0];
            if (order.equals("insert")) {
                int key = Integer.parseInt(s[1]);
                int priority = Integer.parseInt(s[2]);
                root = insert(root, key, priority);
            } else if (order.equals("delete")) {
                int key = Integer.parseInt(s[1]);
                root = _delete(root, key);
            } else if (order.equals("find")) {
                int key = Integer.parseInt(s[1]);
                boolean find = false;
                Node now = root;
                while (now!= null) {
                    if (now.key == key) {
                        find = true;
                        break;
                    } else if (now.key > key) now = now.left;
                    else now = now.right;
                }
                System.out.println(find? "yes" : "no");
            } else {
                inorder(root);
                System.out.println();
                preorder(root);
                System.out.println();
            }
        }
    }

    static void inorder(Node node) {
        if (node!= null) {
            inorder(node.left);
            System.out.print(" " + node.key);
            inorder(node.right);
        }
    }

    static void preorder(Node node) {
        if (node!= null) {
            System.out.print(" " + node.key);
            preorder(node.left);
            preorder(node.right);
        }
    }
}

