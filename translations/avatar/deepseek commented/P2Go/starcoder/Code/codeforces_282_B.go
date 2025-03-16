
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	firstline, _ := strconv.Atoi(readLine())
	total := 0
	memory := []string{}

	for x := 0; x < firstline; x++ {
		A, G := readLineAsIntSlice()
		if total+A <= 500 {
			total += A
			memory = append(memory, "A")
		} else {
			total -= G
			memory = append(memory, "G")
		}
	}

	fmt.Println(strings.Join(memory, ""))
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

func readLineAsIntSlice() []int {
	line := readLine()
	return parseIntSlice(line)
}

func parseIntSlice(line string) []int {
	var slice []int
	for _, item := range strings.Split(line, " ") {
		if item!= "" {
			num, _ := strconv.Atoi(item)
			slice = append(slice, num)
		}
	}
	return slice
}

