import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] s = new String[n];
        
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextLine();
        }
        
        int flag = 0;
        StringBuilder d1 = new StringBuilder();
        StringBuilder d2 = new StringBuilder();
        Set<Character> rem = new HashSet<>();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d1.append(s[i].charAt(j));
                }
                if (i == n - j - 1) {
                    d2.append(s[i].charAt(j));
                }
                if (i != j && i != n - j - 1) {
                    rem.add(s[i].charAt(j));
                }
            }
        }
        
        if (rem.size() != 1) {
            System.out.println("NO");
        } else if (!d1.toString().equals(d2.toString())) {
            System.out.println("NO");
        } else if (new HashSet<>(Set.of(d1.toString().toCharArray())).size() != 1) {
            System.out.println("NO");
        } else if (new HashSet<>(Set.of(d1.toString().toCharArray())).equals(rem)) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
