<<<<<<< HEAD

import (
=======
package main

import (
	"bufio"
>>>>>>> 98c87cb78a (data updated)
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of cells in the grid and the number of rows/columns to be painted
<<<<<<< HEAD
	hcell, wcell := readInt(), readInt()
	hpaint, wpaint := readInt(), readInt()

	// Calculate the number of black cells
	nblack := (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)

	// Calculate the number of white cells
	nwhite := (hcell * wcell) - nblack

	// Print the number of white cells
	fmt.Println(nwhite)
}

func readInt() int {
	// Read a line of input from stdin and return an integer
	text := readLine()
	i, err := strconv.Atoi(text)
	if err!= nil {
		panic(err)
	}
	return i
}

func readLine() string {
	// Read a line of input from stdin
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := os.Stdin.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return strings.TrimSpace(string(buf))
}

=======
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of cells in the grid and the number of rows/columns to be painted: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	input = strings.TrimSuffix(input, "\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\r")
	input = strings.TrimSuffix(input, "\n\n")
	input = strings.TrimSuffix(input, "\n\r\n")
	input = strings.TrimSuffix(input, "\r\n\r")
	input = strings.TrimSuffix(input, "\r\r\n")
	input = strings.TrimSuffix(input, "\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n")
	input = strings.TrimSuffix(input, "\r\r\r")
	input = strings.TrimSuffix(input, "\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	input = strings.TrimSuffix(input, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	input = strings.TrimSuffix(input, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
>>>>>>> 98c87cb78a (data updated)
