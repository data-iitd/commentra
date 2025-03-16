
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n,A[][] = new int[N][N];
        int color[] = new int[N],d[] = new int[N],f[] = new int[N];
        int TT;

        n = in.nextInt();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++){
            int u = in.nextInt();
            int k = in.nextInt();
            u--;
            for(int j=0;j<k;j++){
                int v = in.nextInt();
                v--;
                A[u][v] = 1;
            }
        }

        aaaaa();

        return;
    }


    static void aaaaa() {
        int u,i;

        for(i=0;i<n;i++){
            color[i] = SHIRO;
        }
            
        TT = 0;

        for(u=0;u<n;u++){
            if(color[u] == SHIRO){
                bbbbb(u);
            }
        }

        for(i = 0;i<n;i++){
            System.out.println(i+1+" "+d[i]+" "+f[i]);
        }
    }

    static void bbbbb(int k) {
        int v;
        color[k] = HAI;
        TT++;
        d[k] = TT;
        for(v=0;v<n;v++){
            if(A[k][v] == 0) continue;
            if(color[v] == SHIRO){
                bbbbb(v);
            }
        }
        color[k] = KURO;
        f[k] = ++TT;
    }

}

