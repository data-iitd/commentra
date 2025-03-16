
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

// Global variables
var (
MOD int = 1000000007
)

// Function to read input from stdin
func readInput(scanner *bufio.Scanner) string {
scanner.Scan()
return scanner.Text()
}

// Function to convert a string to an integer
func strToInt(str string) int {
i, _ := strconv.Atoi(str)
return i
}

// Function to convert a string array to an integer array
func strArrayToIntArray(strArray []string) []int {
intArray := make([]int, len(strArray))
for i := 0; i < len(strArray); i++ {
intArray[i] = strToInt(strArray[i])
}
return intArray
}

// Function to print an object or an array in a readable format
func tr(objects...interface{}) {
fmt.Println(objects)
}

// Main function
func main() {
// Read the input from stdin
scanner := bufio.NewScanner(os.Stdin)
input := readInput(scanner)

// Convert the input string to a character array
chars := []rune(input)

// Initialize the base variable to 1
base := 1

// Initialize a 2D array dp of size len(chars) x 13 to store the intermediate results
dp := make([][]int, len(chars))
for i := 0; i < len(chars); i++ {
dp[i] = make([]int, 13)
}

// Iterate through each character in the character array chars
for i := 0; i < len(chars); i++ {
if chars[len(chars)-1-i] == '?' { // If the current character is a '?'
// Iterate through all possible values of pre (from 0 to 12)
for pre := 0; pre < 13; pre++ {
// Iterate through all possible values of next (from 0 to 9)
for next := 0; next < 10; next++ {
// Add the contribution of the current character to the dp array
dp[i][(base*next+pre)%13] += (i > 0? dp[i-1][pre] : (pre == 0? 1 : 0)) // If i is not the first character, add the contribution of the previous character
dp[i][(base*next+pre)%13] %= MOD // Perform modulo operation to keep the result within the range of MOD
}
}
} else { // If the current character is not a '?'
// Convert the digit character to an integer and subtract '0' to get the actual value
next := strToInt(string(chars[len(chars)-1-i])) - 0
// Iterate through all possible values of pre (from 0 to 12)
for pre := 0; pre < 13; pre++ {
// Add the contribution of the current character to the dp array
dp[i][(base*next+pre)%13] += (i > 0? dp[i-1][pre] : (pre == 0? 1 : 0)) // If i is not the first character, add the contribution of the previous character
dp[i][(base*next+pre)%13] %= MOD // Perform modulo operation to keep the result within the range of MOD
}
}
base = base*10 % 13 // Multiply the base by 10 and take the result modulo 13 to update the base for the next character
}

// Print the final result
tr(dp[len(dp)-1][5])
}

