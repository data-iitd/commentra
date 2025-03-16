
import java.util.Scanner;  // Import the Scanner class for user input

public class codeforces_459_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read user input
        String given = scanner.nextLine();  // Read the input as a string
        String[] l1 = given.split(" ");  // Split the input string into an array of strings

        int[] coordinates = new int[4];  // Create an array to store the coordinates
        for (int i = 0; i < 4; i++) {
            coordinates[i] = Integer.parseInt(l1[i]);  // Convert each string to an integer and store in the array
        }

        int x1 = coordinates[0];  // Assign the first four coordinates to variables
        int y1 = coordinates[1];
        int x2 = coordinates[2];
        int y2 = coordinates[3];

        int denominator = x2 - x1;  // Calculate the denominator and numerator for slope calculation
        int numerator = y2 - y1;

        double quotient = 0.0;  // Calculate the slope of the line
        if (denominator!= 0) {
            quotient = (double) numerator / denominator;
        }

        if (numerator == 0) {  // Check if the line is horizontal
            int d = (int) Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));  // Calculate the distance between the two points
            int x3 = x1;
            int x4 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);  // Print the new coordinates
        } else if (denominator == 0) {  // Check if the line is vertical
            int y3 = y1;
            int y4 = y2;
            int d = (int) Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));  // Calculate the distance between the two points
            int x3 = x1 + d;
            int x4 = x2 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);  // Print the new coordinates
        } else if (quotient == 1.0) {  // Check if the slope is 1 (45 degrees)
            int x3 = x2;
            int x4 = x1;
            int y3 = y1;
            int y4 = y2;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);  // Print the new coordinates
        } else if (quotient == -1.0) {  // Check if the slope is -1 (-45 degrees)
            int x3 = x1;
            int x4 = x2;
            int y3 = y2;
            int y4 = y1;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);  // Print the new coordinates
        } else {
            System.out.println(-1);  // If none of the conditions are met, print -1
        }
    }
}

