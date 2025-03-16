import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
        }
        Arrays.sort(s);
        int c = -1, a = 0;
        for (int i = 0; i < n; i++) {
            if (s[i].equals(s[n - 1])) {
                if (i > c) {
                    a = i;
                    c = i;
                }
            }
        }
        System.out.println(a);
    }
}
