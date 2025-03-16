
/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	fmt.Fprintf(&buf, "%t\n", n == 0)
	fmt.Print(buf.String())
}

