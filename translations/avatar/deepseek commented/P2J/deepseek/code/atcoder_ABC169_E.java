import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of pairs
        int n = scanner.nextInt();
        
        // Initialize arrays to store the lower and higher values of each pair
        int[] low = new int[n];
        int[] high = new int[n];
        
        // Loop to read each pair and store values in the arrays
        for (int i = 0; i < n; i++) {
            low[i] = scanner.nextInt();
            high[i] = scanner.nextInt();
        }
        
        // Sort the arrays
        Arrays.sort(low);
        Arrays.sort(high);
        
        // Check if the number of pairs is odd or even
        if (n % 2 == 1) {
            // If odd, calculate the range between the middle elements
            System.out.println(high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
        } else {
            // If even, calculate the average of the middle elements and print the range
            double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;
            double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;
            System.out.println(Math.round((hh - ll) * 2) + 1);
        }
    }
}
