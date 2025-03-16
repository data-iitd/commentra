package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Declaring a private method to calculate the XOR operation on a given string with a specific character
func cal(s string, c byte) int {
	n := len(s)  // Getting the length of the given string
	m := n - 1   // Initializing a variable 'm' to keep track of the index of the previous character
	ans := 0     // Initializing a variable 'ans' to store the result of XOR operation
	
	for i := 0; i < n; i++ {  // Looping through each character in the given string
		if s[i] == c && (m&i == i) { // Checking if the current character is the given character and the difference between its index and the index of the previous character is a power of 2
			ans ^= 1  // If yes, performing XOR operation on 'ans'
		}
	}
	
	return ans  // Returning the result of XOR operation
}

// Declaring a private method to read input and process it
func solve() {
	n := nextInt()  // Reading the number of test cases
	
	for testCase := 1; testCase <= n; testCase++ {  // Looping through each test case
		num := nextInt()  // Reading the length of the given string
		s := next()       // Reading the given string
		
		var sb strings.Builder  // Creating a StringBuilder object to store the differences between adjacent characters
		
		for i := 1; i < num; i++ {  // Looping through each character except the first one in the given string
			sb.WriteString(strconv.Itoa(int(math.Abs(float64(s[i] - s[i-1])))))  // Appending the absolute difference between adjacent characters to the StringBuilder object
		}
		
		if num == 2 {  // Checking if the given string has only two characters
			fmt.Fprintln(os.Stdout, sb.String()[0])  // If yes, printing the first character of the string
			continue  // And moving to the next test case
		}
		
		s = sb.String()  // Converting the StringBuilder object to a String object
		
		if strings.Contains(s, "1") {  // Checking if the given string contains the character '1'
			fmt.Fprintln(os.Stdout, cal(s, '1'))  // If yes, printing the result of XOR operation on the given string with character '1'
		} else {
			fmt.Fprintln(os.Stdout, cal(s, '2')*2)  // If no, performing XOR operation on the given string with character '2' and multiplying the result by 2
		}
	}
}

// Declaring static variables for input/output operations
var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

// Declaring a function to read input
func next() string {
	for {
		line, err := in.ReadString('\n')
		if err == nil {
			return strings.TrimSpace(line)
		}
	}
}

// Declaring a function to read integer input
func nextInt() int {
	n, _ := strconv.Atoi(next())
	return n
}

// Declaring the main function to start the program
func main() {
	defer out.Flush()
	solve()
}

