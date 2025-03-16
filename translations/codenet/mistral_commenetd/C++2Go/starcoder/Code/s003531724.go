<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"

// Define a structure to represent an edge in the graph
type edge struct {
    to, pre, c int
}
var e [1000010]edge
var u [1000010]int
var l int

// Define some variables and arrays for storing information about the graph
var n, m int
var vis [1000010]bool
var cnt [3]int
var d [1000010]int
var T int

// Define a function to perform a depth-first search of the graph
func dfs(x, l int) {
    vis[x] = true
    cnt[l]++
    d[x] = l
    for i := u[x]; i; i = e[i].pre {
        T++
        if!vis[e[i].to] {
            dfs(e[i].to, (l + e[i].c) % 3)
        } else if (l + e[i].c) % 3!= d[e[i].to] {
            fmt.Println("NO")
            return
        }
    }
}

// Define the main function to read the input and compute the answer
func main() {
    // Read the input n and m, where n is the number of nodes and m is the number of edges
    fmt.Scanf("%d%d", &n, &m)
    // Initialize some variables and arrays
    var ans int64
    for i := 1; i <= n; i++ {
        if!vis[i] {
            T = 0
            for j := 0; j < 3; j++ {
                cnt[j] = 0
            }
            ok = true
            // Perform a depth-first search for the current unvisited node
            dfs(i, 0)
            s := cnt[0] + cnt[1] + cnt[2]
            // Compute the answer based on the information obtained during the depth-first search
            if!ok {
                ans += s * s
            } else {
                if cnt[0] && cnt[1] && cnt[2] {
                    ans += int64(cnt[0]) * int64(cnt[1]) + int64(cnt[1]) * int64(cnt[2]) + int64(cnt[2]) * int64(cnt[0])
                } else {
                    ans += int64(T / 2)
                }
            }
        }
    }
    // Output the answer and terminate the program
    fmt.Println(ans)
}

