import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int n = sc.nextInt(); 
        
        // Initialize an array to hold the integer values
        int[] a = new int[n]; 
        
        // Populate the array with input values
        for (int i = 0; i < n; i++) { 
            a[i] = sc.nextInt(); 
        } 
        
        // Read the string input which consists of characters 'A' and 'B'
        String s = sc.next(); 
        
        // Initialize a variable to hold the sum of values corresponding to 'B'
        long sum = 0; 
        
        // Calculate the initial sum based on the positions of 'B' in the string
        for (int i = 0; i < s.length(); i++) { 
            char ch = s.charAt(i); 
            if (ch == 'B') 
                sum += a[i]; // Add the value to sum if the character is 'B'
        } 
        
        // Store the initial sum as the maximum answer found so far
        long ans = sum; 
        long sum1 = sum; 
        
        // Iterate through the string to calculate the maximum possible sum
        for (int i = 0; i < s.length(); i++) { 
            if (s.charAt(i) == 'A') 
                sum1 += a[i]; // Increase sum1 if the character is 'A'
            else 
                sum1 -= a[i]; // Decrease sum1 if the character is not 'A'
            
            // Update the maximum answer if the current sum1 is greater
            ans = Math.max(ans, sum1); 
        } 
        
        // Reset sum1 to the initial sum for the next calculation
        sum1 = sum; 
        
        // Iterate through the string in reverse to calculate the maximum possible sum
        for (int i = s.length() - 1; i >= 0; i--) { 
            if (s.charAt(i) == 'A') 
                sum1 += a[i]; // Increase sum1 if the character is 'A'
            else 
                sum1 -= a[i]; // Decrease sum1 if the character is not 'A'
            
            // Update the maximum answer if the current sum1 is greater
            ans = Math.max(ans, sum1); 
        } 
        
        // Output the maximum sum found
        System.out.println(ans); 
    } 
}
