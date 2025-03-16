

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	a, _ := reader.ReadString('\n')
	b, _ := reader.ReadString('\n')

	b = strings.TrimSpace(b)

	num, _ := strconv.Atoi(a)
	num *= int(math.Pow(10, float64(len(b))))
	num += int(strconv.Atoi(b))

	for i := 1; i <= 100100; i++ {
		if i*i == num {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")
}

