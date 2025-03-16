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
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readLine(reader))
	}

	m := 0
	for i := 1; i < n; i++ {
		if a[m] < 0 && a[i] < 0 {
			m = i
		} else if a[m] > 0 && a[i] > 0 {
			m = i
		}
	}

	r := make([]string, 0)
	if a[m] >= 0 {
		for i := 1; i < n; i++ {
			r = append(r, fmt.Sprintf("%d %d", i, i+1))
		}
	} else {
		for i := n - 1; i > 0; i-- {
			r = append(r, fmt.Sprintf("%d %d", i, i-1))
		}
	}

	fmt.Println(len(r))
	for _, v := range r {
		fmt.Println(v)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

