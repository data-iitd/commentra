import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long n = scanner.nextLong();
        long[] a = new long[(int) n];
        long[] count = new long[(int) n];

        for (long i = 1; i < n; i++) {
            a[(int) i] = scanner.nextLong();
        }

        for (long i = 0; i < n; i++) {
            count[(int) i] = 0;
        }

        for (long i = 1; i < n; i++) {
            count[(int) (a[(int) i] - 1)]++;
        }

        for (long i = 0; i < n; i++) {
            System.out.println(count[(int) i]);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
