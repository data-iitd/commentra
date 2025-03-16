import java.util.Scanner;

public class SubsetSum {
    public static void main(String[] args) {
        final int N = 2000;
        int num1, math[] = new int[N + 1];

        // Initialize variables
        int a, num2, ans, sum = 0;
        int i, j;

        // Initialize math array with first element as 1
        math[0] = 1;

        // Read the number of integers to be input
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of integers to be input:");
        num1 = scanner.nextInt();

        // Read each integer and calculate its sum
        for (i = 0; i < num1; i++) {
            System.out.println("Enter an integer:");
            a = scanner.nextInt();

            // Add the current integer to the sum
            sum += a;

            // Mark all the previous numbers as visited
            for (j = sum - a; j >= 0; j--) {
                if (math[j] == 1) math[j + a] = 1;
            }
        }

        // Read the number of integers to be checked
        System.out.println("Enter the number of integers to be checked:");
        num2 = scanner.nextInt();

        // Check each integer and print the result
        for (i = 0; i < num2; i++) {
            System.out.println("Enter an integer to check:");
            ans = scanner.nextInt();

            // Check if the current integer is marked as visited
            if (math[ans] == 1) System.out.println("yes");
            else System.out.println("no");
        }

        // Return 0 to indicate successful execution
        scanner.close();
    }
}
