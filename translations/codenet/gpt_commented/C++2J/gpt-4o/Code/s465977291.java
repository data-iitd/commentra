import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of items (n) and the distance (d)
        int n, d;

        // Create a Scanner object to read input values for n and d from the user
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        d = scanner.nextInt();

        // Calculate the effective range of coverage, which is (d*2 + 1)
        double a = d * 2 + 1;

        // Calculate and output the minimum number of groups needed to cover 'n' items
        // This is done by dividing 'n' by the coverage 'a' and rounding up to the nearest whole number
        System.out.println((int) Math.ceil(n / a));

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
