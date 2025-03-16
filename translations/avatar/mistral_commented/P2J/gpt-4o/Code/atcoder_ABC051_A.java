import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read a line from input
        String inputString = scanner.nextLine();
        
        // Replace all commas with spaces in the input string
        String modifiedString = inputString.replace(',', ' ');
        
        // Print the modified string to the console
        System.out.println(modifiedString);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
