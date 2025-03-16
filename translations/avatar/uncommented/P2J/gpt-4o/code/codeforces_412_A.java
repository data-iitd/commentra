import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and k
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Read the string v
        String v = scanner.nextLine();
        
        String[] directions = {"LEFT", "RIGHT"};
        boolean f = (k - 1) < (n - k);
        int m = Math.min(k - 1, n - k);
        List<String> a = new ArrayList<>();
        
        // Append directions based on the minimum value
        for (int i = 0; i < m; i++) {
            a.add(directions[!f ? 1 : 0]); // LEFT if f is false, RIGHT if f is true
        }
        
        // Append print commands and directions
        for (int i = v.length() - 1; i >= 0; i--) {
            if (f) {
                a.add("PRINT " + v.charAt(i));
                a.add(directions[1]); // RIGHT
            } else {
                a.add("PRINT " + v.charAt(i));
                a.add(directions[0]); // LEFT
            }
        }
        
        // Print the result
        for (int i = 0; i < a.size() - 1; i++) {
            System.out.println(a.get(i));
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
