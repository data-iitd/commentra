package main

import (
  "bufio"
  "os"
  "strconv"
  "fmt"
)

// Initialize buffered reader and writer for input and output
var reader = bufio.NewReaderSize(os.Stdin, 1000000)
var writer = bufio.NewWriter(os.Stdout)

// Function to read the next line from standard input
func NextLine() string {
  var line, buffer []byte
  var isPrefix bool = true
  var err error
  // Read lines until the entire line is received
  for isPrefix {
    line, isPrefix, err = reader.ReadLine()
    if err != nil { panic(err) }
    buffer = append(buffer, line...)
  }
  return string(buffer)
}

// Function to read the next integer from standard input
func NextInt() int {
  var n int
  n, _ = strconv.Atoi(NextLine())
  return n
}

// Function to write output to standard output
func Write(s interface{}) {
  fmt.Fprintln(writer, s)
}

// Function to flush the buffered writer to output
func Output() {
  _ = writer.Flush()
}

// Function to check if the graph is bipartite
func Bipartite(S *[]string) bool {
  N := len((*S)) // Get the number of nodes
  D := make([]int, N) // Distance array to store levels of nodes
  D[0] = 1 // Start with the first node at level 1
  Q := make([]int, N) // Queue for BFS
  ret := true // Variable to track if the graph is bipartite
  pos := 1 // Position in the queue

  // Perform BFS to check for bipartiteness
  for i := 0; i < N; i++ {
    if !ret { break } // Exit if already determined not bipartite
    q := Q[i] // Current node
    for j, s := range (*S)[q] {
      if s == '0' {
        continue // Skip if there is no edge
      }
      if D[j] == 0 {
        // Assign level to the adjacent node
        D[j] = D[q] + 1
        Q[pos] = j // Add to queue
        pos++
        continue
      }
      // Check if the adjacent node has the same level
      if D[j] % 2 == D[q] % 2 {
        ret = false // Not bipartite
        break
      }
    }
  }
  return ret // Return the result of bipartiteness check
}

// Function to perform the Floyd-Warshall algorithm to find the longest shortest path
func WarshallFloyd(S *[]string) int {
  N := len(*(S)) // Get the number of nodes
  G := make([][]int, N) // Initialize the graph matrix

  // Initialize the graph with distances
  for i := range G {
    G[i] = make([]int, N)
    for j := range G[i] {
      if i == j { continue } // Skip self-loops
      if (*S)[i][j] == '0' {
        G[i][j] = N // No edge, set to a large value
      } else {
        G[i][j] = 1 // Edge exists, set distance to 1
      }
    }
  }

  // Floyd-Warshall algorithm to find shortest paths
  for k := 0; k < N; k++ {
    for i := 0; i < N; i++ {
      for j := 0; j < N; j++ {
        if G[i][k] + G[k][j] < G[i][j] {
          G[i][j] = G[i][k] + G[k][j] // Update shortest path
        }
      }
    }
  }

  // Find the maximum distance in the graph
  ans := 0
  for i := 0; i < N; i++ {
    for j := 0; j < N; j++ {
      if ans < G[i][j] { ans = G[i][j] } // Update maximum distance
    }
  }
  return ans + 1 // Return the maximum distance found
}

// Main function to execute the program
func main() {
  N := NextInt() // Read the number of nodes
  S := make([]string, N) // Initialize the adjacency matrix
  for i := range S {
    S[i] = NextLine() // Read each line of the adjacency matrix
  }
  
  // Check if the graph is bipartite and process accordingly
  if !Bipartite(&S) {
    Write(-1) // Output -1 if not bipartite
  } else {
    Write(WarshallFloyd(&S)) // Output the longest shortest path if bipartite
  }
  
  Output() // Flush the output
}
