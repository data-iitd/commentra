import java.util.ArrayList; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        # Create a Scanner object to read input from the console
        input = Scanner(System.in); 
        
        # Read the number of required items (n) and the number of available items (m)
        n = input.nextInt(); 
        m = input.nextInt(); 
        
        # Initialize ArrayLists to store the required items and the available items
        req = ArrayList(); 
        pre = ArrayList(); 
        
        # Read the required items from the input and store them in the req list
        for i in range(n): 
            req.add(input.nextInt()); 
        
        # Read the available items from the input and store them in the pre list
        for i in range(m): 
            pre.add(input.nextInt()); 
        
        # Initialize pointers for the required items (i) and available items (j)
        i = n - 1; 
        j = m - 1; 
        
        # Variable to count how many required items can be satisfied
        ans = 0; 
        
        # Compare the required items with the available items from the end of both lists
        while i >= 0 and j >= 0: 
            # If the current required item is greater than the current available item
            if req.get(i) > pre.get(j): 
                # Increment the count of satisfied items
                ans++; 
            else: 
                # Move to the next available item if the current one cannot satisfy the requirement
                j--; 
            # Move to the next required item
            i--; 
        
        # Print the total number of satisfied items plus the remaining unsatisfied required items
        print(ans + i + 1); 
    } 
}

