import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements `n` and the number of queries `k`
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Read a single string `v`
        String v = scanner.nextLine();
        
        // Initialize a list `d` with two elements: "LEFT" and "RIGHT"
        String[] d = {"LEFT", "RIGHT"};
        
        // Determine the direction based on the difference between `k` and `n-k`
        boolean f = (k - 1) < (n - k);
        
        // Determine the number of elements to be appended to the list `a`
        int m = Math.min(k - 1, n - k);
        
        // Initialize an empty list `a`
        List<String> a = new ArrayList<>();
        
        // Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
        for (int i = 0; i < m; i++) {
            a.add(d[!f ? 1 : 0]); // d[1] is "RIGHT", d[0] is "LEFT"
        }
        
        // Iterate through the string `v` with a step of 2 times the value of `f`
        for (int i = 0; i < v.length(); i += (2 * (f ? 1 : 0) + 1)) {
            // Append "PRINT <character>" and the corresponding direction to the list `a`
            a.add("PRINT " + v.charAt(i));
            a.add(d[f ? 1 : 0]); // d[1] is "RIGHT", d[0] is "LEFT"
        }
        
        // Print all the elements of the list `a`, except the last one, separated by newline characters
        for (int i = 0; i < a.size() - 1; i++) {
            System.out.println(a.get(i));
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
