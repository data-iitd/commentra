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
	fmt.Println("Enter the number of elements in the sequence")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the initial value of k")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	i := 1
	req := 1
	for k-req >= 0 {
		if k-req >= 0 {
			k = k - req
		} else {
			break
		}
		i++
		if i%n!= 0 {
			req = i % n
		} else {
			req = n
		}
	}
	fmt.Println(k)
}

