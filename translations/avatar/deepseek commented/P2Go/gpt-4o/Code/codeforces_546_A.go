package main

import (
	"fmt"
	"strconv"
)

func main() {
	var kStr, nStr, wStr string
	fmt.Scan(&kStr, &nStr, &wStr)
	
	k, _ := strconv.Atoi(kStr)
	n, _ := strconv.Atoi(nStr)
	w, _ := strconv.Atoi(wStr)

	if 1 <= k && w <= 1000 {
		total := 0
		for i := 1; i <= w; i++ {
			total += i * k
		}
		if total > n {
			fmt.Println(total - n)
		} else {
			fmt.Println(0)
		}
	}
}
// <END-OF-CODE>
