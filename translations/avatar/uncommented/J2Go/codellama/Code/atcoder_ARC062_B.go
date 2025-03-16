
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
	var S string
	fmt.Scan(&S)
	score := 0
	for i := 0; i < len(S); i++ {
		my := "g"
		if i%2 == 0 {
			my = "p"
		}
		his := string(S[i])
		if my != his {
			if my == "p" {
				score++
			} else {
				score--
			}
		}
	}
	fmt.Println(score)
}

// 