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
	fmt.Println("Enter the number of test cases")
	tc, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	for i := 0; i < tc; i++ {
		fmt.Println("Enter the number of colors")
		n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		fmt.Println("Enter the colors")
		s := strings.TrimSpace(reader.ReadString())
		rc, gc, bc := 0, 0, 0
		for _, c := range s {
			if c == 'R' {
				rc++
			} else if c == 'G' {
				gc++
			} else {
				bc++
			}
		}
		result := rc * gc * bc
		for i := 1; i <= n; i++ {
			for k := i + 1; k <= n; k++ {
				if (i+k)%2 == 0 {
					is, ks, js := s[i-1], s[k-1], s[(i+k)/2-1]
					if is!= ks && ks!= js && js!= is {
						result--
					}
				}
			}
		}
		fmt.Println(result)
	}
}

