import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an ArrayList to store the results for each input set
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        // Create a Scanner object to read input from the console
        Scanner insert = new Scanner(System.in);
        
        // Variable to hold the number of elements in the current input set
        int n = -1;
        
        // Infinite loop to continuously accept input until a termination condition is met
        while(true) {
            // Read a line of input and parse it as an integer
            String line = insert.nextLine();
            n = Integer.parseInt(line);
            
            // Check for the termination condition (input of 0)
            if(n == 0) {
                break; // Exit the loop if n is 0
            }
            
            // Read the next line of input containing the numbers
            line = insert.nextLine();
            String array2[] = line.split(" "); // Split the line into an array of strings
            
            // Initialize an array to hold the integer values from the input
            int[] input = new int[n];
            int sum = 0; // Variable to hold the sum of the input numbers
            
            // Loop to parse the input strings into integers and calculate the sum
            for(int i = 0; i < n; i++) {
                input[i] = (Integer.parseInt(array2[i])); // Parse each string to an integer
                sum += input[i]; // Add the current number to the sum
            }
            
            // Calculate the average of the input numbers
            double avg = (double) sum / (double) n;
            int num = 0; // Variable to count how many numbers are less than or equal to the average
            
            // Loop to count how many numbers are less than or equal to the average
            for(int i = 0; i < n; i++) {
                if(input[i] <= avg) {
                    num++; // Increment the count if the current number is less than or equal to the average
                }
            }
            
            // Add the count to the result list
            result.add(num);
        }
        
        // Loop to print the results for each input set
        for(int i = 0; i < result.size(); i++) {
            // Check if the result is -1 (though this case won't occur in the current logic)
            if(result.get(i) == -1) {
                System.out.println("NONE"); // Print "NONE" if the result is -1
            } else {
                System.out.println(result.get(i)); // Print the count of numbers less than or equal to the average
            }
        }
    }
}
