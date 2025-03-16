
package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

const size = 1000000

// Initialize reader
var reader = bufio.NewReaderSize(os.Stdin, size)

// Function to read a single line from the standard input
func NextLine() string {
  var line, buffer []byte
  var isPrefix bool = true
  var err error
  for ;isPrefix; {
    line, isPrefix, err = reader.ReadLine()
    if err != nil {
      panic(err)
    }
    buffer = append(buffer, line...)
  }
  return string(buffer)
}

// Function to read two integers from a single line
func NextInts() (int, int) {
  var x, y int
  var s []string = strings.Split(NextLine(), " ")
  x, _ = strconv.Atoi(s[0])
  y, _ = strconv.Atoi(s[1])
  return x, y
}

// Function to read an array of integers from a single line
func NextIntArray() []int {
  var s []string = strings.Split(NextLine(), " ")
  var a []int = make([]int, len(s))
  for i := 0; i < len(s); i++ {
    a[i], _ = strconv.Atoi(s[i])
    a[i]-- // Decrease each index by 1 for some reason
  }
  return a
}

// Initialize arrays for parent and rank
var par, rank []int

// Function to initialize arrays
func initialize(n int) {
  par = make([]int, n)
  rank = make([]int, n)
  // Set all elements as their own parent initially
  for i := 0; i < n; i++ {
    par[i] = i
  }
}

// Main function
func main() {
  // Read number of nodes and edges
  var n, m int = NextInts()
  // Read array of edges
  var p []int = NextIntArray()
  // Initialize arrays
  initialize(n)
  // Process each edge by uniting their parents
  for i := 0; i < m; i++ {
    x, y := NextInts()
    unite(x-1, y-1)
  }
  // Count the number of disconnected components
  var s int
  for i := 0; i < n; i++ {
    if same(i, p[i]) {
      s++
    }
  }
  // Print the result
  fmt.Println(s)
}

// Function to find the root of a node
func root(i int) int {
  // If the node is its own parent, return it
  if par[i] == i {
    return i
  }
  // Recursively find the root of the parent
  par[i] = root(par[i])
  // Return the new root
  return par[i]
}

// Function to check if two nodes have the same parent
func same(i, j int) bool {
  // Find the root of both nodes
  return root(i) == root(j)
}

// Function to unite two nodes
func unite(i, j int) {
  // Find the roots of both nodes
  i = root(i)
  j = root(j)
  // If they already have the same parent, return
  if i == j {
    return
  }
  // Make the smaller rank node a child of the larger rank node
  if rank[i] < rank[j] {
    par[i] = j
  } else {
    par[j] = i
    // If they have the same rank, increase the rank of the node with the smaller index
    if rank[i] == rank[j] {
      rank[i]++
    }
  }
}
