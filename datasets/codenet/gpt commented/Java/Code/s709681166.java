import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read a line of input from the user
        String s = sc.nextLine();
        
        // Iterate over each character in the input string
        for(int i = 0; i < s.length(); i++){
            // Get the character at the current index
            char c = s.charAt(i);
            
            // Check if the character is an uppercase letter
            if(Character.isUpperCase(c)){
                // Convert uppercase to lowercase by adding 32 to its ASCII value
                c += 32;
                // Print the converted lowercase character
                System.out.print(c);
            }
            // Check if the character is a lowercase letter
            else if(Character.isLowerCase(c)){
                // Convert lowercase to uppercase by subtracting 32 from its ASCII value
                c -= 32;
                // Print the converted uppercase character
                System.out.print(c);
            }
            // If the character is neither uppercase nor lowercase, print it as is
            else {
                System.out.print(c);
            }
        }
        
        // Print a newline after processing the input
        System.out.println();
        
        // Close the scanner to free up resources
        sc.close();
    }
}
