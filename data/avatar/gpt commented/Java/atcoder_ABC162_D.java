import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the integer n which represents the length of the string
        int n = sc.nextInt(); 
        
        // Read the string s which contains characters 'R', 'G', and 'B'
        String s = sc.next(); 
        
        // Initialize counters for each color
        long rc = 0; // Counter for 'R'
        long gc = 0; // Counter for 'G'
        long bc = 0; // Counter for 'B'
        
        // Count the occurrences of each character in the string
        for (int i = 0; i < s.length(); i++) { 
            if (s.charAt(i) == 'R') { 
                rc++; // Increment red counter
            } else if (s.charAt(i) == 'G') { 
                gc++; // Increment green counter
            } else { 
                bc++; // Increment blue counter
            } 
        } 
        
        // Calculate the initial result based on the product of the counts
        long result = rc * gc * bc; 
        
        // Iterate through all pairs of indices (i, k) to check conditions
        for (int i = 1; i <= n; i++) { 
            for (int k = i + 1; k <= n; k++) { 
                // Check if the sum of indices is even
                if ((i + k) % 2 == 0) { 
                    // Get the characters at the current indices
                    char is = s.charAt(i - 1); 
                    char ks = s.charAt(k - 1); 
                    char js = s.charAt(((i + k) / 2) - 1); 
                    
                    // Check if all three characters are different
                    if (is != ks && ks != js && js != is) { 
                        result--; // Decrease the result if the condition is met
                    } 
                } 
            } 
        } 
        
        // Output the final result
        System.out.println(result); 
    } 
}
