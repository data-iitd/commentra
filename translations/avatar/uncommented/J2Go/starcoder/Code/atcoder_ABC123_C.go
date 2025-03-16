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
	sc.Split(bufio.ScanWords)
	sc.Scan()
	N, _ := strconv.ParseInt(sc.Text(), 10, 64)
	min := 0
	for i := 0; i < 5; i++ {
		if i == 0 {
			sc.Scan()
			min, _ = strconv.ParseInt(sc.Text(), 10, 64)
		} else {
			sc.Scan()
			tmp, _ := strconv.ParseInt(sc.Text(), 10, 64)
			if tmp < min {
				min = tmp
			}
		}
	}
	fmt.Println(int(math.Ceil((float64(N) / float64(min))) + 4))
}

