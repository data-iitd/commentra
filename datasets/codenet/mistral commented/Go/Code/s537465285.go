
package main

import (
  "bufio"
  "os"
  "strconv"
  "fmt"
)

// Initialize reader and writer
var reader = bufio.NewReaderSize(os.Stdin, 1000000)
var writer = bufio.NewWriter(os.Stdout)

// Function to read a single line from standard input
func NextLine() string {
  var line, buffer []byte
  var isPrefix bool = true
  var err error
  for isPrefix {
    line, isPrefix, err = reader.ReadLine()
    if err != nil { panic(err) }
    buffer = append(buffer, line...)
  }
  return string(buffer)
}

// Function to read an integer from standard input
func NextInt() int {
  var n int
  n, _ = strconv.Atoi(NextLine())
  return n
}

// Function to write a value to standard output
func Write(s interface{}) {
  fmt.Fprintln(writer, s)
}

// Function to flush the writer buffer
func Output() {
  _ = writer.Flush()
}

// Function to check if a given graph is bipartite
func Bipartite(S *[]string) bool {
  // Initialize number of vertices
  N := len((*S))

  // Initialize degree array
  D := make([]int, N)
  D[0] = 1

  // Initialize queue
  Q := make([]int, N)

  // Initialize result
  ret := true

  // Initialize position in queue
  pos := 1

  // Iterate over each vertex
  for i := 0; i < N; i++ {
    if !ret { break }

    // Get current vertex
    q := Q[i]

    // Iterate over each neighbor of the current vertex
    for j, s := range (*S)[q] {
      if s == '0' {
        continue
      }

      // If neighbor is not visited yet
      if D[j] == 0 {
        // Mark neighbor as visited
        D[j] = D[q] + 1

        // Add neighbor to queue
        Q[pos] = j
        pos++

        // Continue to next neighbor
        continue
      }

      // If degrees of current and neighbor are different
      if D[j] % 2 != D[q] % 2 {
        // Graph is not bipartite
        ret = false
        break
      }
    }
  }

  // Return result
  return ret
}

// Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
func WarshallFloyd(S *[]string) int {
  // Initialize number of vertices
  N := len(*(S))

  // Initialize adjacency matrix
  G := make([][]int, N)
  for i := range G {
    G[i] = make([]int, N)
    for j := range G[i] {
      if i == j { continue }
      if (*S)[i][j] == '0' {
        G[i][j] = N
      } else {
        G[i][j] = 1
      }
    }
  }

  // Iterate over all vertices k
  for k := 0; k < N; k++ {
    // Iterate over all vertices i
    for i := 0; i < N; i++ {
      // Iterate over all vertices j
      for j := 0; j < N; j++ {
        // Update shortest distance if found
        if G[i][k] + G[k][j] < G[i][j] {
          G[i][j] = G[i][k] + G[k][j]
        }
      }
    }
  }

  // Initialize answer as maximum distance
  ans := 0

  // Iterate over all vertices i
  for i := 0; i < N; i++ {
    // Iterate over all vertices j
    for j := 0; j < N; j++ {
      // Update answer if found
      if ans < G[i][j] { ans = G[i][j] }
    }
  }

  // Return answer plus one
  return ans + 1
}

// Main function
func main() {
  // Read number of vertices
  N := NextInt()

  // Initialize graph
  S := make([]string, N)
  for i := range S {
    S[i] = NextLine()
  }

  // Check if graph is bipartite
  if !Bipartite(&S) {
    // Write -1 if graph is not bipartite
    Write(-1)
  } else {
    // Write shortest distance between all pairs of vertices
    Write(WarshallFloyd(&S))
  }

  // Flush writer buffer
  Output()
}

