

import java.util.Scanner;  // Importing the Scanner class from the java.util package

public class codeforces_334_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to read input from the user
        int n = scanner.nextInt();  // Taking an integer input from the user
        int i = 1, j = n * n;  // Initializing variables i and j

        // Starting a while loop that continues as long as i is less than j
        while (i < j) {
            System.out.println(i + " " + j);  // Printing the current values of i and j
            i++;  // Incrementing i by 1
            j--;  // Decrementing j by 1
        }

        scanner.close();  // Closing the Scanner object to release system resources
    }
}

