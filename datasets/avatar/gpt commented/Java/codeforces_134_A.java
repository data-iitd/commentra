import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int n = sc.nextInt(); 
        
        // Initialize an array to hold the integers and a variable to store the sum
        int[] arr = new int[n]; 
        int sum = 0; 
        
        // Read the integers into the array and calculate the sum
        for (int i = 0; i < n; i++) { 
            arr[i] = sc.nextInt(); 
            sum += arr[i]; // Accumulate the sum of the elements
        } 
        
        // Initialize a counter for valid indices and a StringBuilder for output
        int c = 0; 
        StringBuilder sb = new StringBuilder(); 
        
        // Check each element to see if it can be the "removed" element
        for (int i = 0; i < n; i++) { 
            // Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
            if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) { 
                c++; // Increment the count of valid indices
                sb.append((i + 1) + " "); // Append the 1-based index to the StringBuilder
            } 
        } 
        
        // Output the count of valid indices
        System.out.println(c); 
        
        // Output the indices of valid elements
        System.out.println(sb.toString()); 
    } 
}
