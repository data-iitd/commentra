import java.util.Scanner;

public class Main {
    static final long INF = (long) 1e20;
    static final int MOD = (int) 1e9 + 7;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading four integers from standard input.
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long c = scanner.nextLong();
        long d = scanner.nextLong();
        
        // Calculating and printing the maximum of four possible products of two of the given numbers.
        System.out.println(Math.max(Math.max(a * c, b * d), Math.max(a * d, b * c)));
        
        scanner.close();
    }
}
// <END-OF-CODE>
