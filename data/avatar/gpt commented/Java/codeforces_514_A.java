import java.util.ArrayList; 
import java.util.List; 
import java.util.Scanner; 

public class Main { 
    public static void main(String args[]) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Initialize a list to store the digits after transformation
        List<Long> list = new ArrayList<>(); 
        
        // Read a long integer from the user
        long x = sc.nextLong(); 
        
        // Process each digit of the number until there are no digits left
        while (x > 0) { 
            // Extract the last digit of the number
            long r = x % 10; 
            
            // Determine whether to keep the digit or replace it with its complement to 9
            if (9 - r < r) { 
                // If the digit is the last one and its complement is 0, keep the digit
                if (x / 10 == 0 && 9 - r == 0) 
                    list.add(r); 
                else 
                    // Otherwise, add the complement to the list
                    list.add(9 - r); 
            } else 
                // If the digit is less than or equal to its complement, keep the digit
                list.add(r); 
            
            // Remove the last digit from the number
            x = x / 10; 
        } 
        
        // Initialize variables to construct the new number
        int pow = 0; 
        long newNumber = 0; 
        
        // Reconstruct the new number from the transformed digits
        for (int i = 0; i < list.size(); i++) { 
            newNumber = newNumber + list.get(i) * (long) Math.pow(10, pow); 
            pow++; 
        } 
        
        // Output the newly constructed number
        System.out.println(newNumber); 
    } 
}
