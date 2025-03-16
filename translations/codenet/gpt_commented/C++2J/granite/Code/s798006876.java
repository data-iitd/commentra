
import java.util.Scanner;

public class s798006876{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m, nmi, nma;

        // Read inputs m, nmi, and nma until nmi is not equal to 0
        while (scanner.hasNextInt()) {
            m = scanner.nextInt();
            nmi = scanner.nextInt();
            nma = scanner.nextInt();

            if (nmi == 0) {
                break;
            }

            // Array to hold input data
            int[] data = new int[m];

            // Read m elements into the data array
            for (int i = 0; i < m; i++) {
                data[i] = scanner.nextInt();
            }

            // Initialize variables to track the maximum difference and the answer index
            int ma = 0; // Maximum difference found
            int ans = 0; // Index of the element that gives the maximum difference

            // Loop through the specified range from nmi-1 to nma-1
            for (int i = nmi - 1; i < nma - 1; i++) {
                // Check if the current difference is greater than the maximum found so far
                if (ma <= data[i] - data[i + 1]) {
                    ans = i + 1; // Update the answer index
                    ma = data[i] - data[i + 1]; // Update the maximum difference
                }
            }

            // Output the index of the element that produced the maximum difference
            System.out.println(ans);
        }
    }
}
