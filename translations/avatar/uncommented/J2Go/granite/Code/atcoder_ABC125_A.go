
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	sec, _ := strconv.Atoi(reader.ReadLine()[2:])
	per_num, _ := strconv.Atoi(reader.ReadLine()[2:])
	max_sec, _ := strconv.ParseFloat(reader.ReadLine()[2:], 64)
	ans_num := 0
	for i := float64(sec); i < max_sec+0.5; i += float64(sec) {
		ans_num += per_num
	}
	fmt.Println(ans_num)
}

