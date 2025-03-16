package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the length of the string S:")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the value of K:")
	K, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the string S:")
	S := strings.TrimSpace(reader.ReadString('\n'))
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
			if math.Pow(2, float64(K)) > float64(N) {
				c := sDash[0]
				for i := 0; i < N; i++ {
					fmt.Print(c)
				}
				fmt.Println()
				os.Exit(0)
			}
		} else {
			step += step
		}
		K--
		S = sDash
		S = reverse(S)
	}
	fmt.Println(reverse(S))
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

