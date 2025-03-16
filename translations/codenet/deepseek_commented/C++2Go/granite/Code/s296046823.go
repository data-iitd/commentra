
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var N, K int
	fmt.Fscanf(reader, "%d %d\n", &N, &K) // 1. Reading the values of N and K from the standard input.

	v := make([]int, N) // 2. Initializing a slice of size N to store N integers.
	for i := 0; i < N; i++ {
		s, _ := reader.ReadString('\n') // 3. Reading N integers from the standard input and storing them in the slice v.
		v[i], _ = strconv.Atoi(strings.TrimSpace(s))
	}

	// 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
	count := (N-1)/(K-1)
	if (N-1)%(K-1)!= 0 {
		count++
	}
	fmt.Println(count) // 5. Outputting the calculated count.
}

