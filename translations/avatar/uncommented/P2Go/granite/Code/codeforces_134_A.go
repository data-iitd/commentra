
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
	n, _ := strconv.Atoi(readerReadLine(reader))
	w := readLine(reader)
	x := 0
	for _, v := range w {
		x += v
	}
	d := []int{}
	for i, v := range w {
		if (x-v)/(n-1) == v {
			d = append(d, i+1)
		}
	}
	fmt.Println(len(d))
	fmt.Println(strings.Join(intSliceToStringSlice(d), " "))
}

func readerReadLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

func readLine(reader *bufio.Reader) []int {
	line := readerReadLine(reader)
	line = line[:len(line)-1]
	s := strings.Split(line, " ")
	r := make([]int, len(s))
	for i, v := range s {
		r[i], _ = strconv.Atoi(v)
	}
	return r
}

func intSliceToStringSlice(s []int) []string {
	r := make([]string, len(s))
	for i, v := range s {
		r[i] = strconv.Itoa(v)
	}
	return r
}

