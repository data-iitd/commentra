package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)
	scan.Scan()
	N, _ := strconv.ParseInt(scan.Text(), 10, 64)
	scan.Scan()
	A, _ := strconv.ParseInt(scan.Text(), 10, 64)
	scan.Scan()
	B, _ := strconv.ParseInt(scan.Text(), 10, 64)
	k := int64(0)
	if 1 <= N && N <= int64(math.Pow(10, 18)) && 0 <= A && 0 <= B && 0 < A+B && A+B <= int64(math.Pow(10, 18)) {
		if A+B <= N {
			k = N / (A + B)
			if N-k*(A+B) > A {
				fmt.Println(A*k + (N-k*(A+B)) - (N-(k*(A+B)+A)))
			} else {
				fmt.Println(A*k + (N-k*(A+B)))
			}
		} else if A+B > N && A <= N {
			fmt.Println(A)
		} else {
			fmt.Println(N)
		}
	}
}

