
import java.util.Scanner;

class Main {
    
    // Main method is the entry point of the Java program
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Read two strings from the user
        String a = in.next();
        String b = in.next();
        
        // Print the concatenated result of the two strings in reverse order
        System.out.println(b + a);
    }
    
}

