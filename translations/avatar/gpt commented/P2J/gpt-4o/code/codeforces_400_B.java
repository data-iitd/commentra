import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Create a HashSet to store the differences
        HashSet<Integer> differences = new HashSet<>();
        
        // Read n strings and calculate the difference in indices of 'S' and 'G'
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            int indexS = s.indexOf('S');
            int indexG = s.indexOf('G');
            differences.add(indexS - indexG);
        }
        
        // Check if any of the calculated differences are negative
        boolean hasNegative = differences.stream().anyMatch(a -> a < 0);
        
        // Print the result
        System.out.println(hasNegative ? -1 : differences.size());
        
        scanner.close();
    }
}
// <END-OF-CODE>
