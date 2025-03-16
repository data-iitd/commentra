

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	a, _ := strconv.Atoi(reader.ReadLine()[0:1])
	b, _ := strconv.Atoi(reader.ReadLine()[0:1])
	c, _ := strconv.Atoi(reader.ReadLine()[0:1])

	if (100*a + 10*b + c) % 4 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

