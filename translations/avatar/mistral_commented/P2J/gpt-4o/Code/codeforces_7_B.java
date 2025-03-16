import java.util.Arrays;
import java.util.Scanner;

public class MemoryAllocator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input number of tests and memory size
        int t = scanner.nextInt();
        int m = scanner.nextInt();
        int[] alocuente = new int[m];
        int ind = 1; // Initialize index for allocation

        // Loop through each test case
        for (int i = 0; i < t; i++) {
            String op = scanner.next();

            // Allocate memory if the operation type is 'alloc'
            if (op.equals("alloc")) {
                int size = scanner.nextInt();
                int pos = 0; // Initialize position counter
                boolean allocated = false;

                for (int j = 0; j < m; j++) {
                    // Check if the position is available for allocation
                    if (alocuente[j] == 0) {
                        pos++;
                        if (pos == size) {
                            // Set the allocated memory blocks to the given index
                            Arrays.fill(alocuente, j - size + 1, j + 1, ind);
                            // Print the allocated index
                            System.out.println(ind);
                            // Increment the index for the next allocation
                            ind++;
                            allocated = true;
                            break;
                        }
                    } else {
                        pos = 0; // Reset the position counter for the next iteration
                    }
                }

                if (!allocated) {
                    // If no suitable position is found, print 'NULL'
                    System.out.println("NULL");
                }

            // Erase memory if the operation type is 'erase'
            } else if (op.equals("erase")) {
                int index = scanner.nextInt();
                boolean illegalErase = true;

                // Check if the given index is valid and allocated
                if (index > 0 && Arrays.stream(alocuente).anyMatch(x -> x == index)) {
                    // If the index is valid and allocated, free the memory block
                    for (int j = 0; j < m; j++) {
                        if (alocuente[j] == index) {
                            alocuente[j] = 0; // Set the memory block to 0 to indicate it is freed
                        }
                    }
                    illegalErase = false;
                }

                if (illegalErase) {
                    // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                }

            // Defragment memory if the operation type is 'defragment'
            } else if (op.equals("defragment")) {
                int cnt = 0; // Initialize free block counter
                // Count the number of free blocks
                for (int j : alocuente) {
                    if (j == 0) {
                        cnt++;
                    }
                }
                // Create a new array with only allocated blocks
                int[] newAlocuente = Arrays.stream(alocuente).filter(x -> x != 0).toArray();
                // Add free blocks at the end of the array
                alocuente = new int[m];
                System.arraycopy(newAlocuente, 0, alocuente, 0, newAlocuente.length);
            }
        }

        scanner.close();
    }
}
// <END-OF-CODE>
