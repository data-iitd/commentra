
import java.util.*;

class s772335512 {
    static ArrayList<Integer>[] G;
    static boolean[] used;
    static int[] grundy;

    static void dfs(int v){
        used[v] = true;
        grundy[v] = 0;
        for(int i = 0; i < G[v].size(); i++){
            if(!used[G[v][i]]){
                dfs(G[v][i]);
                grundy[v] ^= (grundy[G[v][i]]+1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        G = new ArrayList[N];
        for(int i = 0; i < N; i++){
            G[i] = new ArrayList<>();
        }
        for(int i = 0; i < N-1; i++){
            int x = sc.nextInt()-1;
            int y = sc.nextInt()-1;
            G[x].add(y);
            G[y].add(x);
        }
        used = new boolean[N];
        grundy = new int[N];
        dfs(0);
        if(grundy[0]!= 0){
            System.out.println("Alice");
        }else{
            System.out.println("Bob");
        }
    }
}

