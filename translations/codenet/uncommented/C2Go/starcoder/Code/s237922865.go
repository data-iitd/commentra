package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d\n", &n)

	cnt4 := 0
	cnt2 := 0
	for i := 0; i < n; i++ {
		var wk int
		fmt.Scanf("%d\n", &wk)
		if wk%4 == 0 {
			cnt4++
		} else if wk%2 == 0 {
			cnt2++
		}
	}

	if cnt4+cnt2/2 >= n/2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

