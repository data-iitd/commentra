import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int n = sc.nextInt(); 
        
        // Read the value of k
        long k = sc.nextLong(); 
        
        // Initialize an array to hold the input numbers
        long[] arr = new long[n]; 
        
        // Create a HashSet to store unique elements that meet the criteria
        HashSet<Long> set = new HashSet<>(); 
        
        // Read n long integers into the array
        for (int i = 0; i < n; i++) { 
            arr[i] = sc.nextLong(); 
        } 
        
        // Sort the array to facilitate the processing of elements
        Arrays.sort(arr); 
        
        // Initialize a counter to keep track of valid elements
        int count = 0; 
        
        // Iterate through the sorted array to apply the conditions
        for (int i = 0; i < n; i++) { 
            // Check if the current element is not divisible by k
            if (arr[i] % k != 0) { 
                count++; // Increment count for valid element
                set.add(arr[i]); // Add the element to the set
            } 
            // Check if the current element is divisible by k and its corresponding k-factor is not in the set
            else if (!set.contains(arr[i] / k)) { 
                count++; // Increment count for valid element
                set.add(arr[i]); // Add the element to the set
            } 
        } 
        
        // Output the final count of valid elements
        System.out.println(count); 
    } 
}
