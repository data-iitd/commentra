

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)
	xTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	x := int32(xTemp)
	print(x, n)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	panic(err)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func print(x int32, n int32) {
	max := n*2 - 1
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
	sep := "\n"
	ans := ""
	for i := x + n - 1; i <= x+n+max-1; i++ {
		ans += fmt.Sprintf("%d%s", (i%max+1), sep)
	}
	fmt.Println(ans)
}

