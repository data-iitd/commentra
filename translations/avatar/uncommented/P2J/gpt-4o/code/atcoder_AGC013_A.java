import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        String[] input = br.readLine().trim().split(" ");
        List<Integer> A = new ArrayList<>();
        
        for (String s : input) {
            A.add(Integer.parseInt(s));
        }
        
        // Remove duplicates while maintaining order
        List<Integer> uniqueA = new ArrayList<>();
        Set<Integer> seen = new HashSet<>();
        for (int num : A) {
            if (!seen.contains(num)) {
                seen.add(num);
                uniqueA.add(num);
            }
        }
        
        N = uniqueA.size();
        int ans = 0;
        for (int i = 1; i < N - 1; ) {
            if ((uniqueA.get(i - 1) < uniqueA.get(i) && uniqueA.get(i) > uniqueA.get(i + 1)) ||
                (uniqueA.get(i - 1) > uniqueA.get(i) && uniqueA.get(i) < uniqueA.get(i + 1))) {
                ans++;
                i += 2; // Skip the next element as well
            } else {
                i++;
            }
        }
        
        System.out.println(ans + 1);
    }
}
//<END-OF-CODE>
