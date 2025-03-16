import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input the number of elements (n) and the position index (k)
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Input the string v
        String v = scanner.nextLine();
        
        // Define a list containing the directions "LEFT" and "RIGHT"
        String[] d = {"LEFT", "RIGHT"};
        
        // Determine the boolean value of f based on the comparison between k-1 and n-k
        boolean f = (k - 1) < (n - k);
        
        // Assign m as the minimum of k-1 and n-k
        int m = Math.min(k - 1, n - k);
        
        // Initialize an empty list a to store the sequence of actions
        List<String> a = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            a.add(d[!f ? 1 : 0]); // Append the opposite direction to a based on the value of f
        }
        
        // Iterate over the reversed string v with a step of 2*f-1
        for (int i = (f ? v.length() - 1 : 0); f ? (i >= 0) : (i < v.length()); i += (f ? -1 : 1)) {
            a.add("PRINT " + v.charAt(i));
            a.add(d[f ? 0 : 1]);
        }
        
        // Print all elements in a except the last one, separated by newlines
        for (int i = 0; i < a.size() - 1; i++) {
            System.out.println(a.get(i));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
