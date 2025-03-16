import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 1: Take input from the user and split it into a list of integers
        Scanner scanner = new Scanner(System.in);
        String given = scanner.nextLine();
        String[] parts = given.split(" ");
        int[] l1 = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            l1[i] = Integer.parseInt(parts[i]);
        }

        // Step 2: Assign the values to variables x1, y1, x2, and y2
        int x1 = l1[0];
        int y1 = l1[1];
        int x2 = l1[2];
        int y2 = l1[3];

        // Step 3: Check if the denominator is not zero to calculate the quotient
        int denominator = x2 - x1;
        int numerator = y2 - y1;
        Double quotient = null;
        if (denominator != 0) {
            quotient = (double) numerator / denominator;
        }

        // Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
        if (numerator == 0) {
            int d = (int) Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            int x4 = x1;
            int x3 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        }
        // Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
        else if (denominator == 0) {
            int y4 = y2;
            int y3 = y1;
            int d = (int) Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            int x4 = x1 + d;
            int x3 = x2 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        }
        // Step 6: If the quotient is 1 or -1, swap the coordinates and print them
        else if (quotient != null && (quotient == 1 || quotient == -1)) {
            int x4, x3, y4, y3;
            if (quotient == 1) {
                x4 = x2;
                x3 = x1;
                y4 = y1;
                y3 = y2;
            } else {
                x4 = x1;
                x3 = x2;
                y4 = y2;
                y3 = y1;
            }
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        }
        // Step 7: If none of the above conditions are met, print -1
        else {
            System.out.println("-1");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
