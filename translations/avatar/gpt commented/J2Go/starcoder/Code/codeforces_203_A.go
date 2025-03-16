package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values
	x, _ := strconv.Atoi(readLine())
	t, _ := strconv.Atoi(readLine())
	a, _ := strconv.Atoi(readLine())
	b, _ := strconv.Atoi(readLine())
	da, _ := strconv.Atoi(readLine())
	db, _ := strconv.Atoi(readLine())

	first := 0
	second := 0
	ok := false

	// Iterate through possible steps for the first entity
	for i := 0; i < t; i++ {
		first = a - (da * i)

		// Iterate through possible steps for the second entity
		for j := 0; j < t; j++ {
			second = b - (db * j)

			// Check if any of the conditions to reach target x are met
			if second+first == x || second == x || first == x || x == 0 {
				ok = true
				break
			}
		}
	}

	// Output result based on whether the target can be reached
	if ok {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func readLine() string {
	if _, err := os.Stdin.Stat(); err!= nil {
		return ""
	}

	var (
		isPrefix bool = true
		buf      []byte = make([]byte, 0, 1024)
		tmp      []byte = make([]byte, 0, 1024)
		single   byte
	)

	for isPrefix && err!= io.EOF {
		single, err = os.Stdin.Read(tmp)
		buf = append(buf, tmp[:single]...)

		if single == len(tmp) {
			tmp = make([]byte, 1024)
		} else {
			isPrefix = false
		}
	}

	return strings.TrimSpace(string(buf))
}

