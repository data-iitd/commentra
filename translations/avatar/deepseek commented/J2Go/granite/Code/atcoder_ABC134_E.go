
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, _ := fmt.Fscanf(reader, "%d\n", &n)

	freq := make(map[int]int)

	for i := 0; i < n; i++ {
		var num int
		fmt.Fscanf(reader, "%d\n", &num)

		if _, ok := freq[num];!ok {
			freq[num] = 1
		} else {
			freq[num]++
		}

		if lower, ok := freq[num-1]; ok && lower > 0 {
			freq[num-1]--
			if freq[num-1] == 0 {
				delete(freq, num-1)
			}
		}
	}

	sum := 0
	for _, v := range freq {
		sum += v
	}

	fmt.Println(sum)
}

