package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

	fmt.Println("Enter the number of elements in the array")
	N, err := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	checkError(err)

	fmt.Println("Enter the number of elements in the modulo")
	M, err := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	checkError(err)

	fmt.Println("Enter the array elements")
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], err = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		checkError(err)
	}

	cum_remainders := make([]int, N + 1)
	cum_remainders[0] = 0
	for i := 0; i < N; i++ {
		cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M
	}

	remainder_counts := make(map[int]int)
	for i := 0; i < N; i++ {
		remainder_counts[cum_remainders[i]]++
	}

	combinations := 0
	for count := range remainder_counts {
		combinations += count * (count - 1) / 2
	}
	fmt.Println(combinations)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

