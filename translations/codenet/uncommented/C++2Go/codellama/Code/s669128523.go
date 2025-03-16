/*depth first search
not lie in stack
*/
package main

import "fmt"

const N = 100
const WHITE = 0
const GRAY = 1
const BLACK = 2

var M [N][N]int
var n int
var color [N]int
var d [N]int
var f [N]int
var tt int

func dfs_visit(u int) {
	var v int
	color[u] = GRAY
	d[u] = tt + 1
	for v = 0; v < n; v++ {
		if M[u][v] == 0 {
			continue
		}
		if color[v] == WHITE {
			dfs_visit(v)
		}
	}
	color[u] = BLACK
	f[u] = tt + 1

}

func dfs() {
	var u int
	for i := 0; i < n; i++ {
		color[i] = WHITE
	}
	tt = 0

	for u = 0; u < n; u++ {
		if color[u] == WHITE {
			dfs_visit(u)
		}
	}

	for i := 0; i < n; i++ {
		fmt.Println(i+1, d[i], f[i])
	}
}

func main() {

	var k, u, v int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&u, &k)
		u--
		for j := 0; j < k; j++ {
			fmt.Scan(&v)
			v--
			M[u][v] = 1
		}
	}

	dfs()

}

