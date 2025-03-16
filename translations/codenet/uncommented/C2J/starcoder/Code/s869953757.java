
import java.util.*;

public class Main {
  public static void main(String[] args) {
    int n;
    int T[][] = new int[M][M];
    int color[] = new int[M];
    int d[] = new int[M];
    int Q[] = new int[M];
    int head=0,tail=0;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	T[i][j] = 0;
      }
    }

    for(int i=0; i<n; i++){
      int u,k;
      u = sc.nextInt();
      u--;
      k = sc.nextInt();
      for(int j=0; j<k; j++){
	int v;
	v = sc.nextInt();
	v--;
	T[u][v] = 1;
      }
    }

    bfs(0);

    for(int i=0; i<n; i++){
      if(d[i] == 1000000) d[i] = -1;
      System.out.println(i+1+" "+d[i]);
    }

  }

  public static void bfs(int s){
    int i,u,v;
    
    for(i=0; i<n; i++){
      color[i] = whi;
      d[i] = 1000000;
    }

    color[s] = gra;
    d[s] = 0;
    enqueue(s);

    while(head!= tail){
      u = dequeue();
      for(v=0; v<n; v++){
	if(T[u][v] == 1 && color[v] == whi){
	  color[v] = gra;
	  d[v] = d[u]+1;
	  enqueue(v);
	}
      }
      color[u] = bla;
    }
    
  }

  public static void enqueue(int x){
    Q[tail] = x;
    tail = (tail+1)%M;
  }

  public static int dequeue(void){
    int x;
    x = Q[head];
    head = (head+1)%M;
    return x;
  }

  public static final int M = 100;
  public static final int whi = 0;
  public static final int gra = 1;
  public static final int bla = 2;
}

