import java.io.*; 
import java.util.*; 

// Main class definition
final public class Main { 
    public static void main(String[] args) throws IOException { 
        // Initialize BufferedReader to read input from standard input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        
        // StringBuilder to construct output efficiently
        StringBuilder sb = new StringBuilder(); 
        
        // Read the number of elements (n)
        int n = Integer.parseInt(br.readLine()); 
        
        // Tokenize the input line containing the numbers
        StringTokenizer st = new StringTokenizer(br.readLine()); 
        
        // Array to store the numbers and variables for calculations
        Double[] arr = new Double[2 * n]; 
        int non_int = 0; // Counter for non-integer values
        double sum_before = 0, sum = 0; // Variables to store sums
        
        // Loop through the input numbers
        for (int i = 0; i < 2 * n; i++) { 
            // Parse the next number from the input
            double num = Double.parseDouble(st.nextToken()); 
            
            // Accumulate the total sum of the numbers
            sum_before += num; 
            
            // Check if the number is non-integer and update the counter
            if (num != Math.floor(num)) 
                non_int++; 
            
            // Accumulate the sum of the integer parts of the numbers
            sum += Math.floor(num); 
            
            // Store the number in the array
            arr[i] = num; 
        } 
        
        // Calculate the maximum possible sum considering non-integer values
        double max_sum = Math.min(n, non_int) + sum; 
        
        // Calculate the minimum possible sum considering non-integer values
        double min_sum = Math.max(0, non_int - n) + sum; 
        
        double ans; // Variable to store the final answer
        
        // Determine the answer based on the calculated sums
        if (min_sum > sum_before) 
            ans = (min_sum - sum_before); // Case where min_sum is greater than the total sum
        else if (max_sum < sum_before) 
            ans = (sum_before - max_sum); // Case where max_sum is less than the total sum
        else { 
            // Case where the total sum is between min_sum and max_sum
            double x = sum_before - Math.floor(sum_before); 
            ans = Math.min(1 - x, x); // Calculate the minimum distance to the nearest integer
        } 
        
        // Print the final answer formatted to three decimal places
        System.out.printf("%.3f", ans); 
    } 
}
