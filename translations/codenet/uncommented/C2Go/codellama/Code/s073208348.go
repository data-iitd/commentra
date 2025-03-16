#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))


//辺の情報を個別に持つタイプ
type E struct{s,g,c int}
type G struct{
	vcnt,ecnt int
	e [200010]E//適宜変える
	id [100010]int//適宜変える
}

func esort(a,b unsafe.Pointer)int{
	p,q := (*E)(a),(*E)(b)
	if p.s<q.s{return -1}
	if p.s>q.s{return  1}
	if p.g<q.g{return -1}
	return 1
}

var g G
func readgraph(){
	//適宜変える
	var n int
	fmt.Scan(&n)
	rep(i,0,n-1){
		var x,y,c int
		fmt.Scan(&x,&y,&c)
		g.e[2*i].s=x
		g.e[2*i].g=y
		g.e[2*i].c=c
		g.e[2*i+1].s=y
		g.e[2*i+1].g=x
		g.e[2*i+1].c=c
	}
	g.vcnt=n
	g.ecnt=2*n-2
	sort.Slice(g.e,esort)
//	qsort(g.e,g.ecnt,sizeof(E),csort);

	p:=0
	rep(i,0,g.vcnt){
		for p<g.ecnt&&g.e[p].s<i{p++}
		g.id[i]=p
	}
	g.id[g.vcnt]=g.ecnt//番兵
}


//木の直径を求める2回dfs
//*
var tyokkeitemp []int
func tyokkeidfs(s int){
	for i:=g.id[s];i<g.id[s+1];i++{
		if tyokkeitemp[g.e[i].g]==0{
			tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c
			tyokkeidfs(g.e[i].g)
		}
	}
}
func tyokkei()int{
	tyokkeitemp=make([]int,g.vcnt+10)
	tyokkeitemp[0]=1
	tyokkeidfs(0)
	M:=0
	Mi:=0
	rep(i,0,g.vcnt){
		if tyokkeitemp[i]>M{
			M=tyokkeitemp[i]
			Mi=i
		}
	}
	rep(i,0,g.vcnt)tyokkeitemp[i]=0
	tyokkeitemp[Mi]=1
	tyokkeidfs(Mi)
	rep(i,0,g.vcnt)M=max(M,tyokkeitemp[i])
	return M-1
}
//*/

func main(){
	readgraph()
	fmt.Println(tyokkei())
}

