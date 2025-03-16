
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        // Read input values for n and x
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int[] A = new int[n];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        // Sort the array A
        Arrays.sort(A);

        // Initialize answer variable
        int ans = 0;
        // Count how many elements can be taken from A without exceeding x
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }
        // Adjust answer if all elements are taken and there is still remaining x
        if (ans == n && x > 0) {
            ans--;
        }
        // Print the final answer
        System.out.println(ans);
    }
}

