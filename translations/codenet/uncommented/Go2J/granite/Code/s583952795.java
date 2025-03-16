
import java.util.*;

public class s583952795{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String s = tenToN(N, K);
        System.out.println(s.length());
    }

    public static String tenToN(int number, int n) {
        StringBuilder sb = new StringBuilder();
        while (number > 0) {
            sb.append(number % n);
            number /= n;
        }
        return sb.reverse().toString();
    }
}

// 