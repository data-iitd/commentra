
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<List<Integer>> orig = new ArrayList<>();
        for (List<Integer> perm : new Permutations(n)) {
            orig.add(perm);
        }
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }
        int[] q = new int[n];
        for (int i = 0; i < n; i++) {
            q[i] = sc.nextInt();
        }
        int pn = orig.indexOf(Arrays.asList(p));
        int qn = orig.indexOf(Arrays.asList(q));
        System.out.println(Math.abs(pn - qn));
    }
}

class Permutations {
    private int n;
    private List<List<Integer>> perms;

    public Permutations(int n) {
        this.n = n;
        this.perms = new ArrayList<>();
        for (List<Integer> perm : new ArrayList<List<Integer>>(new Permutations(n - 1))) {
            for (int i = 0; i <= n; i++) {
                List<Integer> newPerm = new ArrayList<>(perm);
                newPerm.add(i, n);
                perms.add(newPerm);
            }
        }
    }

    public List<List<Integer>> getPerms() {
        return perms;
    }
}

