
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var A, B, C string
	fmt.Fscanf(reader, "%s %s %s\n", &A, &B, &C)

	la := len(A)
	lb := len(B)

	if A[la-1] == B[0] && B[lb-1] == C[0] {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

