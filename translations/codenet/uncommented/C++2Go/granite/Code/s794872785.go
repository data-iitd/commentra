

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	line, _, err := r.ReadLine()
	if err!= nil {
		if err == io.EOF {
			return
		}
		panic(err)
	}
	for {
		line, _, err := r.ReadLine()
		if err!= nil {
			break
		}
		if len(line) == 0 {
			continue
		}
		words := strings.Fields(string(line))
		fmt.Println(words)
	}
}

