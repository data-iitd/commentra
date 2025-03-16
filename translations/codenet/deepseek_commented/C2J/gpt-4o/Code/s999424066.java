import java.util.Scanner;  // Step 1: Import the Scanner class for input.

public class Main {  // Step 2: Define the Main class.
    public static void main(String[] args) {  // Step 3: Define the main method.
        Scanner scanner = new Scanner(System.in);  // Step 4: Create a Scanner object for input.
        int a, b, c, x, y;  // Step 5: Declare integer variables a, b, c, x, y.
        a = scanner.nextInt();  // Step 6: Read value for a from the user.
        b = scanner.nextInt();  // Step 7: Read value for b from the user.
        c = scanner.nextInt();  // Step 8: Read value for c from the user.
        x = scanner.nextInt();  // Step 9: Read value for x from the user.
        y = scanner.nextInt();  // Step 10: Read value for y from the user.
        c *= 2;  // Step 11: Double the value of c.
        
        if (a + b <= c) {  // Step 12: Check if the sum of a and b is less than or equal to c.
            System.out.println(a * x + b * y);  // Step 13: If true, print the product of a and x plus the product of b and y.
        } else {  // Step 14: If false, start the else block.
            if (x <= y) {  // Step 15: Check if x is less than or equal to y.
                if (b <= c) {  // Step 16: Check if b is less than or equal to c.
                    System.out.println(c * x + (y - x) * b);  // Step 17: If true, print the product of c and x plus the product of (y - x) and b.
                } else {  // Step 18: If false, start the else block.
                    System.out.println(c * y);  // Step 19: Print the product of c and y.
                }
            } else {  // Step 20: If x is greater than y, start the else block.
                if (a <= c) {  // Step 21: Check if a is less than or equal to c.
                    System.out.println(c * y + (x - y) * a);  // Step 22: If true, print the product of c and y plus the product of (x - y) and a.
                } else {  // Step 23: If false, start the else block.
                    System.out.println(c * x);  // Step 24: Print the product of c and x.
                }
            }
        }
        scanner.close();  // Step 25: Close the scanner.
    }  // Step 26: End of the main method.
}  // Step 27: End of the Main class.
