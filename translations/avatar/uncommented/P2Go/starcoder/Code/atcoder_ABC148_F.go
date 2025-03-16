package main
import "fmt"
func main( ) {
	var n, ta, ao int
	fmt.Scan( &n, &ta, &ao )
	g := make( [][]int, n )
	for i := 0; i < n - 1; i++ {
		var a, b int
		fmt.Scan( &a, &b )
		g[a-1] = append( g[a-1], b-1 )
		g[b-1] = append( g[b-1], a-1 )
	}
	ta_dist := make( []int, n )
	ta_dist[ta-1] = 0
	ao_dist := make( []int, n )
	ao_dist[ao-1] = 0
	func ta_dfs( node int ) {
		for _, v := range g[node] {
			if ta_dist[v]!= 0 {
				continue
			}
			ta_dist[v] = ta_dist[node] + 1
			ta_dfs( v )
		}
	}
	func ao_dfs( node int ) {
		for _, v := range g[node] {
			if ao_dist[v]!= 0 {
				continue
			}
			ao_dist[v] = ao_dist[node] + 1
			ao_dfs( v )
		}
	}
	ao_dfs( ao-1 )
	ta_dfs( ta-1 )
	res := 0
	for i := 0; i < n; i++ {
		if ta_dist[i] > ao_dist[i] {
			continue
		}
		res = max( res, ao_dist[i] )
	}
	fmt.Println( res-1 )
}
