package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var N, A, B, k int64
	var err error
	if len(os.Args) < 4 {
		fmt.Println("Usage:", os.Args[0], "N A B")
		os.Exit(1)
	}
	N, err = strconv.ParseInt(os.Args[1], 10, 64)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
	A, err = strconv.ParseInt(os.Args[2], 10, 64)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
	B, err = strconv.ParseInt(os.Args[3], 10, 64)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
	if 1 <= N && N <= math.Pow10(18) && 0 <= A && 0 <= B && 0 < A+B && A+B <= math.Pow10(18) {
		if A+B <= N {
			k = N / (A + B)
			if N-k*(A+B) > A {
				fmt.Println(A*k + (N - k*(A+B)) - (N - (k*(A+B) + A)))
			} else {
				fmt.Println(A*k + (N - k*(A+B)))
			}
		} else if A+B > N && A <= N {
			fmt.Println(A)
		} else {
			fmt.Println(N)
		}
	}
}

