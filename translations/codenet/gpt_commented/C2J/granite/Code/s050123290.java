
import java.util.Scanner;

public class s050123290{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[] su = new char[1000];  // Declare a character array to store the input, initialized with '0'
        int susum = 0;  // Initialize a variable to hold the sum of the digits
        int j = 0;  // Initialize a counter variable for the loop

        // Infinite loop to continuously read input until a specific condition is met
        while(true) {
            // Loop to read characters into the array until a newline is encountered or the limit is reached
            for(j = 0; j < 1000; j++) {
                su[j] = scanner.next().charAt(0);  // Read a character from standard input
                if(su[j] == '\n') break;  // Break the loop if a newline character is encountered
                susum = susum + (su[j] - '0');  // Convert the character to an integer and add it to the sum
            }   
            
            // Check if the first character is '0', which indicates the end of input
            if(su[0] == '0') break;  // Exit the loop if the first character is '0'
            
            System.out.println(susum);  // Print the sum of the digits read
            susum = 0;  // Reset the sum for the next input
        }
        
        scanner.close();  // Close the scanner to release system resources
    }
}
