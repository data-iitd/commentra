
import java.util.Scanner;

public class s387404795{
    public static void main(String[] args) {
        // Declare character arrays for input strings and temporary storage
        char str[] = new char[201];
        char tmp[] = new char[101];
        char p[] = new char[101];
        
        // Declare integer variables for string lengths and loop control
        int slen, plen;
        int i, j, flag;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read two strings from standard input
        scanner.nextLine().getChars(0, 200, str, 0);
        scanner.nextLine().getChars(0, 100, p, 0);
        
        // Copy the original string into a temporary variable and concatenate it with itself
        System.arraycopy(str, 0, tmp, 0, 200);
        System.arraycopy(str, 0, str, 200, 200);
        System.arraycopy(tmp, 0, str, 400, 200);
        
        // Calculate the lengths of the concatenated string and the pattern string
        slen = str.length;
        plen = p.length;
        
        // Initialize a flag to indicate if the pattern is found
        flag = 0;
        
        // Loop through the concatenated string to search for the pattern
        for (i = 0; i < slen - plen; i++) {
            // Compare the substring of str with the pattern p
            if (Arrays.equals(Arrays.copyOfRange(str, i, i + plen), p)) 
                flag = 1; // Set flag if a match is found
        }
        
        // Output "Yes" if the pattern was found, otherwise output "No"
        if (flag == 1) 
            System.out.println("Yes");
        else 
            System.out.println("No");
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}
