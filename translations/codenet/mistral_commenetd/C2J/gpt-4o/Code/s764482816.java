import java.util.Scanner;

public class Main {
    // Declare variables
    static int[] io = new int[5];

    // Read 5 integers from the user and store them in the array io
    static void readInput() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            io[i] = scanner.nextInt();
        }
    }

    public static void main(String[] args) {
        // Initialize variables
        readInput();

        // Perform bubble sort on the array io
        for (int i = 0; i < 5; i++) {
            // Initialize max and max_j with the first element of the array
            int max = io[i];
            int max_j = i;

            // Compare the current element with the remaining elements
            for (int j = i + 1; j < 5; j++) {
                // If the current max is smaller than the next element, update max and max_j
                if (max < io[j]) {
                    max = io[j];
                    max_j = j;
                }
            }

            // Swap the current element with the maximum element
            int buf = io[i];
            io[i] = io[max_j];
            io[max_j] = buf;

            // Print the sorted elements, except for the last one
            if (i < 4) {
                System.out.print(io[i] + " ");
            } else {
                System.out.println(io[i]);
            }
        }
    }
}

// <END-OF-CODE>
