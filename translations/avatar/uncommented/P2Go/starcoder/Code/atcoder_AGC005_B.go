package main
import "fmt"
func main() {
	n := 0
	fmt.Scan( &n )
	a := make( []int, n )
	for i := 0; i < n; i++ {
		fmt.Scan( &a[i] )
	}
	b := make( []int, n )
	for i := 0; i < n; i++ {
		b[a[i]-1] = i
	}
	c := 0
	for k := n-1; k >= 0; k-- {
		l, r := 1, 1
		if k > 0 && a[k-1] > a[k] {
			l += b[k-1]
			unite( k-1, k )
		}
		if k+1 < n && a[k+1] > a[k] {
			r += b[k+1]
			unite( k+1, k )
		}
		c += l*r*a[k]
	}
	fmt.Println( c )
}
func root( x int ) int {
	if par[x] == x {
		return x
	}
	par[x] = root( par[x] )
	return par[x]
}
func same( x, y int ) bool {
	return root( x ) == root( y )
}
func unite( x, y int ) {
	x, y = root( x ), root( y )
	if x!= y {
		if rank[x] < rank[y] {
			par[x] = y
			size[y] += size[x]
		} else {
			par[y] = x
			size[x] += size[y]
			if rank[x] == rank[y] {
				rank[x]++
			}
		}
	}
}
