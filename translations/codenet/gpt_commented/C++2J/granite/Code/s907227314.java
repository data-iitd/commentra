
import java.util.Scanner;

public class s907227314{
    public static void main(String[] args) {
        // Declare a string variable to hold the input
        String s;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read input string from the user
        s = scanner.nextLine();
        
        // Declare variables to store the positions of 'A' and 'Z'
        int a, z;
        
        // Loop through the string to find the first occurrence of 'A'
        for(int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                a = i; // Store the index of 'A'
                break; // Exit the loop once 'A' is found
            }
        }
        
        // Loop through the string in reverse to find the last occurrence of 'Z'
        for(int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == 'Z') {
                z = i; // Store the index of 'Z'
                break; // Exit the loop once 'Z' is found
            }
        }
        
        // Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
        System.out.println(z - a + 1);
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}
