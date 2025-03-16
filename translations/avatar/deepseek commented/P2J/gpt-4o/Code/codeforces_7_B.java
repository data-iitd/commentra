import java.util.*;

public class MemoryManager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt(); // Read the number of operations
        int m = scanner.nextInt(); // Read the size of the memory
        scanner.nextLine(); // Consume the newline
        
        int[] alocuente = new int[m]; // Initialize an array to keep track of memory allocation
        Arrays.fill(alocuente, 0); // Set all elements to 0
        
        int ind = 1; // Initialize the ID counter for allocated memory blocks
        
        for (int i = 0; i < t; i++) {
            String[] op = scanner.nextLine().split(" "); // Read the operation and split it into parts
            
            if (op[0].equals("alloc")) {
                // If the operation is to allocate memory
                int pos = 0; // Initialize a position counter
                int size = Integer.parseInt(op[1]); // Required size to allocate
                
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        pos++; // Increment the position counter
                        if (pos == size) {
                            // If a contiguous block of the required size is found
                            for (int k = j - size + 1; k <= j; k++) {
                                alocuente[k] = ind; // Allocate the memory block with the current ID
                            }
                            System.out.println(ind); // Print the allocated ID
                            ind++; // Increment the ID counter
                            break;
                        }
                    } else {
                        pos = 0; // Reset the position counter if a free block is interrupted
                    }
                }
                
                if (pos < size) {
                    System.out.println("NULL"); // If no contiguous block is found, print "NULL"
                }
            }
            
            if (op[0].equals("erase")) {
                // If the operation is to erase a memory block
                int idToErase = Integer.parseInt(op[1]);
                
                if (idToErase <= 0 || !contains(alocuente, idToErase)) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT"); // Print error if ID is invalid
                } else {
                    for (int j = 0; j < m; j++) {
                        if (alocuente[j] == idToErase) {
                            alocuente[j] = 0; // Free the specified memory block
                        }
                    }
                }
            }
            
            if (op[0].equals("defragment")) {
                // If the operation is to defragment the memory
                int cnt = 0; // Count the number of free memory blocks
                
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        cnt++; // Count free blocks
                    }
                }
                
                int[] newAlocuente = new int[m]; // Create a new array for defragmented memory
                int index = 0;
                
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] != 0) {
                        newAlocuente[index++] = alocuente[j]; // Copy allocated blocks
                    }
                }
                
                // Fill the rest with zeros
                for (int j = index; j < m; j++) {
                    newAlocuente[j] = 0;
                }
                
                alocuente = newAlocuente; // Update the original array
            }
        }
        
        scanner.close(); // Close the scanner
    }
    
    // Helper method to check if the array contains a specific ID
    private static boolean contains(int[] array, int value) {
        for (int j : array) {
            if (j == value) {
                return true;
            }
        }
        return false;
    }
}
// <END-OF-CODE>
