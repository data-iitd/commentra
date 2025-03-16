import java.util.*;

public class Main {
  public static void main(String[] args) {
    int time,n,g[][] = new int[MAX][MAX] = {0};
    int d[] = new int[MAX],f[] = new int[MAX],color[] = new int[MAX] = {WHITE};
    int i,j,x,y,z;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    for(i=0;i<n;i++){
      x = sc.nextInt();
      y = sc.nextInt();
      for(j=0;j<y;j++){
        z = sc.nextInt();
        g[x-1][z-1] = 1;
      }
    }

    time = 0;

    for(i=0;i<n;i++)
      if(color[i] == WHITE)
        visit(i);

    for(i=0;i<n;i++)
      System.out.printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  public static void visit(int u){
    int i;

    color[u] = GRAY;
    d[u] = ++time;

    for(i=0;i<n;i++){
      if(g[u][i] == 0)
        continue;
      if(color[i] ==WHITE)
        visit(i);
    }

    color[u] = BLACK;
    f[u] = ++time;
  }
}

