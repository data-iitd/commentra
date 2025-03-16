import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input from the user
        System.out.println((n * 2 + 1) / 3);  // Perform a calculation and print the result

        System.out.println(factorial(n));  // Calculate the factorial of the input number and print the result
    }

    public static int factorial(int n) {
        if (n == 0) {  // Base case: factorial of 0 is 1
            return 1;
        } else {
            return n * factorial(n - 1);  // Recursive case: n * factorial of (n - 1)
        }
    }
}

