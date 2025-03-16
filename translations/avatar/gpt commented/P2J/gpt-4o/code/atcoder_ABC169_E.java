import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        resolve();
    }

    public static void resolve() {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of intervals
        int n = scanner.nextInt();
        
        // Initialize arrays to store the lower and upper bounds of the intervals
        int[] low = new int[n];
        int[] high = new int[n];
        
        // Read each interval and store the lower and upper bounds
        for (int i = 0; i < n; i++) {
            low[i] = scanner.nextInt();  // Append the lower bound to the low array
            high[i] = scanner.nextInt();  // Append the upper bound to the high array
        }
        
        // Sort the lower and upper bounds
        Arrays.sort(low);
        Arrays.sort(high);
        
        // Check if the number of intervals is odd
        if (n % 2 == 1) {
            // For odd number of intervals, calculate the range of the median interval
            System.out.println(high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
        } else {
            // For even number of intervals, calculate the average of the two middle values
            double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;  // Average of the two middle high values
            double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;    // Average of the two middle low values
            // Calculate the range and print the result
            System.out.println((int)((hh - ll) * 2) + 1);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
