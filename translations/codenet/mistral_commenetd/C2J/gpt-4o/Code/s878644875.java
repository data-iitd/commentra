import java.util.Scanner; // Import the Scanner class for input

public class Main { // Declare the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        char[] s = new char[4]; // Declare a character array of size 4
        char[] t = new char[4]; // Declare another character array of size 4
        
        // Read a string of length less than or equal to 3 and store it in array s
        String inputS = scanner.next(); 
        for (int i = 0; i < inputS.length(); i++) {
            s[i] = inputS.charAt(i);
        }
        
        // Read a string of length less than or equal to 3 and store it in array t
        String inputT = scanner.next(); 
        for (int i = 0; i < inputT.length(); i++) {
            t[i] = inputT.charAt(i);
        }
        
        int hit = 0; // Initialize a counter variable hit to 0
        for (int i = 0; i < 3; i++) { // Start a for loop that iterates from 0 to 2 (3 times)
            if (s[i] == t[i]) hit++; // If the i-th character of string s is equal to the i-th character of string t, increment the counter variable hit
        }
        
        System.out.println(hit); // Print the value of the counter variable hit to the standard output
        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
