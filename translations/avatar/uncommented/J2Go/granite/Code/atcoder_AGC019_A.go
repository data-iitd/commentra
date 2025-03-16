
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var Q, H, S, D, N int64
	fmt.Fscanf(r, "%d\n", &Q)
	fmt.Fscanf(r, "%d\n", &H)
	fmt.Fscanf(r, "%d\n", &S)
	fmt.Fscanf(r, "%d\n", &D)
	fmt.Fscanf(r, "%d\n", &N)
	onePrice := int64(math.Min(math.Min(float64(Q*4), float64(H*2)), float64(S)))
	if float64(onePrice) <= float64(D/2) {
		fmt.Fprintf(w, "%d\n", N*onePrice)
	} else {
		fmt.Fprintf(w, "%d\n", (N/2)*D+(N%2)*onePrice)
	}
	w.Flush()
}

