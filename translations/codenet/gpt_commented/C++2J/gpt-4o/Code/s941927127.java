import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a string variable to hold the input
        Scanner scanner = new Scanner(System.in);
        String W = scanner.next();
        
        // Convert the string to a character array and sort it
        char[] charArray = W.toCharArray();
        Arrays.sort(charArray);
        
        // Iterate through the sorted character array, checking pairs of characters
        for (int i = 0; i < charArray.length; i += 2) {
            // Check if the current character is not equal to the next character
            if (i + 1 >= charArray.length || charArray[i] != charArray[i + 1]) {
                // If they are not equal, print "No" and exit the program
                System.out.println("No");
                return;
            }
        }
        
        // If all pairs are equal, print "Yes"
        System.out.println("Yes");
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
