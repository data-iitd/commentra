
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	array := make([]int, 3*n)
	for i := 0; i < 3*n; i++ {
		array[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	}
	sort.Ints(array)
	head := 3*n - 2
	res := int64(0)
	for i := 0; i < n; i++ {
		res += int64(array[head])
		head -= 2
	}
	fmt.Println(res)
}

