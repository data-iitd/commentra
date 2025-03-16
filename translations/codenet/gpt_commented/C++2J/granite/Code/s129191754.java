
import java.util.*;

public class s129191754{
    public static void main(String[] args) {
        // Synchronize input/output for faster performance
        Scanner scanner = new Scanner(System.in);
        PrintStream out = new PrintStream(System.out);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Initialize a list to store the elements and read them from input
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        
        // Sort the list to facilitate duplicate checking
        Collections.sort(a);
        
        // Check for duplicates in the sorted list
        for (int i = 0; i < n - 1; i++) {
            if (a.get(i).equals(a.get(i + 1))) {
                // If a duplicate is found, print "NO" and exit
                out.println("NO");
                return;
            }
        }
        
        // If no duplicates are found, print "YES"
        out.println("YES");
        
        // End of the program
        return;
    }
}

