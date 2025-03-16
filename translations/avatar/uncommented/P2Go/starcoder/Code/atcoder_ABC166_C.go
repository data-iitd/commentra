package main
import "fmt"
func main() {
	var n, m int
	fmt.Scan( &n, &m )
	p := make( []int, n )
	h := make( []int, n )
	hp := make( map[int]int )
	path := make( map[int][]int )
	for i := 0; i < n; i++ {
		p[i] = i + 1
	}
	for i := 0; i < n; i++ {
		fmt.Scan( &h[i] )
		hp[ p[i] ] = h[i]
	}
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan( &a, &b )
		path[a] = append( path[a], b )
		path[b] = append( path[b], a )
	}
	c := 0
	for i, v := range path {
		f := 0
		for j := range v {
			if hp[i] <= hp[v[j]] {
				f = 1
				break
			}
		}
		if f == 0 {
			c++
		}
	}
	fmt.Println( c )
}
