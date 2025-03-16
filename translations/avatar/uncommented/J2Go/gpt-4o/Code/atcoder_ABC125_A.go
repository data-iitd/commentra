package main

import (
	"fmt"
)

func main() {
	var sec, perNum, maxSec int
	fmt.Scan(&sec)
	fmt.Scan(&perNum)
	fmt.Scan(&maxSec)

	maxSec = int(float64(maxSec) + 0.5)
	ansNum := 0

	for i := sec; i < maxSec; i += sec {
		ansNum += perNum
	}

	fmt.Println(ansNum)
}

// <END-OF-CODE>
