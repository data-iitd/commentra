
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
	N, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	map_ := make(map[int]string)
	for i := 0; i < N; i++ {
		tmp := strings.Split(reader.ReadLine(), " ")
		map_[i], _ = strconv.Atoi(tmp[1])
	}
	ans := true
	past := make(map[int]string)
	next := ""
	for i := 0; i < N; i++ {
		if _, ok := past[map_[i]]; ok {
			ans = false
			break
		}
		past[map_[i]] = ""
		if i!= 0 {
			if next!= string(map_[i])[0:1] {
				ans = false
				break
			}
		}
		next = string(map_[i])[len(map_[i])-1 : len(map_[i])]
	}
	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
