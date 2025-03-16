package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	str := make([]string, 4)
	i := -1
	for i!= 3 {
		i++
		str[i], _ = sc.ReadString('\n')
	}
	u := -1
	i = -1
	yes := 0
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
	}
	if yes == 0 {
		fmt.Println("NO")
	}
}

