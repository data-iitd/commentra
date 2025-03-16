

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	t := string(s.Bytes()[0]) + strconv.Itoa(len(s.Bytes())-2) + string(s.Bytes()[len(s.Bytes())-1])
	fmt.Println(t)
}
