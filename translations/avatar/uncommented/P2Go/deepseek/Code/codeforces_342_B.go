package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	s, _ := strconv.Atoi(parts[2])
	f, _ := strconv.Atoi(parts[3])

	var d int
	var c string
	if s < f {
		d = 1
		c = "R"
	} else {
		d = -1
		c = "L"
	}

	res := ""
	i := 1
	j := s
	for j != f {
		if i > t && k < m {
			scanner.Scan()
			parts := strings.Split(scanner.Text(), " ")
			t, _ := strconv.Atoi(parts[0])
			l, _ := strconv.Atoi(parts[1])
			r, _ := strconv.Atoi(parts[2])
			k++
		}
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			res += "X"
		} else {
			res += c
			j += d
		}
		i++
	}
	fmt.Println(res)
}
