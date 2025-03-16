import java.util.*;

public class Main {
    public static void main(String[] args){
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a string input from the user
        String C = sc.next();

        // Convert the first character of the string to its ASCII value, 
        // add 1 to it, and then convert it back to a character
        // Finally, print the resulting character to the console
        System.out.println((char)(C.charAt(0) + 1));
    }
}
