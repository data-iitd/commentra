package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	var l []int
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		l = append(l, num)
	}

	sort.Ints(l)

	c := 0
	for _, i := range l {
		if i > c {
			c += 1
		}
	}

	fmt.Println(c + 1)
}

