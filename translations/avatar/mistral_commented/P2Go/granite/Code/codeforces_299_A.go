
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read input from file instead of user input
	file, _ := os.Open("input.txt")
	defer file.Close()

	scanner := bufio.NewScanner(file)
	scanner.Scan()
	line := scanner.Text()
	a := make([]int, 0)
	for _, s := range strings.Split(line, " ") {
		num, _ := strconv.Atoi(s)
		a = append(a, num)
	}
	sort.Ints(a)

	// Find the largest number that leaves a remainder when divided by any number in the list
	result := -1
	for _, num := range a {
		if num < a[0] {
			break
		}
		for _, div := range a {
			if div == num {
				continue
			}
			if num%div == 0 {
				break
			}
		}
		result = num
	}
	fmt.Println(result)
}

