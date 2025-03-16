package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]string, 0)
	for _, arg := range os.Args[1:] {
		sc = append(sc, arg)
	}

	sec, _ := strconv.Atoi(sc[0])
	per_num, _ := strconv.Atoi(sc[1])
	max_sec, _ := strconv.ParseFloat(sc[2], 64)

	ans_num := 0
	for i := sec; i < max_sec; i += sec {
		ans_num += per_num
	}

	fmt.Println(ans_num)
}

