package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	readInt := func() int {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		return num
	}

	n := readInt()
	m := readInt()
	s := readInt()
	f := readInt()

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
	t := readInt()
	l := readInt()
	r := readInt()
	k := 1

	for j != f {
		if i > t && k < m {
			t = readInt()
			l = readInt()
			r = readInt()
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
