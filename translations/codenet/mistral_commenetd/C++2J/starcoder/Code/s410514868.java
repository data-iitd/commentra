
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String s = sc.next();
        int L = s.charAt(0);
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(L == s.charAt(i)){
                cnt++;
            }
            else {
                ans += cnt;
                ans2++;
                cnt = 0;
                L = s.charAt(i);
            }
        }
        ans += cnt;
        ans2++;
        System.out.println(ans + Math.min(2 * k, ans2 - 1));
    }
}

