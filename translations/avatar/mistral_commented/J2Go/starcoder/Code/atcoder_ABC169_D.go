package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int64
	fmt.Scanf("%d", &n)
	sqrt := int(math.Sqrt(float64(n)))
	answer := 0
	for i := 2; i <= sqrt; i++ {
		count := 0
		for {
			if n%i == 0 {
				n /= i
				count++
			} else {
				break
			}
		}
		for j := 1; count-j >= 0; j++ {
			count -= j
			answer++
		}
	}
	if n > 1 {
		answer++
	}
	fmt.Println(answer)
}

