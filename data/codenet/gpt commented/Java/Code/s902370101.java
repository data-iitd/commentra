import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements to be entered into the array
        int n = sc.nextInt();
        
        // Initialize an array to hold the input integers
        int[] array = new int[n];
        
        // Initialize variables to track the maximum and minimum values
        int max = 0; // Starting with 0 as the initial maximum
        int min = 10000; // Starting with a high value as the initial minimum
        
        // Loop through the array to read integers and find max and min
        for (int i = 0; i < array.length; i++) {
            // Read the next integer from input and store it in the array
            array[i] = sc.nextInt();
            
            // Update max if the current element is greater than the current max
            if (max < array[i]) {
                max = array[i];
            }

            // Update min if the current element is less than the current min
            if (min > array[i]) {
                min = array[i];
            }
        }
        
        // Calculate and print the difference between max and min values
        System.out.println(max - min);
        
        // Close the scanner to free up resources
        sc.close();
    }
}
