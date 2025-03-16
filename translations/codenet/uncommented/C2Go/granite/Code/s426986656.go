
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	A, _ := strconv.Atoi(nextString(reader))
	B, _ := strconv.Atoi(nextString(reader))

	flag := 0
	for i := 1; i <= 3; i++ {
		if (A*B*i)%2 == 1 {
			flag = 1
			break
		}
	}

	if flag == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func nextString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

