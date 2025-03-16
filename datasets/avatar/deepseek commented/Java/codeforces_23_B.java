
Here are the comments for each logical block in the code:

import java.util.Scanner; // Importing the Scanner class for input operations

public class Main { // Defining the Main class
    public static void main(String[] args) { // The main method, the entry point of the program
        Scanner scan = new Scanner(System.in); // Creating a Scanner object to read input
        int t = scan.nextInt(); // Reading the number of test cases
        for (int i = 0; i < t; i++) { // Looping through each test case
            int n = scan.nextInt(); // Reading the value of n for each test case
            System.out.println(maxLeft(n)); // Calling the maxLeft method and printing the result
        }
    }

    public static int maxLeft(int n) { // Defining the maxLeft method
        return n > 2 ? n - 2 : 0; // Returning n - 2 if n is greater than 2, otherwise returning 0
    }
}
