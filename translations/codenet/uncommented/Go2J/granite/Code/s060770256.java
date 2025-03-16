
import java.util.Scanner;

public class s060770256{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        System.out.println(solution(n, m));
    }

    public static int solution(int n, int m) {
        n = n - 2;
        m = m - 2;
        if (n < 0) {
            n = 1;
        }
        if (m < 0) {
            m = 1;
        }
        return n * m;
    }
}

Translate the above Java code to JavaScript and end with comment "