import java.util.Scanner;

public class Main {
    // Function to find the smallest divisor of a number
    public static int div(int n) {
        if (n % 2 == 0) return 2;  // Check if the number is even and return 2
        int s = (int) Math.sqrt(n);
        for (int i = 3; i <= s; i += 2) {  // Check for divisors starting from 3 up to the square root
            if (n % i == 0) return i;  // Return the first divisor found
        }
        return n;  // If no divisor is found, return the number itself
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();  // Read an integer from the user
        System.out.print(num + ":");

        while (num != 1) {
            int divisor = div(num);  // Find the smallest divisor
            System.out.print(" " + divisor);  // Print the smallest divisor
            num = num / divisor;  // Divide the number by its smallest divisor
        }
        System.out.println();
        scanner.close();
    }
}

// <END-OF-CODE>
