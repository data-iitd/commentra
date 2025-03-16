import java.util.*; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in);
        
        // Reading the number of elements in the array
        int n = scan.nextInt();
        
        // Initializing an array to hold the input values
        long[] arr = new long[n];
        
        // Loop to read 'n' integers from the user and store them in the array
        for (int i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
        }
        
        // Initialize the answer with the absolute value of the first element
        long answer = Math.abs(arr[0]);
        
        // Loop to calculate the sum of absolute differences between consecutive elements
        for (int i = 1; i < n; i++) {
            answer += Math.abs(arr[i] - arr[i - 1]);
        }
        
        // Output the final calculated answer
        System.out.println(answer);
    }
}
