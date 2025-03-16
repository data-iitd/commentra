import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int MAX_N = 1000; // Define the maximum size of the array
        int[] data = new int[MAX_N]; // Declare the array to store the data

        while (true) {
            int m = scanner.nextInt(); // Read the value of m
            int nmi = scanner.nextInt(); // Read the value of nmi
            int nma = scanner.nextInt(); // Read the value of nma
            if (nmi == 0) break; // Continue until nmi is 0

            for (int i = 0; i < m; i++) {
                data[i] = scanner.nextInt(); // Read m integers into the array data
            }

            int ma = 0; // Initialize the maximum difference to 0
            int ans = 0; // Initialize the answer index to 0
            for (int i = nmi - 1; i < nma; i++) { // Loop through the range from nmi-1 to nma-1
                if (ma <= data[i] - data[i + 1]) { // Check if the current difference is greater than the maximum difference found so far
                    ans = i + 1; // Update the answer index
                    ma = data[i] - data[i + 1]; // Update the maximum difference
                }
            }
            System.out.println(ans); // Print the answer index
        }
    }
}
