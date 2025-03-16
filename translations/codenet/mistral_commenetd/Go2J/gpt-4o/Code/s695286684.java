import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Prompt the user for input
        System.out.print("Enter a string: ");
        
        // Read a string input from the user
        String s = scanner.nextLine();
        
        // Replace all occurrences of the string "2017" in the string `s` with the string "2018"
        s = s.replace("2017", "2018");
        
        // Print the modified string to the standard output
        System.out.println("Modified string: " + s);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
