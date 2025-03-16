package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(input[:len(input)-1])
	
	ans, sumL := 1, 0
	
	sentence, _ := reader.ReadString('\n')
	sentences := regexp.MustCompile(`[.?!]`).Split(sentence[:len(sentence)-1], -1)
	
	for _, s := range sentences {
		s = s + "."
		L := len(s)
		if L > 1 {
			if L > n {
				fmt.Println("Impossible")
				return
			}
			if sumL + L + (sumL > 0) > n {
				ans++
				sumL = L
			} else {
				sumL = sumL + L + (sumL > 0)
			}
		}
	}
	fmt.Println(ans)
}

