import java.util.*;
import java.io.*;

public class Main{
	static class Edge{
		int s,g,c;
		public Edge(int s,int g,int c){
			this.s=s;
			this.g=g;
			this.c=c;
		}
	}
	static class Graph{
		int vcnt,ecnt;
		Edge[] e;
		int[] id;
		public Graph(int vcnt,int ecnt){
			this.vcnt=vcnt;
			this.ecnt=ecnt;
			e=new Edge[ecnt];
			id=new int[vcnt+1];
		}
	}
	static int[] tyokkeitemp;
	static void tyokkeidfs(int s){
		for(int i=g.id[s];i<g.id[s+1];i++){
			if(tyokkeitemp[g.e[i].g]==0){
				tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c;
				tyokkeidfs(g.e[i].g);
			}
		}
	}
	static int tyokkei(){
		tyokkeitemp=new int[g.vcnt+10];
		tyokkeitemp[0]=1;
		tyokkeidfs(0);
		int M=0,Mi;
		for(int i=0;i<g.vcnt;i++){
			if(tyokkeitemp[i]>M){
				M=tyokkeitemp[i];
				Mi=i;
			}
		}
		for(int i=0;i<g.vcnt)tyokkeitemp[i]=0;
		tyokkeitemp[Mi]=1;
		tyokkeidfs(Mi);
		for(int i=0;i<g.vcnt)M=Math.max(M,tyokkeitemp[i]);
		return M-1;
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] line=br.readLine().split(" ");
		int n=Integer.parseInt(line[0]);
		g=new Graph(n,2*n-2);
		for(int i=0;i<n-1;i++){
			line=br.readLine().split(" ");
			int s=Integer.parseInt(line[0]);
			int g=Integer.parseInt(line[1]);
			int c=Integer.parseInt(line[2]);
			g.e[2*i]=new Edge(s,g,c);
			g.e[2*i+1]=new Edge(g,s,c);
		}
		Arrays.sort(g.e,new Comparator<Edge>(){
			public int compare(Edge a,Edge b){
				if(a.s<b.s)return -1;
				if(a.s>b.s)return 1;
				if(a.g<b.g)return -1;
				return 1;
			}
		});
		int p=0;
		for(int i=0;i<n;i++){
			while(p<g.ecnt&&g.e[p].s<i)p++;
			g.id[i]=p;
		}
		g.id[n]=g.ecnt;//番兵
		System.out.println(tyokkei());
	}
}

