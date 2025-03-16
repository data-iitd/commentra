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
	fmt.Println("Enter number of strings")
	num, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]string, num)
	for i := 0; i < num; i++ {
		fmt.Println("Enter string", i+1)
		arr[i], _ = reader.ReadString()
	}
	fine := 0
	for i := 0; i < num; i++ {
		counter := 0
		for k := 0; k < num; k++ {
			if arr[k][i] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
	}
	for i := 0; i < num; i++ {
		counter := 0
		for k := 0; k < num; k++ {
			if arr[i][k] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
	}
	fmt.Println(fine)
}

