import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Calculate the value of x using the given formula
        int x = m * 1900 + (n - m) * 100;

        // Print the result
        System.out.println(x * (int)Math.pow(2, m));
    }
}

