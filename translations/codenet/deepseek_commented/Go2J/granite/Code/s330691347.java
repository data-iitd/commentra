
import java.util.Arrays;
import java.util.Scanner;

public class s330691347{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int L = sc.nextInt();
        String[] s = new String[N];
        for (int i = 0; i < N; i++) {
            s[i] = sc.next();
        }
        System.out.println(N + " " + L + " " + Arrays.toString(s));
        Arrays.sort(s);
        System.out.println(Arrays.toString(s));
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(s[i]);
        }
        System.out.println(sb.toString());
    }
}

