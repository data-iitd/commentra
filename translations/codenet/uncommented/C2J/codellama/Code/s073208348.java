#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))


//辺の情報を個別に持つタイプ
class E{
	public int s,g,c;
	public E(int s,int g,int c){
		this.s=s;
		this.g=g;
		this.c=c;
	}
}

class G{
	public int vcnt,ecnt;
	public E[] e;//適宜変える
	public int[] id;//適宜変える
	public G(int vcnt,int ecnt){
		this.vcnt=vcnt;
		this.ecnt=ecnt;
		e=new E[200010];//適宜変える
		id=new int[100010];//適宜変える
	}
}

int esort(E a,E b){
	if(a.s<b.s)return -1;
	if(a.s>b.s)return  1;
	if(a.g<b.g)return -1;
	return 1;
}

G g;
void readgraph(){
	//適宜変える
	int n;
	scanf("%d",&n);
	rep(i,0,n-1){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		g.e[2*i]=new E(x,y,c);
		g.e[2*i+1]=new E(y,x,c);
	}
	g.vcnt=n;
	g.ecnt=2*n-2;
	Arrays.sort(g.e,0,g.ecnt,new Comparator<E>(){
		public int compare(E a,E b){
			return esort(a,b);
		}
	});
//	qsort(g.e,g.ecnt,sizeof(E),csort);

	int p=0;
	rep(i,0,g.vcnt){
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//番兵
}


//木の直径を求める2回dfs
//*
int[]tyokkeitemp;
void tyokkeidfs(int s){
	for(int i=g.id[s];i<g.id[s+1];i++){
		if(tyokkeitemp[g.e[i].g]==0){
			tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c;
			tyokkeidfs(g.e[i].g);
		}
	}
}
int tyokkei(){
	tyokkeitemp=new int[g.vcnt+10];
	tyokkeitemp[0]=1;
	tyokkeidfs(0);
	int M=0,Mi;
	rep(i,0,g.vcnt){
		if(tyokkeitemp[i]>M){
			M=tyokkeitemp[i];
			Mi=i;
		}
	}
	rep(i,0,g.vcnt)tyokkeitemp[i]=0;
	tyokkeitemp[Mi]=1;
	tyokkeidfs(Mi);
	rep(i,0,g.vcnt)M=max(M,tyokkeitemp[i]);
	return M-1;
}
//*/

int main(){
	readgraph();
	System.out.println(tyokkei());
}

