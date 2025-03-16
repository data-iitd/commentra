import java.util.Scanner;

public class Main {
    // Function to find the product of two numbers after subtracting 2 from each
    public static int solution(int n, int m) {
        // Set n and m to be the input numbers after subtracting 2 from each
        n = n - 2;
        m = m - 2;

        // Check if n is less than 0, if so set it to 1
        if (n < 0) {
            n = 1;
        }

        // Check if m is less than 0, if so set it to 1
        if (m < 0) {
            m = 1;
        }

        // Multiply n and m and return the result
        return n * m;
    }

    // Main function to read input and call solution function
    public static void main(String[] args) {
        // Initialize two variables n and m to read input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Call solution function with n and m as arguments and print the result
        System.out.println(solution(n, m));
        scanner.close();
    }
}

// <END-OF-CODE>
