package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

// Define a constant size for the buffered reader
const size = 1000000

// Create a buffered reader with the specified size
var reader = bufio.NewReaderSize(os.Stdin, size)

// Function to read the next line from standard input
func NextLine() string {
  var line, buffer []byte
  var isPrefix bool = true
  var err error
  
  // Read lines until a complete line is received
  for isPrefix {
    line, isPrefix, err = reader.ReadLine()
    if err != nil {
      panic(err) // Handle any read errors
    }
    buffer = append(buffer, line...) // Append the line to the buffer
  }
  
  // Return the complete line as a string
  return string(buffer)
}

// Function to read two integers from the next line of input
func NextInts() (int, int) {
  var x, y int
  // Split the line into strings and convert to integers
  var s []string = strings.Split(NextLine(), " ")
  x, _ = strconv.Atoi(s[0]) // Convert the first string to an integer
  y, _ = strconv.Atoi(s[1]) // Convert the second string to an integer
  return x, y // Return the two integers
}

// Function to read an array of integers from the next line of input
func NextIntArray() []int {
  // Split the line into strings
  var s []string = strings.Split(NextLine(), " ")
  // Create an integer slice of the same length as the string slice
  var a []int = make([]int, len(s))
  
  // Convert each string to an integer and decrement by 1 for zero-based indexing
  for i := 0; i < len(s); i++ {
    a[i], _ = strconv.Atoi(s[i])
    a[i]-- // Decrement to convert to zero-based index
  }
  
  return a // Return the integer array
}

// Declare global variables for union-find structure
var par, rank []int

func main() {
  // Read the number of elements (n) and number of unions (m)
  var n, m int = NextInts()
  // Read the array of integers
  var p []int = NextIntArray()
  var x, y int
  
  // Initialize the union-find structure
  initialize(n)
  
  // Process each union operation
  for i := 0; i < m; i++ {
    x, y = NextInts() // Read the pair of integers for union
    unite(x-1, y-1)   // Unite the two elements (convert to zero-based index)
  }
  
  // Count the number of elements that are in the same set as their corresponding value in p
  var s int
  for i := 0; i < n; i++ {
    if same(i, p[i]) { // Check if the element is in the same set
      s++ // Increment the count
    }
  }
  
  // Print the result
  fmt.Println(s)
}

// Function to initialize the union-find structure
func initialize(n int) {
  par = make([]int, n) // Create parent array
  rank = make([]int, n) // Create rank array
  
  // Set each element's parent to itself
  for i := 0; i < n; i++ {
    par[i] = i
  }
}

// Function to find the root of the element with path compression
func root(i int) int {
  if par[i] == i {
    return i // Return the root if it is its own parent
  }
  par[i] = root(par[i]) // Path compression
  return par[i] // Return the root
}

// Function to check if two elements are in the same set
func same(i, j int) bool {
  return root(i) == root(j) // Check if their roots are the same
}

// Function to unite two elements into the same set
func unite(i, j int) {
  i = root(i) // Find the root of the first element
  j = root(j) // Find the root of the second element
  
  if i == j {
    return // If they are already in the same set, do nothing
  }
  
  // Union by rank
  if rank[i] < rank[j] {
    par[i] = j // Make j the parent of i
  } else {
    par[j] = i // Make i the parent of j
    if rank[i] == rank[j] {
      rank[i]++ // Increment rank if they were the same
    }
  }
}
