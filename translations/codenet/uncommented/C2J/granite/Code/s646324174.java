
import java.util.Scanner;

public class s646324174{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int top = 0;
        int[] S = new int[10000];

        while (sc.hasNext()) {
            String s = sc.next();
            if (s.equals("+")) {
                int b = S[top--];
                int a = S[top--];
                S[++top] = a + b;
            } else if (s.equals("-")) {
                int b = S[top--];
                int a = S[top--];
                S[++top] = a - b;
            } else if (s.equals("*")) {
                int b = S[top--];
                int a = S[top--];
                S[++top] = a * b;
            } else {
                S[++top] = Integer.parseInt(s);
            }
        }
        System.out.println(S[top]);
    }
}
