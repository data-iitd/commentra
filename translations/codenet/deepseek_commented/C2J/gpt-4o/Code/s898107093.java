import java.util.Scanner;  // Import Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int n = scanner.nextInt();  // Read the number of rounds
        String[] t = new String[n];  // Declare an array for Tarō's strings
        String[] h = new String[n];  // Declare an array for Hanako's strings
        int taro = 0, hanako = 0;  // Initialize scores

        // Loop through each round
        for (int i = 0; i < n; i++) {
            t[i] = scanner.next();  // Read Tarō's string
            h[i] = scanner.next();  // Read Hanako's string
            if (t[i].compareTo(h[i]) < 0) hanako += 3;  // Compare and update Hanako's score
            if (t[i].compareTo(h[i]) > 0) taro += 3;  // Compare and update Tarō's score
            if (t[i].compareTo(h[i]) == 0) {  // If strings are equal
                taro += 1;  // Increment Tarō's score by 1
                hanako += 1;  // Increment Hanako's score by 1
            }
        }

        System.out.println(taro + " " + hanako);  // Print the final scores
        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
