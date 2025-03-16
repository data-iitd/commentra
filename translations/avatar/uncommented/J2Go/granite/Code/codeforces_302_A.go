
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	k, _ := strconv.Atoi(reader.ReadLine()[2:])
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadLine()[2:])
	}
	o, e := 0, 0
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++
		} else {
			e++
		}
	}
	for i := 0; i < k; i++ {
		l, _ := strconv.Atoi(reader.ReadLine()[2:])
		r, _ := strconv.Atoi(reader.ReadLine()[2:])
		if (r-l+1)%2 == 1 {
			fmt.Println("0")
		} else {
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				fmt.Println("1")
			} else {
				fmt.Println("0")
			}
		}
	}
}

