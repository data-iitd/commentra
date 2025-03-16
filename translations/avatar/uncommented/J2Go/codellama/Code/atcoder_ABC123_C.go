
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var N int64
	var min int64
	var i int64
	var ans int64
	var err error
	N, err = strconv.ParseInt(os.Args[1], 10, 64)
	if err != nil {
		fmt.Println(err)
		return
	}
	min = 0
	for i = 0; i < 5; i++ {
		if i == 0 {
			min, err = strconv.ParseInt(os.Args[2], 10, 64)
			if err != nil {
				fmt.Println(err)
				return
			}
		} else {
			min = int64(math.Min(float64(min), float64(strconv.ParseInt(os.Args[i+1], 10, 64))))
		}
	}
	ans = int64(math.Ceil(float64(N) / float64(min))) + 4
	fmt.Println(ans)
}

