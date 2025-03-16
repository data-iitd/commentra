package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	str := make([]string, 4)
	i := -1
	for i != 3 {
		i++
		scanner.Scan()
		str[i] = scanner.Text()
	}
	u := -1
	for u != 2 {
		u++
		i := -1
		for i != 2 {
			i++
			if (str[u][i] == str[u][i+1] && (str[u+1][i] == str[u][i] || str[u+1][i+1] == str[u][i])) || (str[u+1][i] == str[u+1][i+1] && (str[u][i] == str[u+1][i] || str[u][i+1] == str[u+1][i])) {
				fmt.Println("YES")
				return
			}
		}
	}
	fmt.Println("NO")
}

