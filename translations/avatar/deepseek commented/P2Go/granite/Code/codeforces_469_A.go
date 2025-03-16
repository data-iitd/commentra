
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var maxLevel int
	fmt.Fscanf(reader, "%d\n", &maxLevel)

	var x, y []int
	fmt.Fscanf(reader, "%d", &x)
	for i := 1; i < len(x); i++ {
		var temp int
		fmt.Fscanf(reader, " %d", &temp)
		x = append(x, temp)
	}

	fmt.Fscanf(reader, "%d", &y)
	for i := 1; i < len(y); i++ {
		var temp int
		fmt.Fscanf(reader, " %d", &temp)
		y = append(y, temp)
	}

	x = x[1:]
	y = y[1:]

	xSet := make(map[int]bool)
	for _, v := range x {
		xSet[v] = true
	}

	ySet := make(map[int]bool)
	for _, v := range y {
		ySet[v] = true
	}

	if xSet[0] {
		delete(xSet, 0)
	}
	if ySet[0] {
		delete(ySet, 0)
	}

	z := make(map[int]bool)
	for k := range xSet {
		z[k] = true
	}
	for k := range ySet {
		z[k] = true
	}

	if len(z)!= maxLevel {
		fmt.Println("Oh, my keyboard!")
	} else {
		fmt.Println("I become the guy.")
	}
}
