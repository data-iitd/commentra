import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // Reading number of elements
        int N = Integer.parseInt(br.readLine().trim());
        // Reading list of elements
        st = new StringTokenizer(br.readLine());
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(Integer.parseInt(st.nextToken()));
        }

        // Removing consecutive duplicates from list A
        List<Integer> uniqueA = new ArrayList<>();
        uniqueA.add(A.get(0));
        for (int i = 1; i < A.size(); i++) {
            if (!A.get(i).equals(A.get(i - 1))) {
                uniqueA.add(A.get(i));
            }
        }
        A = uniqueA;
        N = A.size();

        // Initializing variables for main logic
        int i = 1;
        int ans = 0;

        // Main logic to find peaks
        while (i < N - 1) {
            if ((A.get(i - 1) < A.get(i) && A.get(i) > A.get(i + 1)) || 
                (A.get(i - 1) > A.get(i) && A.get(i) < A.get(i + 1))) {
                ans++;
                i++;  // Skip next element as it's already checked
            }
            i++;
        }

        // Output the total number of peaks found
        System.out.println(ans + 1);
    }
}

// <END-OF-CODE>
