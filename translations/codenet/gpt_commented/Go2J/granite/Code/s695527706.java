
import java.util.Scanner; // Importing the Scanner class for input reading

public class s695527706{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the standard input

        int n = scanner.nextInt(); // Read the length of the string n from the standard input
        scanner.nextLine(); // Consume the newline character after reading n

        String s = scanner.nextLine(); // Read the input string s from the standard input

        int count = 0; // Initialize a variable count to keep track of the number of occurrences of the substring "ABC" in the string s

        // Use a for loop to iterate over the characters in the string s
        for (int i = 0; i < s.length() - 2; i++) {
            // Check if the substring "ABC" is present starting from index i in the string s
            if (s.substring(i, i + 3).equals("ABC")) {
                count++; // Increment the count variable if the substring "ABC" is found
            }
        }

        // Print the number of occurrences of the substring "ABC" in the string s
        System.out.println(count);

        scanner.close(); // Close the Scanner object to release system resources
    }
}
