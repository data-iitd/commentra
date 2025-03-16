
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var (
		len int
		err error
		a   []int
		key int
		i   int
		j   int
	)

	reader := bufio.NewReader(os.Stdin)

	if len, err = strconv.Atoi(reader.ReadLine()); err!= nil {
		panic(err)
	}

	a = make([]int, len)

	for i = 0; i < len; i++ {
		if a[i], err = strconv.Atoi(reader.ReadLine()); err!= nil {
			panic(err)
		}
	}

	for j = 1; j < len; j++ {
		for i = 0; i < len; i++ {
			fmt.Printf("%d ", a[i])
		}
		fmt.Println()
		key = a[j]
		for i = j - 1; i >= 0 && a[i] > key; i-- {
			a[i+1] = a[i]
		}
		a[i+1] = key
	}

	for i = 0; i < len; i++ {
		fmt.Printf("%d ", a[i])
	}
	fmt.Println()
}

