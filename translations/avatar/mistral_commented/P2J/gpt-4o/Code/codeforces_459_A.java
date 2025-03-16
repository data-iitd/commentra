import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Get user input and split it into an array of strings
        String given = scanner.nextLine();
        String[] parts = given.split(" ");
        
        // Convert the string array to an array of integers
        int[] l1 = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            l1[i] = Integer.parseInt(parts[i]);
        }
        
        // Assign the first two elements of the array to x1, y1 and the last two elements to x2, y2
        int x1 = l1[0], y1 = l1[1];
        int x2 = l1[2], y2 = l1[3];
        
        // Calculate the denominator and numerator of the slope
        int denominator = x2 - x1;
        int numerator = y2 - y1;
        
        // Check if the denominator is zero
        if (denominator == 0) {
            // Calculate the distance between the two points and print the result
            int d = (int) Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            int x4 = x1, x3 = x2, y3 = y2 + d, y4 = y1 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        } else {
            // If the denominator is not zero, calculate the quotient
            double quotient = (double) numerator / denominator;

            // Check if the quotient is equal to 1 or -1
            if (quotient == 1 || quotient == -1) {
                // Swap the x and y coordinates of the two points and print the result
                int x4, x3, y3, y4;
                if (quotient == 1) {
                    x4 = x2; x3 = x1; y3 = y1; y4 = y2;
                } else {
                    x4 = x1; x3 = x2; y3 = y2; y4 = y1;
                }
                System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
            } else {
                // If the quotient is not 1 or -1, print -1
                System.out.println("-1");
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
