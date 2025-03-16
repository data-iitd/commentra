

import java.io.*;
import java.util.*;

public class s032857139{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int x = Integer.parseInt(input[1]);
        int[] A = new int[n];
        String[] input2 = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(input2[i]);
        }
        Arrays.sort(A);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }
        if (ans == n && x > 0) {
            ans--;
        }
        System.out.println(ans);
    }
}

