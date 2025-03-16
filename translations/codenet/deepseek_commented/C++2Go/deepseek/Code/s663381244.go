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
	scanner.Buffer(nil, 1024*1024)

	m := []int{10, 50, 100, 500}

	for {
		scanner.Scan()
		money, _ := strconv.Atoi(scanner.Text())
		if money == 0 {
			break
		}

		num := make([]int, 4)
		sum := 0
		for i := 0; i < 4; i++ {
			scanner.Scan()
			num[i], _ = strconv.Atoi(scanner.Text())
			sum += num[i] * m[i]
		}

		change := sum - money
		for i := 3; i >= 0; i-- {
			if change/m[i] > 0 {
				num[i] -= change / m[i]
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

