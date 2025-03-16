package main

import (
	"fmt"
)

func main() {
	var sec, per_num int
	var max_sec float64
	fmt.Scan(&sec, &per_num, &max_sec)
	ans_num := 0
	for i := sec; i < int(max_sec); i += sec {
		ans_num += per_num
	}
	fmt.Println(ans_num)
}
