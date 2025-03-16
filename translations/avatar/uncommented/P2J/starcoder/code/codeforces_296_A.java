import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] m = new String[n];
        for (int i = 0; i < n; i++) {
            m[i] = sc.next();
        }
        boolean possible = true;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (m[i].equals(m[j])) {
                    count++;
                }
            }
            if (count >= n / 2 + 1) {
                possible = false;
                break;
            }
        }
        System.out.println(possible? "YES" : "NO");
    }
}
