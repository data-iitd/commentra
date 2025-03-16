
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func generateString() string {
	var sb strings.Builder
	for i := 1; i <= 1000; i++ {
		sb.WriteString(strconv.Itoa(i))
	}
	return sb.String()
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	fmt.Println(string(generateString()[n-1]))
}

