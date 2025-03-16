
import java.util.*;

public class s583952795{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String s = TenToN(N, K);
        System.out.println(s.length());
    }

    public static String TenToN(int number, int n) {
        StringBuilder s = new StringBuilder();
        int tmp = number;
        while (tmp >= n) {
            s.append(tmp % n);
            tmp /= n;
        }
        s.append(tmp);
        return s.reverse().toString();
    }
}

// End of code.