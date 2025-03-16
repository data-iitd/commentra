import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        while(sc.hasNextInt()) {
            n = sc.nextInt();
            if(n == 0) break;
            int m;
            P[] v = new P[n];
            for(int i = 0; i < n; i++) {
                v[i] = new P(0, "");
            }
            for(int i = 0; i < n; i++) {
                String s = sc.next();
                m = sc.nextInt();
                for(int j = 0; j < m; j++) {
                    int a = sc.nextInt();
                    v[i].first += n - d[a].size();
                    for(int k = 0; k < d[a].size(); k++) {
                        v[d[a].get(k)].first--;
                    }
                    d[a].add(i);
                }
                v[i].second = s;
            }
            Arrays.sort(v);
            System.out.println(v[0].first + " " + v[0].second);
        }
    }
}
