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
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	roundComplexity := []int{}
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		roundComplexity = append(roundComplexity, num)
	}

	scanner.Scan()
	georgeComplexity := []int{}
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		georgeComplexity = append(georgeComplexity, num)
	}

	i, j := 0, 0
	for i < n && j < m {
		if roundComplexity[i] <= georgeComplexity[j] {
			i++
		}
		j++
	}

	fmt.Println(n - i)
}
