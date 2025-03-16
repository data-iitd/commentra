
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	N, _ := strconv.Atoi(read(reader))
	K, _ := strconv.Atoi(read(reader))
	S := read(reader)

	firstTime := true
	step := 1

	for K > 0 {
		T := reverse(S)
		revU := S + T
		revU = reverse(revU)
		sDash := S

		for i := N; i >= 0; i -= step {
			tmp := revU[i : i+N]
			if sDash > tmp {
				sDash = tmp
			} else {
				if!firstTime {
					break
				}
			}
		}

		if firstTime {
			firstTime = false
			if 1<<uint(K) > N {
				c := string(sDash[0])
				for i := 0; i < N; i++ {
					fmt.Print(c)
				}
				fmt.Println()
				os.Exit(0)
			}
		} else {
			step *= 2
		}
		K--
		S = sDash
		S = reverse(S)
	}
	fmt.Println(reverse(S))
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

