
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	vec := make([][]int, n)
	for i := 0; i < n; i++ {
		line := reader.ReadLine()[2 : len(reader.ReadLine())]
		vec[i] = make([]int, 4)
		vec[i][0], _ = strconv.Atoi(line[:len(line)-1])
		line = reader.ReadLine()[2 : len(reader.ReadLine())]
		vec[i][1], _ = strconv.Atoi(line[:len(line)-1])
		line = reader.ReadLine()[2 : len(reader.ReadLine())]
		vec[i][2], _ = strconv.Atoi(line[:len(line)-1])
		line = reader.ReadLine()[2 : len(reader.ReadLine())]
		vec[i][3], _ = strconv.Atoi(line[:len(line)-1])
	}
	ans := 500
	ansPrice := 200000
	for i := 0; i < n; i++ {
		fl := true
		for j := 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				fl = false
			}
		}
		if fl {
			if vec[i][3] < ansPrice {
				ansPrice = vec[i][3]
				ans = i + 1
			}
		}
	}
	fmt.Println(ans)
}

