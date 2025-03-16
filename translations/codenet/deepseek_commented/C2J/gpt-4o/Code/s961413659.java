import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the user input
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Check if either of the integers is 1, and if so, change them to 14
        if (a == 1) {
            a = 14;
        }
        if (b == 1) {
            b = 14;
        }
        
        // Compare the two integers and print the appropriate result
        if (a < b) {
            System.out.println("Bob");
        } else if (a > b) {
            System.out.println("Alice");
        } else {
            System.out.println("Draw");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
