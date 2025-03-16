import java.util.Arrays;
import java.util.Scanner;

public class MemoryAllocator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of operations (t) and the size of the array (m)
        int t = scanner.nextInt();
        int m = scanner.nextInt();
        // Initialize an array to keep track of allocated memory blocks, initially all set to 0
        int[] alocuente = new int[m];
        // Initialize an index to keep track of the next allocation identifier
        int ind = 1;

        // Process each operation
        for (int i = 0; i < t; i++) {
            // Read the operation and its parameters
            String op = scanner.next();
            
            // Handle the 'alloc' operation
            if (op.equals("alloc")) {
                int size = scanner.nextInt();
                int pos = 0;  // Position counter to find free blocks
                for (int j = 0; j < m; j++) {
                    // Check if the current block is free (0)
                    if (alocuente[j] == 0) {
                        pos++;  // Increment the position counter
                        // If we have found enough consecutive free blocks
                        if (pos == size) {
                            // Allocate the blocks and set them to the current identifier
                            for (int k = j - size + 1; k <= j; k++) {
                                alocuente[k] = ind;
                            }
                            System.out.println(ind);  // Output the identifier of the allocated blocks
                            ind++;  // Increment the identifier for the next allocation
                            break;
                        }
                    } else {
                        pos = 0;  // Reset position counter if a block is occupied
                    }
                }
                if (pos < size) {
                    // If no sufficient space was found, output NULL
                    System.out.println("NULL");
                }
            }
            
            // Handle the 'erase' operation
            if (op.equals("erase")) {
                int eraseId = scanner.nextInt();
                boolean found = false;  // Flag to check if the identifier is found
                // Check if the identifier to erase is valid
                if (eraseId <= 0 || Arrays.stream(alocuente).noneMatch(x -> x == eraseId)) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");  // Output error for illegal erase
                } else {
                    // Iterate through the array to find and erase the specified block
                    for (int j = 0; j < m; j++) {
                        if (alocuente[j] == eraseId) {
                            alocuente[j] = 0;  // Set the block to 0 to indicate it is free
                            found = true;
                        }
                    }
                }
            }
            
            // Handle the 'defragment' operation
            if (op.equals("defragment")) {
                int cnt = 0;  // Counter for the number of free blocks
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        cnt++;  // Count how many blocks are free
                    }
                }
                // Create a new array with only the allocated blocks (non-zero)
                int[] newAlocuente = new int[m];
                int index = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] != 0) {
                        newAlocuente[index++] = alocuente[j];
                    }
                }
                // Append the free blocks (0) back to the end of the list
                for (int j = index; j < m; j++) {
                    newAlocuente[j] = 0;
                }
                alocuente = newAlocuente;  // Update the original array
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
