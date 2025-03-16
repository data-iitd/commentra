
import java.util.*;

public class s672953945{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int L = sc.nextInt();
        String[] s = new String[N];
        for (int i = 0; i < N; i++) {
            s[i] = sc.next();
        }
        Arrays.sort(s);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(s[i]);
        }
        System.out.println(sb.toString());
    }
}

