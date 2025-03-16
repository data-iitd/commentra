
import java.util.*;

public class codeforces_404_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
        }
        int flag = 0;
        List<String> d1 = new ArrayList<>();  // Primary diagonal
        List<String> d2 = new ArrayList<>();  // Secondary diagonal
        Set<String> rem = new HashSet<>();  // Non-diagonal elements

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If it's a primary diagonal element
                if (i == j) {
                    d1.add(s[i].substring(j, j + 1));
                }
                // If it's a secondary diagonal element
                if (i == n - j - 1) {
                    d2.add(s[i].substring(j, j + 1));
                }
                // If it's a non-diagonal element
                if (i!= j && i!= n - j - 1) {
                    rem.add(s[i].substring(j, j + 1));
                }
            }
        }

        // Check conditions to determine the output
        // If the number of unique non-diagonal elements is not 1
        if (rem.size()!= 1) {
            System.out.println("NO");
        }
        // If the primary and secondary diagonals are not equal
        else if (!d1.equals(d2)) {
            System.out.println("NO");
        }
        // If the primary diagonal does not consist of the same element
        else if (d1.size()!= 1) {
            System.out.println("NO");
        }
        // If the unique element in the primary diagonal is also in the non-diagonal set
        else if (d1.get(0).equals(rem.iterator().next())) {
            System.out.println("NO");
        }
        // If all conditions are satisfied, print 'YES'
        else {
            System.out.println("YES");
        }
    }
}
