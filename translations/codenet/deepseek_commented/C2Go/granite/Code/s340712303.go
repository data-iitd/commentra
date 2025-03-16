
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const N = 2000

func main() {
	num1, math := 0, make([]int, N+1)
	math[0] = 1

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &num1)
	for i := 0; i < num1; i++ {
		a, _ := strconv.Atoi(readLine(reader))
		sum += a
		for j := sum - a; j >= 0; j-- {
			if math[j] == 1 {
				math[j+a] = 1
			}
		}
	}

	num2, _ := strconv.Atoi(readLine(reader))
	for i := 0; i < num2; i++ {
		ans, _ := strconv.Atoi(readLine(reader))
		if math[ans] == 1 {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

