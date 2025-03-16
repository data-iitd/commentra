import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Infinite loop to continuously read input until the user enters "0"
        while(true){
            // Initialize a variable to hold the sum of digits
            int sum = 0;            
            // Read the next input string from the user
            String s = sc.next();
            
            // Check if the input is "0", if so, exit the loop
            if(s.equals("0")) break;
            
            // Iterate through each character in the input string
            for(int i=0; i<s.length(); i++){
                // Get the character at the current index
                char a = s.charAt(i);
                // Convert the character to its integer value and add it to the sum
                sum += a - '0';
            }
            // Print the calculated sum of the digits
            System.out.printf("%d\n", sum);
        }
        // Close the scanner to free up resources
        sc.close();
    }
}
