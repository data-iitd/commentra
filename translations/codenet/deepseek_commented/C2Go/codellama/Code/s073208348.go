#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

//辺の情報を個別に持つタイプ
type E struct {s,g,c int} // Define the structure for edges
type G struct {
	vcnt,ecnt int
	e [200010]E //適宜変える // Define the array of edges
	id [100010]int //適宜変える // Define the array of indices
} // Define the structure for the graph

func esort(a,b interface{})int{ // Define a function to sort edges
	p,q := a.(*E),b.(*E)
	if p.s<q.s {return -1} // Compare edges based on start vertex
	if p.s>q.s {return  1}
	if p.g<q.g {return -1} // Compare edges based on end vertex
	return 1
}

var g G // Define a global graph variable
func readgraph(){ // Define a function to read the graph
	//適宜変える
	var n int
	fmt.Scan(&n) // Read the number of vertices
	rep(i,0,n-1){ // Read each edge and store it in the graph structure
		var x,y,c int
		fmt.Scan(&x,&y,&c)
		g.e[2*i].s=x
		g.e[2*i].g=y
		g.e[2*i].c=c
		g.e[2*i+1].s=y
		g.e[2*i+1].g=x
		g.e[2*i+1].c=c
	}
	g.vcnt=n // Set the number of vertices
	g.ecnt=2*n-2 // Set the number of edges
	sort.Slice(g.e,func(i,j int)bool{return esort(&g.e[i],&g.e[j])<0}) // Sort the edges

	p:=0
	rep(i,0,g.vcnt){ // Populate the id array with the starting index of edges for each vertex
		for p<g.ecnt&&g.e[p].s<i {p++}
		g.id[i]=p
	}
	g.id[g.vcnt]=g.ecnt //番兵 // Set the sentinel value for the id array
}

//木の直径を求める2回dfs
//*
var tyokkeitemp []int // Define a temporary array for DFS
func tyokkeidfs(s int){ // Define a function to perform DFS and update distances
	for i:=g.id[s];i<g.id[s+1];i++{
		if tyokkeitemp[g.e[i].g]==0{
			tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c
			tyokkeidfs(g.e[i].g)
		}
	}
}
func tyokkei()int{ // Define a function to find the diameter of the tree
	tyokkeitemp=make([]int,g.vcnt+10) // Allocate memory for the temporary array
	tyokkeitemp[0]=1 // Start DFS from the root
	tyokkeidfs(0) // Perform DFS
	M,Mi:=0,0 // Initialize variables to find the maximum distance
	rep(i,0,g.vcnt){ // Find the vertex with the maximum distance from the root
		if tyokkeitemp[i]>M{
			M=tyokkeitemp[i]
			Mi=i
		}
	}
	rep(i,0,g.vcnt)tyokkeitemp[i]=0 // Reset the temporary array
	tyokkeitemp[Mi]=1 // Start DFS from the farthest vertex found
	tyokkeidfs(Mi) // Perform DFS
	rep(i,0,g.vcnt)M=max(M,tyokkeitemp[i]) // Find the maximum distance in the second DFS
	return M-1 // Return the diameter of the tree
}
//*/

func main(){ // Define the main function
	readgraph() // Read the graph
	fmt.Println(tyokkei()) // Print the diameter of the tree
}

