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
	n, _ := strconv.Atoi(readLine(reader))
	w := readInts(reader)
	x := 0
	for _, v := range w {
		x += v
	}
	d := []int{}
	for i := 0; i < n; i++ {
		if (x-w[i])/(n-1) == w[i] {
			d = append(d, i+1)
		}
	}
	fmt.Println(len(d))
	fmt.Println(strings.Join(intSliceToStringSlice(d), " "))
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

func readInts(reader *bufio.Reader) []int {
	line := readLine(reader)
	ints := []int{}
	for _, s := range strings.Split(line, " ") {
		num, _ := strconv.Atoi(s)
		ints = append(ints, num)
	}
	return ints
}

func intSliceToStringSlice(s []int) []string {
	strs := []string{}
	for _, v := range s {
		strs = append(strs, strconv.Itoa(v))
	}
	return strs
}
