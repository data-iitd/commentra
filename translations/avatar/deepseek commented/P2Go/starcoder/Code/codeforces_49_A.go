
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := reader.ReadString('\n')
	a = strings.TrimSpace(a)
	vo := []string{"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"}
	for i := len(a) - 1; i >= 0; i-- {
		if a[i] =='' || a[i] == '?' {
			continue
		} else {
			if a[i] == vo[0] || a[i] == vo[1] || a[i] == vo[2] || a[i] == vo[3] || a[i] == vo[4] || a[i] == vo[5] || a[i] == vo[6] || a[i] == vo[7] || a[i] == vo[8] || a[i] == vo[9] || a[i] == vo[10] || a[i] == vo[11] || a[i] == vo[12] || a[i] == vo[13] || a[i] == vo[14] {
				fmt.Println("YES")
			} else {
				fmt.Println("NO")
			}
			break
		}
	}
}

