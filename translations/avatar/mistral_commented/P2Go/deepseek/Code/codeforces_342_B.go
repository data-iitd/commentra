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
	inputs := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(inputs[0])
	m, _ := strconv.Atoi(inputs[1])
	s, _ := strconv.Atoi(inputs[2])
	f, _ := strconv.Atoi(inputs[3])

	var d int
	var c string
	if s < f {
		d = 1
		c = "R"
	} else {
		d = -1
		c = "L"
	}

	var res strings.Builder
	i := 1
	j := s

	for scanner.Scan() {
		track := strings.Split(scanner.Text(), " ")
		t, _ := strconv.Atoi(track[0])
		l, _ := strconv.Atoi(track[1])
		r, _ := strconv.Atoi(track[2])

		for j != f {
			if i > t {
				scanner.Scan()
				track = strings.Split(scanner.Text(), " ")
				t, _ = strconv.Atoi(track[0])
				l, _ = strconv.Atoi(track[1])
				r, _ = strconv.Atoi(track[2])
			}

			if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
				res.WriteString("X")
			} else {
				res.WriteString(c)
				j += d
			}
			i++
		}
		break
	}

	fmt.Println(res.String())
}

