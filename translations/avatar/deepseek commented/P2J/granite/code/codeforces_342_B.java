

import java.util.Scanner;  // Import the Scanner class for input

public class codeforces_342_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        int n = scanner.nextInt();  // Read the value of n
        int m = scanner.nextInt();  // Read the value of m
        int s = scanner.nextInt();  // Read the value of s
        int f = scanner.nextInt();  // Read the value of f

        int d = s < f? 1 : -1;  // Determine the direction based on the starting and finishing points
        char c = s < f? 'R' : 'L';  // Determine the character based on the direction

        StringBuilder res = new StringBuilder();  // Initialize a StringBuilder object to store the result
        int i = 1;  // Initialize step counter
        int j = s;  // Initialize current position
        int t = scanner.nextInt();  // Read the value of t
        int l = scanner.nextInt();  // Read the value of l
        int r = scanner.nextInt();  // Read the value of r
        int k = 1;  // Initialize the current time step

        while (j!= f) {  // Loop until the current position reaches the finishing point
            if (i > t && k < m) {  // Check if it's time to update the time step and there are more steps
                t = scanner.nextInt();  // Read new value for t
                l = scanner.nextInt();  // Read new value for l
                r = scanner.nextInt();  // Read new value for r
                k++;  // Increment the time step counter
            }

            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {  // Check if it's the specified time step and the position is within the allowed range
                res.append('X');  // Append 'X' to the result string
            } else {
                res.append(c);  // Append the direction character to the result string
                j += d;  // Update the current position
            }
            i++;  // Increment the step counter
        }

        System.out.println(res.toString());  // Print the result string
    }
}

