
import java.util.*;  // Importing necessary classes for input/output and data structures
import java.io.*;
import java.math.*;

public class atcoder_AGC013_A{
    public static void main(String[] args) throws IOException {
        // Initializing necessary input/output streams
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        // Reading number of elements
        int N = Integer.parseInt(br.readLine());
        // Reading list of elements
        String[] input = br.readLine().split(" ");
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(input[i]);
        }

        // Removing consecutive duplicates from list A
        List<Integer> AList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (i == 0 || A[i]!= A[i - 1]) {
                AList.add(A[i]);
            }
        }
        int[] A2 = new int[AList.size()];
        for (int i = 0; i < AList.size(); i++) {
            A2[i] = AList.get(i);
        }
        N = A2.length;

        // Initializing variables for main logic
        int i = 1;
        int ans = 0;

        // atcoder_AGC013_A logic to find peaks
        while (i < N - 1) {
            if ((A2[i - 1] < A2[i] && A2[i] > A2[i + 1]) || (A2[i - 1] > A2[i] && A2[i] < A2[i + 1])) {
                ans++;
                i++;  // Skip next element as it's already checked
            }
            i++;
        }

        // Output the total number of peaks found
        pw.println(ans + 1);

        // Closing input/output streams
        pw.close();
    }
}

Translate the above Java code to C++ and end with comment "