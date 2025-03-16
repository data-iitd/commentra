import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Initialize an empty set
        HashSet<Integer> c = new HashSet<>();
        
        // Populate set c with differences between indices of 'S' and 'G' in each string
        for (String s : scanner.nextLine().split(" ")) {
            // Find the indices of 'S' and 'G' in the current string
            int index_S = s.indexOf('S');
            int index_G = s.indexOf('G');
            
            // Calculate the difference and add it to the set
            int difference = index_S - index_G;
            c.add(difference);
        }
        
        // Check if there is any negative number in set c and print accordingly
        boolean hasNegative = c.stream().anyMatch(a -> a < 0);
        System.out.println(hasNegative ? -1 : c.size());
        
        scanner.close();
    }
}
// <END-OF-CODE>
