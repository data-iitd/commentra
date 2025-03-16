import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] cnt = new int[1000001];
        for(int i = 0; i < n; ++i){
            int x = sc.nextInt();
            cnt[x]++;
        }
        int[] a = new int[n];
        int j = 0;
        for(int i = 0; i < cnt.length; ++i){
            if(cnt[i] > 0)
                a[j++] = cnt[i];
        }
        Arrays.sort(a);
        int ans = 0;
        for(int i = 0; i < a.length - k; ++i){
            ans += a[i];
        }
        System.out.println(ans);
    }
}

