import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask user for the number of elements in the list
        int n = scanner.nextInt();
        int[] number = new int[n];

        // Get the list of numbers from user input
        for (int i = 0; i < n; i++) {
            number[i] = scanner.nextInt();
        }

        // Initialize variables h1 and h2 to 0
        int h1 = 0;
        int h2 = 0;
        boolean valid = true;

        // Iterate through the list of numbers
        for (int i = 0; i < n; i++) {
            // Check if the current number is not 4 and not 7
            if (number[i] != 4 && number[i] != 7) {
                // Print "NO" and break the loop if the condition is met
                System.out.println("NO");
                valid = false;
                break;
            }

            // If the index is less than half the length of the list, add the number to h1
            if (i < n / 2) {
                h1 += number[i];
            } 
            // If the index is greater than or equal to half the length of the list, add the number to h2
            else {
                h2 += number[i];
            }
        }

        // Check if the loop was broken due to a non-4 and non-7 number
        if (valid) {
            // If h1 and h2 are equal, print "YES"
            if (h1 == h2) {
                System.out.println("YES");
            } 
            // If h1 and h2 are not equal, print "NO"
            else {
                System.out.println("NO");
            }
        }

        scanner.close();
    }
}
// <END-OF-CODE>
