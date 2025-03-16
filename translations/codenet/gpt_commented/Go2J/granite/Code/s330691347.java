
import java.util.*;

class s330691347 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int L = sc.nextInt();
        String[] s = new String[N];
        for (int i = 0; i < N; i++) {
            s[i] = sc.next();
        }
        Arrays.sort(s);
        String ans = "";
        for (int i = 0; i < N; i++) {
            ans += s[i];
        }
        System.out.println(ans);
    }
}
