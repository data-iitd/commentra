
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
// Start time measurement
start := time.Now()

// Creating a new Scanner object to read input
sc := bufio.NewScanner(os.Stdin)

// Reading the number of elements in the array
var n int
fmt.Scanln(&n)

// Creating an array of long type with size n
var A [n]int64

// Reading the elements of the array A
for i := 0; i < n; i++ {
fmt.Scanln(&A[i])
}

// Calculating the answer using the given formula
var ans int64
for i := 0; i < 60; i++ {
var a int64
var count1 int64

// Counting the number of elements in the array A with the i-th bit set to 1
for j := 0; j < n; j++ {
if A[j]&(1<<i)!= 0 { // Checking if the i-th bit is set in the j-th element of the array A
count1++
}
}

// Calculating the contribution of the i-th bit to the answer
a = a + count1*(n-count1)

// Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
for j := 0; j < i; j++ {
a = (a << 1) % 1000000007
}

// Adding the contribution to the answer
ans += a
ans %= 1000000007
}

// Printing the answer
fmt.Println(ans)

// End time measurement
end := time.Now()

// Printing the time taken by the program to execute
fmt.Println("Time taken by the program is : ", end.Sub(start))
}

