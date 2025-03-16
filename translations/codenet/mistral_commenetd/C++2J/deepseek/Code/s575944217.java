import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices from the input
        int n = scanner.nextInt();

        // Initialize an answer list of size n
        List<Integer> ans = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            ans.add(0);
        }

        // Read the edges and increment the count of each vertex in the answer list
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt();
            a--; // Decrement the vertex index as it is 0-indexed
            ans.set(a, ans.get(a) + 1); // Increment the count of the vertex
        }

        // Print the answer list
        for (int i = 0; i < n; i++) {
            System.out.println(ans.get(i));
        }
    }
}
