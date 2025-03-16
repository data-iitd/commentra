
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var a [5]int
	var r [5]int
	var map map[int]int

	// Step 2: Reading input and storing remainders
	for i := 0; i < 5; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
		r[i] = a[i] % 10
		if r[i]!= 0 {
			if map == nil {
				map = make(map[int]int)
			}
			map[10-r[i]] = a[i]
		}
	}

	// Step 3: Handling edge cases
	if map == nil {
		var ans int
		for i := 0; i < 5; i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	// Step 4: Finding the maximum and adjusting values
	var last int
	for _, v := range map {
		last = v
	}
	var idx int
	for i := 0; i < 5; i++ {
		if a[i] == last {
			idx = i
		}
	}
	var ans int
	for i := 0; i < 5; i++ {
		if i!= idx {
			if a[i]%10 == 0 {
				ans += a[i]
			} else {
				ans += a[i] + (10 - r[i])
			}
		}
	}
	ans += last
	fmt.Println(ans)
}

