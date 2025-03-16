import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the grid (n: number of rows, m: number of columns)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        Set<Integer> differences = new HashSet<>();
        
        // For each of the n rows, read the string and find the index of 'S' and 'G'.
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            int indexS = s.indexOf('S');
            int indexG = s.indexOf('G');
            differences.add(indexS - indexG); // Calculate the difference and store it in the set
        }
        
        // Check if there is any negative difference in the set 'differences'.
        boolean hasNegative = differences.stream().anyMatch(a -> a < 0);
        if (hasNegative) {
            System.out.println(-1);
        } else {
            System.out.println(differences.size());
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
