import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize two integer variables, N and A
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the value of N from the standard input
        int A = scanner.nextInt(); // Read the value of A from the standard input

        // Calculate the result and print it to the standard output
        System.out.println(N * N - A);
        
        scanner.close();
    }
}

// <END-OF-CODE>
