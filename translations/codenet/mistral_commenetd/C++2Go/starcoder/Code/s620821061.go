
<<<<<<< HEAD

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

const MN = 520

type BitMatching struct {
	G [2*MN][]int
	match [2*MN]int
	used [2*MN]bool
}

func (bm *BitMatching) init() {
	for i := 0; i < 2*MN; i++ {
		bm.G[i] = bm.G[i][:0]
	}
}

func (bm *BitMatching) add(a, b int) {
	bm.G[a] = append(bm.G[a], b+MN)
	bm.G[b+MN] = append(bm.G[b+MN], a)
}

func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true
	for i := 0; i < len(bm.G[v]); i++ {
		u := bm.G[v][i]
		w := bm.match[u]
		if w < 0 || (!bm.used[w] && bm.dfs(w)) {
			bm.match[v] = u
			bm.match[u] = v
			return true
		}
	}
	return false
}

func (bm *BitMatching) exec() int {
	res := 0
	for i := 0; i < MN; i++ {
		bm.match[i] = -1
	}
	for v := 0; v < MN; v++ {
		if bm.match[v] < 0 {
			for i := 0; i < MN; i++ {
				bm.used[i] = false
			}
			if bm.dfs(v) {
				res++
			}
		}
	}
	return res
}

func main() {
	var n, m int
	for {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &m)
		if n == 0 {
			break
		}
		bm := &BitMatching{}
		bm.init()
		a := make([]int, n)
		b := make([]int, m)
		for i := 0; i < n; i++ {
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d ", &a[i])
		}
		for i := 0; i < m; i++ {
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d ", &b[i])
		}
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j])!= 1 {
					bm.add(i, j)
				}
			}
		}
		fmt.Println(bm.exec())
	}
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// 
=======
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

/**
 * @brief Constants for the maximum number of vertices in the graph.
 */
const MN = 520

/**
 * @brief BitMatching template structure for solving Bipartite Graph Matching problem.
 *
 * @tparam V The maximum number of vertices in the graph.
 */
type BitMatching[V int] struct {
    G [2*V][]int
    match [2*V]int
    used [2*V]bool
}

/**
 * @brief Initializes the graph data structures.
 */
func (bm *BitMatching[V]) init() {
    for i := 0; i < 2*V; i++ {
        bm.G[i] = make([]int, 0)
    }
}

/**
 * @brief Adds an edge between two vertices in the graph.
 *
 * @param a The source vertex.
 * @param b The destination vertex.
 */
func (bm *BitMatching[V]) add(a, b int) {
    bm.G[a] = append(bm.G[a], b+V)
    bm.G[b+V] = append(bm.G[b+V], a)
}

/**
 * @brief Performs Depth First Search (DFS) algorithm to find a matching between vertices.
 *
 * @param v The current vertex being processed.
 *
 * @return true if a matching is found, false otherwise.
 */
func (bm *BitMatching[V]) dfs(v int) bool {
    bm.used[v] = true

    for i := 0; i < len(bm.G[v]); i++ {
        u := bm.G[v][i]
        w := bm.match[u]

        if w < 0 || (!bm.used[w] && bm.dfs(w)) {
            bm.match[v] = u
            bm.match[u] = v
            return true
        }
    }
    return false
}

/**
 * @brief Executes the Bipartite Graph Matching algorithm.
 *
 * @return The number of matched vertices.
 */
func (bm *BitMatching[V]) exec() int {
    res := 0
    for v := 0; v < V; v++ {
        if bm.match[v] < 0 {
            bm.used = make([]bool, 2*V)
            bm.match = make([]int, 2*V)
            bm.match = append(bm.match, -1)
            bm.match = append(bm.match, -1)
            bm.used = append(bm.used, false)
            bm.used = append(bm.used, false)

            if bm.dfs(v) {
                res++
            }
        }
    }
    return res
}

/**
 * @brief Reads input data and performs the Bipartite Graph Matching algorithm.
 */
func main() {
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        n, m := 0, 0
        fmt.Sscanf(scanner.Text(), "%d %d", &n, &m)

        if n == 0 {
            break
        }

        bm := BitMatching[MN]{}
        bm.init()

        a := make([]int, n)
        b := make([]int, m)

        for i := 0; i < n; i++ {
            fmt.Sscanf(scanner.Text(), "%d", &a[i])
        }

        for i := 0; i < m; i++ {
            fmt.Sscanf(scanner.Text(), "%d", &b[i])
        }

        for i := 0; i < n; i++ {
            for j := 0; j < m; j++ {
                if gcd(a[i], b[j])!= 1 {
                    bm.add(i, j)
                }
            }
        }

        fmt.Println(bm.exec())
    }
}

func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a%b)
}

>>>>>>> 98c87cb78a (data updated)
