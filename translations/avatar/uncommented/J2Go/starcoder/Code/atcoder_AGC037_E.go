package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	defer sc.Close()

	var N, K int
	var S string
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	K, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	S = sc.Text()

	firstTime := true
	step := 1
	for K > 0 {
		T := strings.Builder{}
		for i := N; i >= 0; i-- {
			T.WriteByte(S[i])
		}
		revU := strings.Builder{}
		revU.WriteString(S)
		revU.WriteString(T.String())
		revU.Reverse()
		sDash := S
		for i := N; i >= 0; i -= step {
			tmp := revU.String()[i : i+N]
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

