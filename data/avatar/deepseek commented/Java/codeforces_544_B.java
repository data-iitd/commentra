import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Creating a Scanner object to read input
        int n = scan.nextInt(); // Reading the first integer input (size of the grid)
        int count = scan.nextInt(); // Reading the second integer input (number of 'L' characters)
        printIsland(n, count); // Calling the printIsland method with the inputs
    }

    // Method to print the island pattern based on the given size and count of 'L' characters
    public static void printIsland(int n, int count) {
        int a = (n + 1) / 2; // Calculating the number of 'L' characters in the first diagonal
        int b = n / 2; // Calculating the number of 'L' characters in the second diagonal
        int max = a * a + b * b; // Calculating the maximum possible number of 'L' characters

        // Checking if the requested count exceeds the maximum possible 'L' characters
        if (count > max) {
            System.out.println("NO"); // Printing "NO" if count is too high
            return; // Returning from the method as further execution is unnecessary
        }

        System.out.println("YES"); // Printing "YES" as the count is within the allowed range

        // Building the island grid
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder(); // Creating a StringBuilder to build the row
            for (int j = 0; j < n; j++) {
                if ((i + j) % 2 == 0 && count > 0) { // Checking if the position should be 'L'
                    sb.append('L'); // Appending 'L' to the StringBuilder
                    count--; // Decrementing the count of 'L' characters
                } else {
                    sb.append('S'); // Appending 'S' to the StringBuilder
                }
            }
            System.out.println(sb.toString()); // Printing the constructed row
        }
    }
}
