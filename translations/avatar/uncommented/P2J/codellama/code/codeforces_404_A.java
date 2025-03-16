import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
        }
        int flag = 0;
        String[] d1 = new String[n];
        String[] d2 = new String[n];
        Set<String> rem = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d1[i] = s[i].charAt(j) + "";
                }
                if (i == n - j - 1) {
                    d2[i] = s[i].charAt(j) + "";
                }
                if (i != j && i != n - j - 1) {
                    rem.add(s[i].charAt(j) + "");
                }
            }
        }
        if (rem.size() != 1) {
            System.out.println("NO");
        } else if (!Arrays.equals(d1, d2)) {
            System.out.println("NO");
        } else if (new HashSet<>(Arrays.asList(d1)).size() != 1) {
            System.out.println("NO");
        } else if (new HashSet<>(Arrays.asList(d1)).equals(rem)) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}



Translate the above Java code to C++ and end with comment "