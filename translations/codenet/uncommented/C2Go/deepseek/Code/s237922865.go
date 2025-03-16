package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	cnt4, cnt2 := 0, 0
	//4の倍数
	//4の倍数出ないが、2の倍数/2
	//の合計がn/2より大きい
	for i := 0; i < n; i++ {
		var wk int
		fmt.Scan(&wk)
		if wk%4 == 0 {
			cnt4++
		} else if wk%2 == 0 {
			cnt2++
		}
	}

	if cnt4+(cnt2/2) >= n/2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

