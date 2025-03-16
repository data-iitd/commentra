import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Get user input and convert it to a list of integers
        String given = scanner.nextLine();
        String[] l1 = given.split(" ");
        int[] intArray = new int[l1.length];
        for (int i = 0; i < l1.length; i++) {
            intArray[i] = Integer.parseInt(l1[i]);
        }
        
        // Assign the first two elements of the list to x1, y1 and the last two elements to x2, y2
        int x1 = intArray[0];
        int y1 = intArray[1];
        int x2 = intArray[2];
        int y2 = intArray[3];
        
        // Calculate the denominator and numerator of the slope
        int denominator = x2 - x1;
        int numerator = y2 - y1;
        
        // Check if the denominator is zero
        if (denominator == 0) {
            // Calculate the distance between the two points and print the result
            int d = (int) Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            int x4 = x1;
            int x3 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        }
        // If the denominator is not zero, calculate the quotient
        else if (denominator != 0) {
            double quotient = (double) numerator / denominator;
            
            // Check if the quotient is equal to 1 or -1
            if (quotient == 1.0 || quotient == -1.0) {
                // Swap the x and y coordinates of the two points and print the result
                if (quotient == 1.0) {
                    int x4 = x2;
                    int x3 = x1;
                    int y3 = y1;
                    int y4 = y2;
                    System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
                } else {
                    int x4 = x1;
                    int x3 = x2;
                    int y3 = y2;
                    int y4 = y1;
                    System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
                }
            }
            // If the quotient is not 1 or -1, print -1
            else {
                System.out.println("-1");
            }
        }
    }
}
