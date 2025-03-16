
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
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	values := strings.Split(scanner.Text(), " ")
	scanner.Scan()
	costs := strings.Split(scanner.Text(), " ")

	max := 0
	for i := 0; i < n; i++ {
		profit, _ := strconv.Atoi(values[i])
		cost, _ := strconv.Atoi(costs[i])
		if profit-cost > 0 {
			max += profit - cost
		}
	}

	fmt.Println(max)
}

