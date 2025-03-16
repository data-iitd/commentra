import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        // These integers represent the total number of items n and the number of groups m

        int q = n / m; // Calculate the quotient, which is the number of items each group will have
        int r = n % m; // Calculate the remainder, which is the number of items that will be left over

        int[] a = new int[m]; // Initialize an array a of length m
        // This represents the initial distribution of items among the groups

        for (int i = 0; i < m; i++) { // Loop to initialize the array a with q
            a[i] = q;
        }

        for (int i = 0; i < r; i++) { // Loop for the number of remaining items r
            a[i]++; // Increment the corresponding element in the array a by 1
            // Ensuring that the remaining items are distributed evenly
        }

        for (int i = 0; i < m; i++) { // Loop to print the elements of the array a
            System.out.print(a[i] + " "); // Print each element separated by a space
        }
        System.out.println(); // Print a newline at the end
    }
}
