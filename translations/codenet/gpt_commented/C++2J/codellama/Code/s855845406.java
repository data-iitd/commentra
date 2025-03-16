import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input values
        int N, A;

        // Read an integer value for N from standard input
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();

        // Read an integer value for A from standard input
        A = scanner.nextInt();

        // Calculate the result by squaring N and subtracting A, then output the result
        System.out.println(N * N - A);
    }
}

