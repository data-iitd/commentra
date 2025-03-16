
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
public class UnionFind {
    private final int[] p; 
    private final int[] r; 
    public UnionFind(int n) {
        p = new int[n];
        r = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    public int find(int i) {
        int parent = p[i];
        if (i == parent) {
            return i;
        }
        final int result = find(parent);
        p[i] = result;
        return result;
    }
    public void union(int x, int y) {
        int r0 = find(x);
        int r1 = find(y);
        if (r1 == r0) {
            return;
        }
        if (r[r0] > r[r1]) {
            p[r1] = r0;
        } else if (r[r1] > r[r0]) {
            p[r0] = r1;
        } else {
            p[r1] = r0;
            r[r0]++;
        }
    }
    public int count() {
        List<Integer> parents = new ArrayList<>();
        for (int i = 0; i < p.length; i++) {
            int root = find(i);
            if (!parents.contains(root)) {
                parents.add(root);
            }
        }
        return parents.size();
    }
    @Override
    public String toString() {
        return "p " + Arrays.toString(p) + " r " + Arrays.toString(r) + "\n";
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        UnionFind uf = new UnionFind(n);
        int unionOps = scanner.nextInt();
        for (int i = 0; i < unionOps; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            uf.union(x, y);
        }
        int findOps = scanner.nextInt();
        for (int i = 0; i < findOps; i++) {
            int x = scanner.nextInt();
            System.out.println("Find(" + x + ") -> Root: " + uf.find(x));
        }
        System.out.println("Number of disjoint sets: " + uf.count());
        scanner.close();
    }
}
