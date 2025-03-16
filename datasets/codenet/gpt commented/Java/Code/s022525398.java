import java.util.Scanner; // Import the Scanner class for user input

class Main {
    
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner in = new Scanner(System.in);
        
        // Read the first string input from the user
        String a = in.next();
        
        // Read the second string input from the user
        String b = in.next();
        
        // Concatenate the second string with the first string and print the result
        System.out.println(b + a);
        
        // Close the scanner to prevent resource leaks
        in.close();
    }
}
