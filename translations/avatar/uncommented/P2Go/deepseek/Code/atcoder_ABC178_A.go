package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(tc int) {
	reader := bufio.NewReader(os.Stdin)
	a, _ := reader.ReadString('\n')
	a = a[:len(a)-1] // Remove the newline character
	aInt := int(a[0] - '0')
	if aInt == 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	tcs, _ := reader.ReadString('\n')
	tcs = tcs[:len(tcs)-1] // Remove the newline character
	tcsInt, _ := fmt.Sscanf(tcs, "%d", &tcs)
	for tc := 1; tc <= tcsInt; tc++ {
		solve(tc)
	}
}

