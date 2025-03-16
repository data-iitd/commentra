package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of seconds")
	seconds, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the number of people per second")
	per_num, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the maximum number of seconds")
	max_sec, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	ans_num := 0
	for i := seconds; i < max_sec; i += seconds {
		ans_num += per_num
	}
	fmt.Println(ans_num)
}

