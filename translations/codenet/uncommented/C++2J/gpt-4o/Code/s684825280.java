import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    private static final int SIZE = (int) (1e5 * 2) + 13;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        int[] cnt = new int[SIZE];
        ArrayList<Integer> a = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            cnt[x]++;
        }
        
        for (int i = 0; i < cnt.length; i++) {
            if (cnt[i] > 0) {
                a.add(cnt[i]);
            }
        }
        
        int ans = 0;
        Collections.sort(a);
        int m = a.size() - k;
        
        for (int i = 0; i < m; i++) {
            ans += a.get(i);
        }
        
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
