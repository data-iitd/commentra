import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();

        // Compute the maximum value among a+b, a-b, and a*b
        long result = Math.max(a + b, Math.max(a - b, a * b));
        System.out.println(result); // Print the maximum value
    }
}
