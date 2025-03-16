package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	m := []int{10, 50, 100, 500}
	scanner := bufio.NewScanner(os.Stdin)
	first := true
	for scanner.Scan() {
		if !first {
			fmt.Println()
		}
		first = false
		money, _ := strconv.Atoi(scanner.Text())
		sum := 0
		num := make([]int, 4)
		for i := 0; i < 4; i++ {
			scanner.Scan()
			num[i], _ = strconv.Atoi(scanner.Text())
			sum += num[i] * m[i]
		}

		change := sum - money
		for i := 3; i >= 0; i-- {
			if change/m[i] > 0 {
				num[i] = num[i] - change/m[i]
				change %= m[i]
			}
		}

		for i := 0; i < 4; i++ {
			if num[i] > 0 {
				fmt.Println(m[i], num[i])
			}
		}
	}
}

