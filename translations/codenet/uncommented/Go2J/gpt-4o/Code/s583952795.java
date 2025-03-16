import java.util.Scanner;

public class Main {
    static final int INITIAL_BUF_SIZE = 10000;
    static final int MAX_BUF_SIZE = 100000000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = readInt(scanner);
        int K = readInt(scanner);
        String s = tenToN(N, K);
        System.out.println(s.length());
    }

    public static String tenToN(int number, int n) {
        StringBuilder s = new StringBuilder();
        int tmp = number;
        while (true) {
            s.insert(0, i2s(tmp % n));
            if (tmp < n) {
                break;
            }
            tmp /= n;
        }
        return s.toString();
    }

    public static int readInt(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }

    public static String i2s(int i) {
        return Integer.toString(i);
    }
}

/*==========================================
 *             Library
 *==========================================*/
// Additional utility methods can be added here if needed

// <END-OF-CODE>
