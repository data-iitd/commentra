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
	fmt.Print("Enter n: ")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Print("Enter k: ")
	k, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Print("Enter a: ")
	a, _ := reader.ReadString('\n')
	a = strings.TrimSuffix(a, "\n")

	// Check if k is greater than n/2
	if k > n/2 {
		// Move right until k equals n
		for k < n {
			fmt.Println("RIGHT")
			k++
		}
	} else {
		// Move left until k equals 1
		for k > 1 {
			fmt.Println("LEFT")
			k--
		}
	}

	// If k equals 1, print each character of the string a starting from the first character and moving rightwards
	if k == 1 {
		for i := 0; i < len(a); i++ {
			fmt.Println("PRINT", a[i])
			if i+1 < len(a) {
				fmt.Println("RIGHT")
			}
		}
	} else {
		// If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
		for i := len(a) - 1; i >= 0; i-- {
			fmt.Println("PRINT", a[i])
			if i-1 >= 0 {
				fmt.Println("LEFT")
			}
		}
	}
}

