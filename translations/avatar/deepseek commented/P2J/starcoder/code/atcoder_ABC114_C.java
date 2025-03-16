
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        System.out.println(aaa(N));
    }
    
    public static int aaa(int n) {
        if (n > N) return 0;
        int ans = 1;
        if (n % 10 == 7 || n % 10 == 5 || n % 10 == 3) ans = 1;
        else ans = 0;
        for (int i = 0; i < 3; i++) {
            ans += aaa(n + i);
        }
        return ans;
    }
}

