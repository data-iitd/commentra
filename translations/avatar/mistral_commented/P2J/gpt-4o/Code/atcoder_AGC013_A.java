import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // Read the number of elements in the list A
        int N = Integer.parseInt(br.readLine().trim());

        // Read N integers into the list A
        int[] A = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        // Use a list to store unique elements
        List<Integer> uniqueA = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (i == 0 || A[i] != A[i - 1]) {
                uniqueA.add(A[i]);
            }
        }

        N = uniqueA.size(); // Update N to the size of uniqueA
        int ans = 0; // Initialize answer counter

        // Main logic
        for (int i = 1; i < N - 1; i++) {
            if ((uniqueA.get(i - 1) < uniqueA.get(i) && uniqueA.get(i) > uniqueA.get(i + 1)) ||
                (uniqueA.get(i - 1) > uniqueA.get(i) && uniqueA.get(i) < uniqueA.get(i + 1))) {
                ans++;
                i++; // Skip the next element
            }
        }

        System.out.println(ans + 1); // Print the final answer
    }
}
