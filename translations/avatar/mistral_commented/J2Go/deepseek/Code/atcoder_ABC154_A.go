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

	// Reading the first line of input as an array of strings
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	splitStr := strings.Split(str, " ")

	// Reading the second line of input as separate tokens
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	tokenStr := scanner.Text()
	tokens := strings.Split(tokenStr, " ")

	// Reading the first two integers as input
	a, _ := strconv.Atoi(tokens[0])
	b, _ := strconv.Atoi(tokens[1])

	// Reading the third line of input as a string
	u, _ := reader.ReadString('\n')
	u = strings.TrimSpace(u)

	// Checking if the first string from the first line matches with the given string 'u'
	if u == splitStr[0] {
		// If the condition is true, then print the result as (a-1) and b
		fmt.Println(strconv.Itoa(a-1) + " " + strconv.Itoa(b))
	} else {
		// If the condition is false, then print the result as a and (b-1)
		fmt.Println(strconv.Itoa(a) + " " + strconv.Itoa(b-1))
	}
}
