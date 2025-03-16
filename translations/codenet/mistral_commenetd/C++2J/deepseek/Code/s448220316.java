import java.util.Scanner;

public class Main {
    // Function to read an integer from standard input
    static int read() {
        Scanner scanner = new Scanner(System.in);
        int k = 0, f = 1;
        char ch = scanner.next().charAt(0);
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = scanner.next().charAt(0);
        }
        while (ch >= '0' && ch <= '9') {
            k = k * 10 + ch - '0';
            ch = scanner.next().charAt(0);
        }
        return k * f;
    }

    // Function to write an integer to standard output
    static void write(int x) {
        if (x < 0) {
            x = -x;
            System.out.print("-");
        }
        if (x > 9) write(x / 10);
        System.out.print(x % 10);
    }

    // Function to write an integer and a newline to standard output
    static void writeln(int x) {
        write(x);
        System.out.println();
    }

    // Initialize variables
    static int n, m, l, r, vi, fa[], v[];

    // Function to get the root of a tree
    static int get(int x) {
        if (fa[x] == x) return x;
        int f = get(fa[x]);
        v[x] += v[fa[x]];
        fa[x] = f;
        return f;
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of vertices 'n' and edges 'm'
        n = scanner.nextInt();
        m = scanner.nextInt();
        // Initialize the trees for each vertex
        fa = new int[n + 1];
        v = new int[2 * n + 1];
        for (int i = 1; i <= n; i++) fa[i] = i;
        // Process each edge
        for (int i = 0; i < m; i++) {
            // Read the left and right endpoints and the value 'vi' of the edge
            l = scanner.nextInt();
            r = scanner.nextInt();
            vi = scanner.nextInt();
            // Find the roots of the trees of the left and right endpoints
            int li = get(l), ri = get(r);
            // If the roots are different, update the depth of the right tree and its father
            if (li != ri) {
                v[ri] += vi - v[r] + v[l];
                fa[ri] = li;
            } else {
                // If the roots are the same, check if the value of the edge is correct
                if (v[r] - v[l] != vi) {
                    System.out.println("No");
                    return;
                }
            }
        }
        // Output 'Yes' if all edges have the correct value
        System.out.println("Yes");
    }
}
