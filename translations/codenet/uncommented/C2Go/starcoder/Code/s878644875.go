package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	s := make([]byte, 4)
	t := make([]byte, 4)
	fmt.Fscanf(os.Stdin, "%s", &s)
	fmt.Fscanf(os.Stdin, "%s", &t)
	hit := 0
	for i := 0; i < 3; i++ {
		if s[i] == t[i] {
			hit++
		}
	}
	fmt.Printf("%d\n", hit)
}

