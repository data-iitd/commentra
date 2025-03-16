
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var word1, word2, word3 string
	scanner.Scan()
	word1 = scanner.Text()
	scanner.Scan()
	word2 = scanner.Text()
	scanner.Scan()
	word3 = scanner.Text()
	scanner.Scan()
	var students int
	fmt.Scan(&students)
	scanner.Scan()
	for i := 0; i < students; i++ {
		scanner.Scan()
		testCase := scanner.Text()
		if strings.EqualFold(testCase, word1+word2+word3) || strings.EqualFold(testCase, word1+word3+word2) || strings.EqualFold(testCase, word2+word1+word3) || strings.EqualFold(testCase, word2+word3+word1) || strings.EqualFold(testCase, word3+word1+word2) || strings.EqualFold(testCase, word3+word2+word1) {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

