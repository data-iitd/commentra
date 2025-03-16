
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	source, _ := reader.ReadString('\n')
	source = strings.TrimSpace(source)

	if len(source) > 10 || len(source) < 1 {
		fmt.Println(-1)
		return
	}

	maxI := int(math.Pow(2, float64(len(source)-1)))

	sum := 0.0

	for i := 0; i < maxI; i++ {
		plus := fmt.Sprintf("%0"+strconv.Itoa(len(source)-1)+"b", i)

		number := 0.0

		working := source
		for len(plus) > 0 {
			index := strings.Index(plus, "1")
			if index == -1 {
				break
			}
			sum += mustParseFloat(working[:index+1])
			plus = plus[index+1:]
			working = working[index+1:]
		}
		sum += mustParseFloat(working)
	}

	fmt.Println(int(sum))
}

func mustParseFloat(s string) float64 {
	f, err := strconv.ParseFloat(s, 64)
	if err!= nil {
		panic(err)
	}
	return f
}

