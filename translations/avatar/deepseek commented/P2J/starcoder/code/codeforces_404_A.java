
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[][] s = new String[n][n];
        for (int i = 0; i < n; i++) {
            String[] k = sc.next().split(" ");
            for (int j = 0; j < n; j++) {
                s[i][j] = k[j];
            }
        }
        boolean flag = false;
        List<String> d1 = new ArrayList<>();
        List<String> d2 = new ArrayList<>();
        Set<String> rem = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d1.add(s[i][j]);
                }
                if (i == n - j - 1) {
                    d2.add(s[i][j]);
                }
                if (i!= j && i!= n - j - 1) {
                    rem.add(s[i][j]);
                }
            }
        }
        if (rem.size()!= 1) {
            System.out.println("NO");
        } else if (!d1.equals(d2)) {
            System.out.println("NO");
        } else if (new HashSet<>(d1).size()!= 1) {
            System.out.println("NO");
        } else if (d1.equals(rem)) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}

