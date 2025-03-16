import java.util.*;
import java.io.*;
import java.math.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine().trim());
        int[] A = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        List<Integer> uniqueA = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (i == 0 || A[i] != A[i - 1]) {
                uniqueA.add(A[i]);
            }
        }
        
        N = uniqueA.size();
        int ans = 0;
        
        for (int i = 1; i < N - 1; i++) {
            if ((uniqueA.get(i - 1) < uniqueA.get(i) && uniqueA.get(i) > uniqueA.get(i + 1)) || 
                (uniqueA.get(i - 1) > uniqueA.get(i) && uniqueA.get(i) < uniqueA.get(i + 1))) {
                ans++;
            }
        }
        
        pw.println(ans + 1);
        pw.flush();
    }
}
