
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	S, _ := reader.ReadString('\n')
	T, _ := reader.ReadString('\n')
	A, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
	B, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
	U, _ := reader.ReadString('\n')

	if S == U {
		A -= 1
	}
	if T == U {
		B -= 1
	}

	fmt.Println(A, B)
}

