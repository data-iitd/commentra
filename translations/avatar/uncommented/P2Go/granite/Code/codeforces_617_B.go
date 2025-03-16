
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
	fmt.Fscanf(reader, "%d\n", new(int))
	fmt.Fscanf(reader, "%s\n", new(string))
	s := strings.TrimSpace(*new(string))
	if strings.Count(s, "1") == 0 {
		fmt.Println(0)
	} else {
		var ans int64 = 1
		for _, v := range strings.Split(s, "1") {
			ans *= int64(len(v) + 1)
		}
		fmt.Println(ans)
	}
}
