package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

func main() {
  // Initialize input reader with a buffer size of 1,000,000 bytes
  input := Input{bufio.NewReaderSize(os.Stdin, 1000000)}
  
  // Read the number of elements and the array of integers from input
  n := input.NextInt()
  s := input.NextIntArray()
  
  // Create a boolean slice to track used indices
  u := make([]bool, n)
  
  // Initialize variables to store the maximum sum and a temporary sum
  var m, f int64
  
  // Iterate through possible values of c from 1 to n-2
  for c := 1; c < n-1; c++ {
    f = 0 // Reset the temporary sum for each c
    
    // Iterate to find pairs of indices based on the current value of c
    for k := 0; c < n-1-k*c; k++ {
      u[k*c] = true // Mark the current index as used
      
      // Break if the corresponding index is already used
      if u[n-1-k*c] { break }
      
      // Calculate the sum of the elements at the current indices
      f += s[n-1-k*c] + s[k*c]
      
      // Update the maximum sum if the current sum is greater
      if m < f { m = f }
    }
    
    // Reset the used indices for the next iteration of c
    for k := 0; k*c < n-1; k++ { u[k*c] = false }
  }
  
  // Print the maximum sum found
  fmt.Println(m)
}

// Input struct to handle reading from standard input
type Input struct {
  reader *bufio.Reader
}

// NextLine reads a full line from input
func (i *Input) NextLine() string {
  var buffer []byte
  for {
    line, isPrefix, err := i.reader.ReadLine()
    if err != nil { panic(err) } // Handle any read errors
    buffer = append(buffer, line...)
    if !isPrefix { break } // Break if the line is not a prefix
  }
  return string(buffer) // Return the complete line as a string
}

// NextInt reads an integer from input
func (i *Input) NextInt() int {
  n, _ := strconv.Atoi(i.NextLine()) // Convert the input line to an integer
  return n // Return the integer value
}

// NextIntArray reads a line of integers and returns them as a slice
func (i *Input) NextIntArray() []int64 {
  s := strings.Split(i.NextLine(), " ") // Split the line into string segments
  a := make([]int64, len(s)) // Create a slice to hold the integers
  for i := 0; i < len(s); i++ { 
    a[i], _ = strconv.ParseInt(s[i], 10, 64) // Parse each string segment to int64
  }
  return a // Return the slice of integers
}
