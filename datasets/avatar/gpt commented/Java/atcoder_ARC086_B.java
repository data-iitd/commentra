import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner s = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int n = s.nextInt(); 
        
        // Initialize an array of size n to hold the integers
        int[] a = new int[n]; 
        
        // Populate the array with user input
        Arrays.setAll(a, i -> s.nextInt()); 
        
        // Create a list to store the result pairs
        ArrayList<String> r = new ArrayList<>(); 
        
        // Variable to track the index of the element with the maximum absolute value
        int m = 0; 
        
        // Find the index of the element with the maximum absolute value
        for (int i = 1; i < n; ++i) 
            if (Math.abs(a[m]) < Math.abs(a[i])) 
                m = i; 
        
        // Generate pairs of indices based on the sign of the maximum absolute value element
        for (int i = 0; i < n; ++i) 
            if (a[m] >= 0 ^ a[i] >= 0) 
                r.add((m + 1) + " " + (i + 1)); 
        
        // If the maximum absolute value element is non-negative
        if (a[m] >= 0) { 
            // Add pairs of consecutive indices in ascending order
            for (int i = 1; i < n; ++i) 
                r.add(i + " " + (i + 1)); 
        } else { 
            // If the maximum absolute value element is negative, add pairs in descending order
            for (int i = n; i > 1; --i) 
                r.add(i + " " + (i - 1)); 
        } 
        
        // Print the size of the result list
        System.out.println(r.size()); 
        
        // Print each pair in the result list
        r.forEach(System.out::println); 
    } 
}
