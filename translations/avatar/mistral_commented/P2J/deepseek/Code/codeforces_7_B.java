import java.util.Scanner;

public class MemoryManager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input number of tests and memory size
        int t = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize an array to represent the memory allocation status
        int[] alocuente = new int[m];

        // Loop through each test case
        for (int i = 0; i < t; i++) {
            // Read the operation type and arguments
            String[] op = scanner.next().split("");

            // Allocate memory if the operation type is 'alloc'
            if (op[0].equals("alloc")) {
                int pos = 0;  // Initialize position counter
                for (int j = 0; j < m; j++) {
                    // Check if the position is available for allocation
                    if (alocuente[j] == 0) {
                        // If the position is available, allocate the memory block of the given size
                        pos++;
                        if (pos == Integer.parseInt(op[1])) {
                            // Set the allocated memory blocks to the given index
                            for (int k = j - Integer.parseInt(op[1]) + 1; k <= j; k++) {
                                alocuente[k] = 1;  // Mark as allocated
                            }
                            // Print the allocated index
                            System.out.println(1);  // Assuming index starts from 1
                            // Break the loop since we found the suitable position
                            break;
                        } else {
                            pos = 0;  // Reset the position counter for the next iteration
                        }
                    }
                }
                if (pos != Integer.parseInt(op[1])) {
                    // If no suitable position is found, print 'NULL'
                    System.out.println("NULL");
                }
            }

            // Erase memory if the operation type is 'erase'
            else if (op[0].equals("erase")) {
                int pos = Integer.parseInt(op[1]);
                // Check if the given index is valid and allocated
                if (pos <= 0 || pos > m || alocuente[pos - 1] == 0) {
                    // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                } else {
                    // If the index is valid and allocated, free the memory block
                    alocuente[pos - 1] = 0;  // Mark as freed
                }
            }

            // Defragment memory if the operation type is 'defragment'
            else if (op[0].equals("defragment")) {
                int cnt = 0;  // Initialize free block counter
                // Count the number of free blocks
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        cnt++;
                    }
                }
                // Create a new array with only allocated blocks
                int[] newAlocuente = new int[m - cnt];
                int index = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] != 0) {
                        newAlocuente[index++] = alocuente[j];
                    }
                }
                // Copy the new array back to the original array
                System.arraycopy(newAlocuente, 0, alocuente, 0, newAlocuente.length);
            }
        }
    }
}
