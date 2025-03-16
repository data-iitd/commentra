

import java.util.Scanner;

public class codeforces_669_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input from the user
        System.out.println((n * 2 + 1) / 3);  // Perform a calculation and print the result
    }
}

public class codeforces_669_A{
    public static int factorial(int n) {
        if (n == 0) {  // Base case: factorial of 0 is 1
            return 1;
        } else {
            return n * factorial(n - 1);  // Recursive case: n * factorial of (n - 1)
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();  // Take an integer input from the user
        int result = factorial(number);  // Calculate the factorial of the input number
        System.out.println(result);  // Print the result
    }
}

public class codeforces_669_A{
    public static int fibonacci(int n) {
        if (n <= 0) {  // Return 0 for non-positive input
            return 0;
        } else if (n == 1) {  // Return 1 for input of 1
            return 1;
        } else {
            int a = 0, b = 1;  // Initialize the first two Fibonacci numbers
            for (int i = 2; i <= n; i++) {  // Loop from 2 to n
                int temp = a;
                a = b;
                b = temp + b;  // Update the values of a and b
            }
            return b;  // Return the nth Fibonacci number
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int index = scanner.nextInt();  // Take an integer input from the user
        int result = fibonacci(index);  // Print the nth Fibonacci number
        System.out.println(result);
    }
}

