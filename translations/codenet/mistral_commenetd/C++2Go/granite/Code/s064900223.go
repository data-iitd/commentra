

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

func main() {
 reader := bufio.NewReader(os.Stdin)
 writer := bufio.NewWriter(os.Stdout)

 var n int
 var err error
 var p []int
 var ans int

 // Read the number of elements in the vector from the user
 fmt.Fscanf(reader, "%d\n", &n)

 // Allocate memory for the vector p of size n
 p = make([]int, n)

 // Read elements of the vector p from the user
 for i := 0; i < n; i++ {
 var s string
 s, err = reader.ReadString('\n')
 if err!= nil {
 panic(err)
 }
 p[i], err = strconv.Atoi(strings.TrimSpace(s))
 if err!= nil {
 panic(err)
 }
 }

 // Initialize the answer variable ans to zero
 ans = 0

 // Check each element of the vector p starting from the first one
 for i := 0; i < n-1; i++ {
 if p[i] == i+1 {
 // Swap the current element with the next one if it is in the wrong position
 p[i], p[i+1] = p[i+1], p[i]
 ans += 1
 }
 }

 // Check the last element of the vector p
 if p[n-1] == n {
 ans += 1
 }

 // Print the answer to the user
 fmt.Fprintf(writer, "%d\n", ans)
 writer.Flush()
}

