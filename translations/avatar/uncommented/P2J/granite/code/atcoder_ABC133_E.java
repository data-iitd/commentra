
import java.util.*;
import java.io.*;
class atcoder_ABC133_E {
    static int mod = 100000007;
    static int N, K;
    static ArrayList<Integer>[] graph;
    public static void main ( String[] args ) {
        Scanner sc = new Scanner ( System.in );
        N = sc.nextInt();
        K = sc.nextInt();
        graph = new ArrayList[N];
        for ( int i = 0; i < N; i++ ) {
            graph[i] = new ArrayList<Integer>();
        }
        for ( int i = 0; i < N - 1; i++ ) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            graph[a].add(b);
            graph[b].add(a);
        }
        System.out.println(dfs(0, -1, K));
    }
    static int dfs ( int fro, int to, int f ) {
        int caseNum = f;
        int colorNum = K - 1;
        if ( f == K ) {
            colorNum--;
        }
        for ( int u : graph[fro] ) {
            if ( u == to ) {
                continue;
            }
            int pat = dfs(u, fro, colorNum);
            if ( pat == 0 ) {
                caseNum = 0;
                break;
            }
            caseNum = (int)((long)caseNum * pat % mod);
            colorNum--;
        }
        return caseNum;
    }
}
