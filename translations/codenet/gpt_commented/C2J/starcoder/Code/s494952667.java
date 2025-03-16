
import java.util.Scanner;

public class ReverseString {

    public static void main(String[] args) {
        // Declare a character array to hold the input string (maximum length 20 + 1 for null terminator)
        char[] str = new char[21];
        int i, len;
        
        // Read a string from standard input
        Scanner in = new Scanner(System.in);
        str = in.nextLine().toCharArray();
        
        // Calculate the length of the input string
        len = str.length;

        // Loop through the string in reverse order
        for(i = len - 1; i >= 0; i--){
            // Output each character of the string in reverse
            System.out.print(str[i]);
        }
        
        // Print a newline character after the reversed string
        System.out.println();
    }
}

