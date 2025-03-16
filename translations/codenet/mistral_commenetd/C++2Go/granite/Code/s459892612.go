

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(reader.ReadLine()[0])
	b, _ := strconv.Atoi(reader.ReadLine()[0])
	c, _ := strconv.Atoi(reader.ReadLine()[0])

	if a+b >= c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

