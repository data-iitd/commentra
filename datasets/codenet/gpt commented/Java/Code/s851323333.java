import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Initialize a LinkedList to store integers
        LinkedList<Integer> list = new LinkedList<Integer>();
        
        // Continuously read integers from the input until there are no more integers
        while(scan.hasNextInt() == true) {
            // Read the next integer from the input
            int a = scan.nextInt();
            
            // Check if the input integer is 0
            if(a == 0) {
                // If it is 0, pop and print the last element from the list
                System.out.println(list.pop());
            } else {
                // If it is not 0, push the integer onto the list
                list.push(a);
            }
        }
        
        // Close the scanner to prevent resource leaks
        scan.close();
    }
}
