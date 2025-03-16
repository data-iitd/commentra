
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const MOD = 100000007

	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		if n == 0 {
			break
		}

		sq := make([]int, n)
		fr := make([]int, (n-1)/2+1)
		for i := 1; i < n; i++ {
			sq[i] = (i * i) % n
		}

		com := make([]int, 0)
		for i := 1; i < n; i++ {
			f := true
			for j := 0; j < len(com); j++ {
				if com[j] == sq[i] {
					f = false
					break
				}
			}
			if f {
				com = append(com, sq[i])
			}
		}

		for i := 0; i <= (n-1)/2; i++ {
			fr[i] = 0
		}

		for i := 0; i < len(com); i++ {
			for j := 0; j < len(com); j++ {
				if i!= j {
					tmp := com[i] - com[j]
					if tmp < 0 {
						tmp += n
					}
					if tmp > (n-1)/2 {
						tmp = n - tmp
					}
					fr[tmp]++
				}
			}
		}

		for i := 1; i <= (n-1)/2; i++ {
			fmt.Println(fr[i])
		}
	}
}

