package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')
	n = strings.TrimSpace(n)
	nInt, _ := strconv.Atoi(n)

	q := [][]string{}
	count := 0

	for i := 0; i < nInt; i++ {
		a, _ := reader.ReadString('\n')
		a = strings.TrimSpace(a)
		split := strings.Split(a, " ")
		q = append(q, split)
	}

	for _, j := range q {
		for _, k := range q {
			if strings.Join(j, "") == strings.Join(k, "") {
				continue
			}
			if j[0] == k[len(k)-1] {
				count++
			}
		}
	}

	fmt.Println(count)
}

