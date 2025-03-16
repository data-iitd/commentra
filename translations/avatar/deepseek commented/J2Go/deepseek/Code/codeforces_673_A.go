package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	a := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	result, pos, flag := 0, 0, 0

	if a[0] > 15 {
		result = 15
	} else {
		for i := 1; i < n; i++ {
			if a[i]-a[i-1] > 15 {
				pos = i - 1
				flag = 1
				break
			}
		}
		if flag == 1 {
			result = a[pos] + 15
		} else {
			result = a[n-1] + 15
		}
	}

	if result > 90 {
		result = 90
	}

	fmt.Println(result)
}

