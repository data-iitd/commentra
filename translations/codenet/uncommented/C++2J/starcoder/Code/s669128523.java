/*depth first search
not lie in stack
*/
import java.util.*;

public class Main{
	static final int N=100;
	static final int WHITE=0;
	static final int GRAY=1;
	static final int BLACK=2;

	int M[][];
	int n;
	int color[];
	int d[];
	int f[];
	int tt;

	void dfs_visit(int u){
		int v;
		color[u]=GRAY;
		d[u]=++tt;
		for(v=0;v<n;v++){
			if(M[u][v]==0)
				continue;
			if(color[v]==WHITE){
				dfs_visit(v);
			}
		}
		color[u]=BLACK;
		f[u]=++tt;
	}

	void dfs(){
		int u;
		color=new int[N];
		d=new int[N];
		f=new int[N];
		for(int i=0;i<n;i++){
			color[i]=WHITE;
		}
		tt=0;
		
		for(u=0;u<n;u++){
			if(color[u]==WHITE)
				dfs_visit(u);
		}
		
		for(int i=0;i<n;i++)
			System.out.println(i+1+" "+d[i]+" "+f[i]);
	}

	public static void main(String args[]){
		Main m=new Main();
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		m.M=new int[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				m.M[i][j]=0;
		}
		for(int i=0;i<n;i++){
			int u=sc.nextInt();
			int k=sc.nextInt();
			u--;
			for(int j=0;j<k;j++){
				int v=sc.nextInt();
				v--;
				m.M[u][v]=1;
			}
		}
		m.n=n;
		m.dfs();
	}
}

