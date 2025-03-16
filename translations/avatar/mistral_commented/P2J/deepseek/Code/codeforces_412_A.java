import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements `n` and the number of queries `k` from the standard input
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read a single string `v` from the standard input
        String v = scanner.next();
        
        // Initialize a list `d` with two elements: "LEFT" and "RIGHT"
        String[] d = {"LEFT", "RIGHT"};
        
        // Determine the direction based on the difference between `k` and `n-k`
        boolean f = k - 1 < n - k;
        
        // Determine the number of elements to be appended to the list `a`
        int m = Math.min(k - 1, n - k);
        
        // Initialize an empty list `a`
        StringBuilder a = new StringBuilder();
        
        // Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
        for (int i = 0; i < m; i++) {
            a.append(d[f ? 1 : 0]).append("\n");
        }
        
        // Iterate through the string `v` with a step of 2 times the value of `f`
        for (int i = 0; i < v.length(); i += 2 * (f ? 1 : 0)) {
            // Append "PRINT <character>" and the corresponding direction to the list `a`
            a.append("PRINT ").append(v.charAt(i)).append("\n");
            a.append(d[f ? 0 : 1]).append("\n");
        }
        
        // Print all the elements of the list `a`, except the last one, separated by newline characters
        System.out.println(a.substring(0, a.length() - 1));
    }
}
