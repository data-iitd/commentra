// Define a structure to represent an edge in the graph
type edge struct { to, pre, c int }
var e []edge
var u []int
var l int
func ins(a, b, c int) { e = append(e, edge{b, u[a], c}) u[a] = l; l++ }

// Define some variables and arrays for storing information about the graph
var n, m int
var vis []bool
var ok bool
var cnt []int64
var d []int
var T int

// Define a function to perform a depth-first search of the graph
func dfs(x, l int) {
    vis[x] = true
    cnt[l]++
    d[x] = l
    for i := u[x]; i > 0; i = e[i].pre {
        T++
        if !vis[v] {
            dfs(v, (l + ec) % 3)
        } else if (l + ec) % 3 != d[v] {
            ok = false
        }
    }
}

// Define the main function to read the input and compute the answer
func main() {
    // Read the input n and m, where n is the number of nodes and m is the number of edges
    fmt.Scan(&n, &m)
    // Initialize some variables and arrays
    var ans int64
    for i := 1; i <= n; i++ {
        if !vis[i] {
            T = 0
            for j := 0; j < 3; j++ {
                cnt[j] = 0
            }
            ok = true
            // Perform a depth-first search for the current unvisited node
            dfs(i, 0)
            s := cnt[0] + cnt[1] + cnt[2]
            // Compute the answer based on the information obtained during the depth-first search
            if !ok {
                ans += s * s
            } else {
                if cnt[0] && cnt[1] && cnt[2] {
                    ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
                } else {
                    ans += T / 2
                }
            }
        }
    }
    // Output the answer and terminate the program
    fmt.Println(ans)
}

