package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var sec int
	sc.Scan()
	sec, _ = strconv.Atoi(sc.Text())
	var per_num int
	sc.Scan()
	per_num, _ = strconv.Atoi(sc.Text())
	var max_sec float64
	sc.Scan()
	max_sec, _ = strconv.ParseFloat(sc.Text(), 64)
	var ans_num int
	for i := sec; i < max_sec; i += sec {
		ans_num += per_num
	}
	fmt.Println(ans_num)
}

