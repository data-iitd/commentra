import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner s = new Scanner(System.in); 
        
        // Read the number of operations (t) and the size of memory (m)
        int t = s.nextInt(); 
        int m = s.nextInt(); 
        
        // Initialize the memory array to keep track of allocated memory
        int[] memory = new int[m]; 
        
        // Initialize the allocation index to track the allocation IDs
        int allocIdx = 0; 
        
        // Process each operation based on the number of operations (t)
        for (int j = 0; j < t; j++) { 
            // Read the operation type (alloc, erase, defragment)
            switch (s.next()) { 
                case "alloc": 
                    // Read the size of memory to allocate
                    int n = s.nextInt(); 
                    int len = 0; 
                    boolean canAlloc = false; 
                    
                    // Check for a contiguous block of free memory of size n
                    for (int i = 0; i < m; i++) { 
                        if (memory[i] == 0) 
                            len++; // Increase length if the current memory is free
                        else 
                            len = 0; // Reset length if the current memory is allocated
                        
                        // If a sufficient block is found, mark it as allocatable
                        if (len == n) { 
                            canAlloc = true; 
                            len = i - n + 1; // Calculate the starting index for allocation
                            break; 
                        } 
                    } 
                    
                    // If allocation is possible, allocate memory and print the allocation ID
                    if (canAlloc) { 
                        allocIdx++; 
                        for (int i = len; i < len + n; i++) 
                            memory[i] = allocIdx; // Mark the allocated memory with the allocation ID
                        System.out.println(allocIdx); // Output the allocation ID
                    } else 
                        System.out.println("NULL"); // Output NULL if allocation failed
                    break; 
                
                case "erase": 
                    // Read the allocation ID to erase
                    int x = s.nextInt(); 
                    
                    // Check for illegal erase argument
                    if (x <= 0) { 
                        System.out.println("ILLEGAL_ERASE_ARGUMENT"); 
                        break; 
                    } 
                    
                    boolean hasErased = false; 
                    
                    // Erase the memory corresponding to the given allocation ID
                    for (int i = 0; i < m; i++) { 
                        if (memory[i] == x) { 
                            memory[i] = 0; // Free the allocated memory
                            hasErased = true; 
                        } 
                    } 
                    
                    // If no memory was erased, print an error message
                    if (!hasErased) 
                        System.out.println("ILLEGAL_ERASE_ARGUMENT"); 
                    break; 
                
                case "defragment": 
                    // Initialize a counter for the number of free blocks
                    int d = 0; 
                    
                    // Move allocated memory to the front of the array
                    for (int i = 0; i < m; i++) { 
                        if (memory[i] == 0) 
                            d++; // Count free blocks
                        else 
                            memory[i - d] = memory[i]; // Shift allocated memory left
                    } 
                    
                    // Clear the remaining memory at the end of the array
                    for (int i = m - d; i < m; i++) 
                        memory[i] = 0; 
                    break; 
                
                default: 
                    // Handle any unrecognized command
                    System.out.println("h"); 
                    break; 
            } 
        } 
        
        // Close the scanner to free resources
        s.close(); 
    } 
}
