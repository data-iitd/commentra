
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		top, chonda, yamagami int
		null                    string
		bufIn                   = bufio.NewReader(os.Stdin)
		bufOut                  = bufio.NewWriter(os.Stdout)
	)

	for {
		null, _ = bufIn.ReadString('\n')
		null = strings.TrimSpace(null)
		if null == "" {
			break
		}

		switch null[0] {
		case '+':
			chonda, _ = strconv.Atoi(strconv.Itoa(pop()))
			yamagami, _ = strconv.Atoi(strconv.Itoa(pop()))
			push(chonda + yamagami)
		case '-':
			yamagami, _ = strconv.Atoi(strconv.Itoa(pop()))
			chonda, _ = strconv.Atoi(strconv.Itoa(pop()))
			push(chonda - yamagami)
		case '*':
			chonda, _ = strconv.Atoi(strconv.Itoa(pop()))
			yamagami, _ = strconv.Atoi(strconv.Itoa(pop()))
			push(chonda * yamagami)
		default:
			push(atoi(null))
		}
	}

	fmt.Fprintf(bufOut, "%d\n", pop())
	bufOut.Flush()
}

func push(chonda int) {
	top++
	stack[top] = chonda
}

func pop() int {
	top--
	return stack[top+1]
}

var stack [1000]int
var top int

