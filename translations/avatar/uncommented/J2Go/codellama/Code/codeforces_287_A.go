
package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	str := make([]string, 4)
	i := -1
	for i != 3 {
		i++
		sc.Scan()
		str[i] = sc.Text()
	}
	u := -1
	i = -1
	yes := 0
	for u != 2 {
		u++
		i = -1
		for i != 2 {
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
	}
	if yes == 0 {
		fmt.Println("NO")
	}
}

