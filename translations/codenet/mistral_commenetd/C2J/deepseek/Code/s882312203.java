import java.util.Scanner; // Import the Scanner class to read input

public class Main { // Define the main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String s = scanner.next(); // Read a string from the standard input

        for (int j = 0; j < s.length(); j++) { // Iterate through each character in the string 's' using index 'j'
            for (int i = 0; i < s.length(); i++) { // Nested loop to compare each character with all other characters in the string
                if ((i != j) && (s.charAt(i) == s.charAt(j))) { // Check if the current characters at indices 'i' and 'j' are the same and not the same index
                    System.out.println("no"); // If duplicate characters are found, print 'no' and exit the program
                    return;
                }
            }
        }

        System.out.println("yes"); // If no duplicate characters are found, print 'yes'
    }
}
