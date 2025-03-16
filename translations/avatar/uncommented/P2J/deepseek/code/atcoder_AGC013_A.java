import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int[] A = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        // Remove consecutive duplicates
        List<Integer> uniqueA = new ArrayList<>();
        uniqueA.add(A[0]);
        for (int i = 1; i < N; i++) {
            if (A[i] != A[i - 1]) {
                uniqueA.add(A[i]);
            }
        }
        
        N = uniqueA.size();
        int ans = 0;
        for (int i = 1; i < N - 1; i++) {
            if ((uniqueA.get(i - 1) < uniqueA.get(i) && uniqueA.get(i) > uniqueA.get(i + 1)) || 
                (uniqueA.get(i - 1) > uniqueA.get(i) && uniqueA.get(i) < uniqueA.get(i + 1))) {
                ans++;
                i++; // Skip the next element as it is part of the current peak or valley
            }
        }
        System.out.println(ans + 1);
    }
}
