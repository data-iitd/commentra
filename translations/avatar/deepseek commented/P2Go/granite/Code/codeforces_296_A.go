

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

	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	m := strings.Split(readLine(reader), " ")

	possible := true

	for i := range m {
		m[i] = strings.TrimSpace(m[i])
	}

	m = removeDuplicates(m)

	for _, v := range m {
		count := 0
		for _, x := range m {
			if x == v {
				count++
			}
		}
		if count >= n/2+1 {
			possible = false
			break
		}
	}

	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

func removeDuplicates(elements []string) []string {
	 encountered := map[string]bool{}
	result := []string{}

	for v := range elements {
		if encountered[elements[v]] == true {
			continue
		}
		encountered[elements[v]] = true
		result = append(result, elements[v])
	}
	return result
}

