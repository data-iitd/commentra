package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Get input from stdin.
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter maximum level: ")
	maxLevel, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Print("Enter x: ")
	x := strings.Split(strings.TrimSpace(reader.ReadString()), " ")
	fmt.Print("Enter y: ")
	y := strings.Split(strings.TrimSpace(reader.ReadString()), " ")

	// Remove the first element from each list, convert them into sets, and check if there's a 0 in either set.
	x = x[1:]
	y = y[1:]
	x = toSet(x)
	y = toSet(y)
	if 0 in x {
		x.remove(0)
	}
	if 0 in y {
		y.remove(0)
	}

	// Find the union of the two sets and check if its length is equal to the maximum level.
	z := x.union(y)
	if len(z)!= maxLevel {
		fmt.Println("Oh, my keyboard!")
	} else {
		fmt.Println("I become the guy.")
	}
}

func toSet(arr []string) (set []int) {
	for _, v := range arr {
		i, _ := strconv.Atoi(v)
		set = append(set, i)
	}
	return
}

