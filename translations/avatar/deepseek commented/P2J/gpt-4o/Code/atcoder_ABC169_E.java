import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void resolve() {
        // Read the number of pairs
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        // Initialize lists to store the lower and higher values of each pair
        List<Integer> low = new ArrayList<>();
        List<Integer> high = new ArrayList<>();
        
        // Loop to read each pair and append values to the lists
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            low.add(a);
            high.add(b);
        }
        
        // Sort the lists
        Collections.sort(low);
        Collections.sort(high);
        
        // Check if the number of pairs is odd or even
        if (n % 2 != 0) {
            // If odd, calculate the range between the middle elements
            System.out.println(high.get((n + 1) / 2 - 1) - low.get((n + 1) / 2 - 1) + 1);
        } else {
            // If even, calculate the average of the middle elements and print the range
            double hh = (high.get(n / 2 - 1) + high.get(n / 2)) / 2.0;
            double ll = (low.get(n / 2 - 1) + low.get(n / 2)) / 2.0;
            System.out.println((int)((hh - ll) * 2) + 1);
        }
        
        scanner.close();
    }

    // Call the resolve function when the script is executed
    public static void main(String[] args) {
        resolve();
    }
}

// <END-OF-CODE>
