import java.util.Scanner;

public class Main {
    // comp takes two integers x and a as input and returns an integer.
    // It returns 0 if x is less than a, otherwise it returns 10.
    public static int comp(int x, int a) {
        if (x < a) { // Check if x is less than a
            return 0;
        }
        return 10; // Return 10 if x is not less than a
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt(); // Read first integer
        int a = scanner.nextInt(); // Read second integer

        System.out.println(comp(x, a)); // Call the comp function with x and a, and print the result
        scanner.close();
    }
}

// <END-OF-CODE>
