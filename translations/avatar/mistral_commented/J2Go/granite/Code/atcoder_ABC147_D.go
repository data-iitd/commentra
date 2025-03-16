

package main

import (
 "bufio"
 "fmt"
 "math"
 "os"
 "strconv"
 "strings"
)

func main() {
 startTime := time.Now().UnixNano() // Start time measurement
 reader := bufio.NewReader(os.Stdin) // Creating a new bufio.Reader object to read input from the standard input
 n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader))) // Reading the number of elements in the array A
 div := int64(math.Pow(10, 9)) + 7 // Modulus constant for efficient modular arithmetic
 A := make([]int64, n) // Creating an array of int64 type with size n
 ans := int64(0) // Initializing the answer variable to zero

 // Reading the elements of the array A
 for i := 0; i < n; i++ {
 A[i], _ = strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64) // Reading an element of the array A
 }

 // Calculating the answer using the given formula
 for i := 0; i < 60; i++ { // Looping through all the bits from 0 to 59
 a := int64(0) // Initializing the variable a to zero
 count1 := int64(0) // Initializing the variable count1 to zero

 // Counting the number of elements in the array A with the i-th bit set to 1
 for j := 0; j < n; j++ {
 if (A[j]>>i)&1 == 1 { // Checking if the i-th bit is set in the j-th element of the array A
 count1++ // Incrementing the count1 variable
 }
 }

 // Calculating the contribution of the i-th bit to the answer
 a = a + count1*(n-count1) // a = a + (count1 \* (n - count1))

 // Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
 for j := 0; j < i; j++ {
 a = (a << 1) % div // a = (a << 1) % div
 }

 // Adding the contribution to the answer
 ans = (ans + a) % div // ans = (ans + a) % div
 }

 // Printing the answer
 fmt.Println(ans) // Printing the answer
 endTime := time.Now().UnixNano() // End time measurement
 fmt.Println("Time taken by the program is : ", (endTime-startTime)/1e6, " milliseconds") // Printing the time taken by the program to execute
}

func readLine(reader *bufio.Reader) string {
 str, _, err := reader.ReadLine() // Reading a line of input from the standard input
 if err == io.EOF {
 return ""
 }
 return strings.TrimSpace(string(str)) // Returning the trimmed line of input as a string
}

I hope these comments will help you understand the code better. Let me know if you have any questions!