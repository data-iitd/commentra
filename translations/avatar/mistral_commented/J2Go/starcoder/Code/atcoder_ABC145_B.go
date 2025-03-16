
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
	fmt.Println("Enter a string:")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	fmt.Println("Enter the length of the string:")
	length, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println(isPalindrome(input, length))
}

func isPalindrome(input string, length int) string {
	if length%2 == 0 {
		return "Yes"
	}
	for i := 0; i < length/2; i++ {
		if input[i]!= input[length-i-1] {
			return "No"
		}
	}
	return "Yes"
}

