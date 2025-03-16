import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] G = new int[N];
        for(int i = 0; i < N; i++){
            G[i] = sc.nextInt();
        }
        int[] grundy = new int[N];
        boolean[] used = new boolean[N];
        for(int i = 0; i < N; i++){
            if(!used[i]){
                dfs(G, grundy, used, i);
            }
        }
        if(grundy[0]!= 0){
            System.out.println("Alice");
        }else{
            System.out.println("Bob");
        }
    }

    public static void dfs(int[] G, int[] grundy, boolean[] used, int v){
        used[v] = true;
        grundy[v] = 0;
        for(int i = 0; i < G[v]; i++){
            if(!used[i]){
                dfs(G, grundy, used, i);
                grundy[v] ^= (grundy[i]+1);
            }
        }
    }
}

