import java.util.Scanner;

public class Main {
    static final int INITIAL_BUF_SIZE = 10000;
    static final int MAX_BUF_SIZE = 100000000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers N and K from standard input
        int N = readInt(scanner);
        int K = readInt(scanner);

        // Convert N to base K and print the length of the resulting string
        String s = tenToN(N, K);
        System.out.println(s.length());
    }

    // TenToN converts a decimal number to a base N string
    static String tenToN(int number, int n) {
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

    // readInt reads an integer from the standard input
    static int readInt(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }

    // i2s converts an integer to a string
    static String i2s(int i) {
        return Integer.toString(i);
    }
}

// <END-OF-CODE>
