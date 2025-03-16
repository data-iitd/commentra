
package main

import (
	"bufio"
	"fmt"
	"os"
)

const N = 2000

func main() {
	var num1, a, num2, ans int
	var sum int
	var math [N + 1]bool
	math[0] = true

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &num1)
	for i := 0; i < num1; i++ {
		fmt.Fscanf(reader, "%d\n", &a)
		sum += a
		for j := sum - a; j >= 0; j-- {
			if math[j] == true {
				math[j+a] = true
			}
		}
	}

	fmt.Fscanf(reader, "%d\n", &num2)
	for i := 0; i < num2; i++ {
		fmt.Fscanf(reader, "%d\n", &ans)
		if math[ans] == true {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

