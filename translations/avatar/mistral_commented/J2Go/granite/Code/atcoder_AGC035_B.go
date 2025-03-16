

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main method where the program starts execution.
func main() {
    // Creating a new Scanner object to read input from the standard input stream.
    sc := bufio.NewScanner(os.Stdin)

    // Reading the number of nodes and edges from the input.
    sc.Scan()
    numNode, _ := strconv.Atoi(sc.Text())
    sc.Scan()
    numEdge, _ := strconv.Atoi(sc.Text())

    // Initializing the connect array to store the list of neighbors for each node.
    connect := make([][]int, numNode)
    for i := 0; i < numNode; i++ {
        connect[i] = make([]int, 0)
    }

    // Reading the edges and adding them to the connect array.
    for i := 0; i < numEdge; i++ {
        sc.Scan()
        line := strings.Split(sc.Text(), " ")
        a, _ := strconv.Atoi(line[0])
        b, _ := strconv.Atoi(line[1])
        connect[a-1] = append(connect[a-1], b-1)
        connect[b-1] = append(connect[b-1], a-1)
    }

    // Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
    if numEdge%2!= 0 {
        fmt.Println(-1)
        return
    }

    // Initializing the visited, odd, and print arrays and objects.
    visited := make([]int, numNode)
    odd := make([]bool, numNode)
    print := &strings.Builder{}

    // Calling the dfs method with the first node and -1 as the parent node.
    dfs(0, -1, connect, visited, odd, print)

    // Printing the output.
    fmt.Println(print)
}

// Static array to store the connectivity information for each node.
func dfs(crt int, parent int, connect [][]int, visited []int, odd []bool, print *strings.Builder) {
    // Marking the current node as visited.
    visited[crt] = 1

    // Iterating through the neighbors of the current node.
    for _, child := range connect[crt] {
        // Skipping the neighbor if it is the parent node or already visited.
        if child == parent || visited[child] == 1 {
            continue
        }

        // If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
        // Otherwise, we swap the components and continue the traversal.
        if visited[child] == 2 {
            print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
            odd[crt] =!odd[crt]
        } else {
            dfs(child, crt, connect, visited, odd, print)
            if odd[child] {
                print.WriteString(strconv.Itoa(child+1) + " " + strconv.Itoa(crt+1) + "\n")
                odd[child] =!odd[child]
            } else {
                print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
                odd[crt] =!odd[crt]
            }
        }
    }

    // Marking the current node as visited with component 2.
    visited[crt] = 2
}

These comments should provide a clear understanding of the logic behind each block of code in the given Go program.