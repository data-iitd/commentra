
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Run local test with specified input file
	RUN_LOCAL("dataabc155A.txt")

	// Read two integers from input
	a, _ := strconv.Atoi(read())
	b, _ := strconv.Atoi(read())

	// Output the smaller integer b times
	if a < b {
		for i := 0; i < b; i++ {
			fmt.Print(a)
		}
		fmt.Println()
	} else {
		for i := 0; i < a; i++ {
			fmt.Print(b)
		}
		fmt.Println()
	}
}

func read() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func RUN_LOCAL(testfilename string) {
	file, err := os.Open(testfilename)
	if err!= nil {
		file = os.Stdin
	}
	defer file.Close()
	os.Stdin = file
}

// End of code