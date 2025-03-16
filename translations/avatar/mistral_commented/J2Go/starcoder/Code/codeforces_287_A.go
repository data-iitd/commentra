
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var str [4]string
	var i int = -1
	var u int = -1
	var yes int = 0

	reader := bufio.NewReader(os.Stdin)
	for i!= 3 {
		i++
		str[i], _ = reader.ReadString('\n')
	}

	for u!= 2 {
		u++
		i = -1
		for i!= 2 {
			i++
			if (str[u][i] == str[u][i+1] && (str[u+1][i] == str[u][i] || str[u+1][i+1] == str[u][i])) || (str[u+1][i] == str[u+1][i+1] && (str[u][i] == str[u+1][i] || str[u][i+1] == str[u+1][i])) {
				yes = 1
				fmt.Println("YES")
				break
			}
		}
		if yes == 1 {
			break
		}
		if yes == 0 {
			fmt.Println("NO")
		}
	}
}

