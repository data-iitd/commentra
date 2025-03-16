package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, D int
	var ans, rem int

	N, D = get_input()
	ans = N / (D*2+1)
	rem = N % (D*2+1)

	if rem!= 0 {
		ans = ans + 1
	}

	fmt.Printf("%d\n", ans)
}

func get_input() (int, int) {
	var N, D int
	var line string
	var err error

	line, err = os.Stdin.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	N, err = strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		panic(err)
	}

	line, err = os.Stdin.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	D, err = strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		panic(err)
	}

	return N, D
}

