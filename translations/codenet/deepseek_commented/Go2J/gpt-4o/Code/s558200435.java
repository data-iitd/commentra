import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // 1. Reading the input number of elements (n)
        int n = scanner.nextInt();
        
        // 2. Reading the elements into an ArrayList (a)
        ArrayList<Integer> a = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        
        // 3. Creating an ArrayList (b) to store the longest increasing subsequence
        ArrayList<Integer> b = new ArrayList<>();
        
        // 4. Finding the longest increasing subsequence
        for (int v : a) {
            int x = Collections.binarySearch(b, v);
            if (x < 0) {
                x = -(x + 1); // Convert to the insertion point
            }
            if (x == b.size()) {
                b.add(v);
            } else {
                b.set(x, v);
            }
        }
        
        // 5. Outputting the length of the longest increasing subsequence
        System.out.println(b.size());
        
        scanner.close();
    }
}
// <END-OF-CODE>
