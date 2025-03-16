package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := bufio.NewReader(inputStream)
	out := bufio.NewWriter(outputStream)

	// Read four integers from input
	a, _ := strconv.Atoi(readLine(in))
	b, _ := strconv.Atoi(readLine(in))
	c, _ := strconv.Atoi(readLine(in))
	d, _ := strconv.Atoi(readLine(in))

	// Check conditions to determine the output
	if c > b {
		// If c is greater than b, output 0
		fmt.Fprintln(out, 0)
	} else if a > d {
		// If a is greater than d, output 0
		fmt.Fprintln(out, 0)
	} else if a < c {
		// If a is less than c, calculate and output the difference
		fmt.Fprintln(out, int(math.Min(float64(b), float64(d))-float64(c)))
	} else {
		// Create a list to hold the four integers
		l := make([]int, 4)
		l[0] = a
		l[1] = b
		l[2] = c
		l[3] = d

		// Sort the list to find the second largest and third largest values
		sort.Ints(l)

		// Output the difference between the second largest and third largest values
		fmt.Fprintln(out, l[2]-l[1])
	}

	// Flush the output stream
	out.Flush()
}

// Read a line of input from stdin and return it as a string
func readLine(in *bufio.Reader) string {
	var str string
	var err error
	for {
		str, err = in.ReadString('\n')
		if err != nil {
			if err == io.EOF {
				break
			}
			return ""
		}
		str = strings.TrimSuffix(str, "\n")
		if str != "" {
			break
		}
	}
	return str
}

// END-OF-CODE
