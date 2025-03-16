import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take two integers as input from the user and store them in x and y respectively
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = 0; // Initialize the variable a to 0

        // Run the while loop as long as certain conditions are met
        while ((x >= 0 && y >= 22) || (x >= 1 && y >= 12) || (x >= 2 && y >= 2)) {
            if (a == 1) { // If a is true
                if (y >= 22) { // Check if y is greater than or equal to 22
                    y -= 22; // If so, reduce y by 22
                } else if (x >= 1 && y >= 12) { // Else if x is greater than or equal to 1 and y is greater than or equal to 12
                    x -= 1; // Reduce x by 1
                    y -= 12; // Reduce y by 12
                } else { // Else, x is greater than or equal to 2 and y is greater than or equal to 2
                    x -= 2; // Reduce x by 2
                    y -= 2; // Reduce y by 2
                }
            } else { // If a is false
                if (x >= 2 && y >= 2) { // Check if x is greater than or equal to 2 and y is greater than or equal to 2
                    x -= 2; // Reduce x by 2
                    y -= 2; // Reduce y by 2
                } else if (x >= 1 && y >= 12) { // Else if x is greater than or equal to 1 and y is greater than or equal to 12
                    x -= 1; // Reduce x by 1
                    y -= 12; // Reduce y by 12
                } else { // Else, y is greater than or equal to 22
                    y -= 22; // Reduce y by 22
                }
            }
            a = 1 - a; // Toggle the value of a
        }

        // Print the name of a character based on the value of a
        System.out.println(a == 0 ? "Ciel" : "Hanako");
        
        scanner.close();
    }
}
// <END-OF-CODE>
