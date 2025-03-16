package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	mapa := make(map[int]int)

	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())

		if val, ok := mapa[num]; !ok {
			mapa[num] = 1
		} else {
			mapa[num] = val + 1
		}

		if key, ok := mapa[num-1]; ok {
			if key == 1 {
				delete(mapa, num-1)
			} else {
				mapa[num-1] = key - 1
			}
		}
	}

	ans := 0
	for _, val := range mapa {
		ans += val
	}

	fmt.Println(ans)
}
