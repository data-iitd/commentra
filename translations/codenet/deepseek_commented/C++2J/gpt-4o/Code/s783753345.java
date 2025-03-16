import java.util.Scanner;

public class Main {
    // Main method where the program execution begins
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Declare variables to store integers and a character
        int a, b;
        char S;
        
        // Infinite loop to continuously take input and perform operations
        while (true) {
            // Take input in the format a S b
            a = scanner.nextInt();
            S = scanner.next().charAt(0);
            b = scanner.nextInt();
            
            // Perform operations based on the value of S
            if (S == '+') System.out.println(a + b);
            if (S == '-') System.out.println(a - b);
            if (S == '*') System.out.println(a * b);
            if (S == '/') System.out.println(a / b);
            
            // Break the loop if S is '?'
            if (S == '?') break;
        }
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
