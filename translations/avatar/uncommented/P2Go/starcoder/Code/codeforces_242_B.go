package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
	fmt.Println("Enter the number of test cases")
	tc, err := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	checkError(err)
	var t int
	for t = 0; t < tc; t++ {
		fmt.Println("Enter the number of intervals")
		n, err := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		checkError(err)
		var l, r int
		fmt.Println("Enter the left and right limits of the first interval")
		l, r, err = strconv.Atoi(strings.TrimSpace(readLine(reader))), strconv.Atoi(strings.TrimSpace(readLine(reader))), nil
		checkError(err)
		var id int
		for i := 1; i < n; i++ {
			fmt.Println("Enter the left and right limits of the next interval")
			li, ri, err := strconv.Atoi(strings.TrimSpace(readLine(reader))), strconv.Atoi(strings.TrimSpace(readLine(reader))), nil
			checkError(err)
			if li <= l && r <= ri {
				id = i
			} else if li < l || r < ri {
				id = n
			}
			l = min(l, li)
			r = max(r, ri)
		}
		fmt.Printf("%d\n", -1 if id == n else id+1)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

