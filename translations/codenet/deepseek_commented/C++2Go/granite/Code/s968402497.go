
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the value of tc:")
	tc, _ := reader.ReadString('\n')
	tc = tc[:len(tc)-1]
	fmt.Println("Enter the value of n:")
	n, _ := reader.ReadString('\n')
	n = n[:len(n)-1]
	fmt.Println("Enter the value of m:")
	m, _ := reader.ReadString('\n')
	m = m[:len(m)-1]
	tcInt, _ := strconv.Atoi(tc)
	nInt, _ := strconv.Atoi(n)
	mInt, _ := strconv.Atoi(m)
	if nInt > mInt {
		temp := nInt
		nInt = mInt
		mInt = temp
	}
	for i := 1; i <= mInt; i++ {
		if i*tcInt >= nInt && i*tcInt <= mInt {
			fmt.Println("OK")
			return
		}
	}
	fmt.Println("NG")
}

