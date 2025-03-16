
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := reader.ReadString('\n')
	b, _ := reader.ReadString('\n')
	a = a[:len(a)-1]
	b = b[:len(b)-1]
	aInt, _ := strconv.Atoi(a)
	bInt, _ := strconv.Atoi(b)
	max := int(math.Max(float64(aInt+bInt), math.Max(float64(aInt-bInt), float64(aInt*bInt))))
	fmt.Println(max)
}

