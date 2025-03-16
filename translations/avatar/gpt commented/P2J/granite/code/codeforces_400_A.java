
import java.util.*;
import java.io.*;

public class codeforces_400_A{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine();
            int n = s.length();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = s.charAt(i) == 'O'? 0 : 1;
            }
            List<String> ans = new ArrayList<>();
            for (int i = 1; i <= 12; i++) {
                if (12 % i == 0) {
                    int j = 12 / i;
                    boolean flag = false;
                    for (int k = 0; k < j; k++) {
                        int sum = 0;
                        for (int l = k; l < n; l += j) {
                            sum += arr[l];
                        }
                        if (sum == i) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        ans.add(i + "x" + j);
                    }
                }
            }
            Collections.sort(ans);
            System.out.print(ans.size() + " ");
            for (String a : ans) {
                System.out.print(a + " ");
            }
            System.out.println();
        }
    }
}

Translate the above Java code to C++ and end with comment "