import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        
        List<Integer> a = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a.add(Integer.parseInt(st.nextToken()));
        }
        
        Collections.sort(a);
        
        int ans = 0;
        
        if (a.get(0) > x) {
            System.out.println(0);
            return;
        }
        
        for (int i : a) {
            if (i > x) {
                x = 0;
                break;
            }
            x -= i;
            ans += 1;
        }
        
        if (x != 0) {
            ans -= 1;
        }
        
        System.out.println(ans);
    }
}

