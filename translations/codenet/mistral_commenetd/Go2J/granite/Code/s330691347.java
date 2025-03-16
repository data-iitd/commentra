
import java.util.Arrays;
import java.util.Scanner;

public class s330691347{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        String[] s = new String[N];
        for (int i = 0; i < N; i++) {
            s[i] = scanner.next();
        }
        System.out.println(N + " " + L + " " + Arrays.toString(s));
        Arrays.sort(s);
        StringBuilder ans = new StringBuilder();
        for (String str : s) {
            ans.append(str);
        }
        System.out.println(ans.toString());
    }
}

