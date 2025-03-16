import java.util.*; // Importing the necessary packages

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Reading the number of elements to be processed
        int n = sc.nextInt();
        
        // Initializing an ArrayList to store the integer values
        ArrayList<Integer> a = new ArrayList<Integer>();
        int value;
        
        // Loop to read 'n' integers from user input and add them to the ArrayList
        for (int i = 0; i < n; i++) {
            value = sc.nextInt();
            a.add(value);
        }
        
        // Variables to hold the result, position of the last valid number, and a flag
        int result, pos = 0, flag = 0;
        
        // Check if the first element is greater than 15
        if (a.get(0) > 15) {
            result = 15; // If true, set result to 15
        } else {
            // Loop through the ArrayList to find the first gap greater than 15
            for (int i = 1; i < n; i++) {
                if (a.get(i) - a.get(i - 1) > 15) {
                    pos = i - 1; // Store the position of the last valid number
                    flag = 1; // Set flag to indicate a gap was found
                    break; // Exit the loop as we found the gap
                }
            }
            // If a gap was found, calculate the result based on the last valid number
            if (flag == 1) {
                result = a.get(pos) + 15;
            } else {
                // If no gap was found, set result based on the last number in the list
                result = a.get(n - 1) + 15;
            }
        }
        
        // Ensure the result does not exceed 90
        if (result > 90) {
            result = 90; // Cap the result at 90
        }
        
        // Output the final result
        System.out.println(result);
    }
}
