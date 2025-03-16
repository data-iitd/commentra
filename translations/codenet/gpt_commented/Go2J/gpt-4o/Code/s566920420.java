import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a; // Declare a variable 'a' of type int to store user input
        a = scanner.nextInt(); // Read an integer value from standard input and store it in 'a'
        
        // Calculate the expression a + a^2 + a^3 and print the result
        System.out.println(a + a * a + a * a * a); 
    }
}

// <END-OF-CODE>
