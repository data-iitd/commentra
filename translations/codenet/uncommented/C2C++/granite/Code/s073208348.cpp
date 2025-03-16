
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))


//辺の情報を個別に持つタイプ
typedef struct edge{ll s,g,c;}E;
typedef struct graph{
	int vcnt,ecnt;
	std::vector<E> e;//適宜変える
	std::vector<int> id;//適宜変える
}G;

bool esort(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return true;
	if((*p).s>(*q).s)return false;
	if((*p).g<(*q).g)return true;
	return false;
}

G g;
void readgraph(){
	//適宜変える
	ll n;
	std::cin>>n;
	rep(i,0,n-1){
		ll x,y,c;
		std::cin>>x>>y>>c;
		g.e.push_back({x,y,c});
		g.e.push_back({y,x,c});
	}
	g.vcnt=n;
	g.ecnt=2*n-2;
	std::sort(g.e.begin(),g.e.end(),esort);

	int p=0;
	rep(i,0,g.vcnt){
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id.push_back(p);
	}
	g.id.push_back(g.ecnt);//番兵
}


//木の直径を求める2回dfs
//*
int*tyokkeitemp;
void tyokkeidfs(ll s){
	for(int i=g.id[s];i<g.id[s+1];i++){
		if(tyokkeitemp[g.e[i].g]==0){
			tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c;
			tyokkeidfs(g.e[i].g);
		}
	}
}
int tyokkei(){
	tyokkeitemp=(int*)calloc(g.vcnt+10,sizeof(int));
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
	free(tyokkeitemp);
	return M-1;
}
//*/

int main(){
	readgraph();
	std::cout<<tyokkei()<<std::endl;
}
