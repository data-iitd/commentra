
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the string and the number of elements to be removed from the string")
	n, k := readNums(reader)
	fmt.Println("Enter the string")
	s := readString(reader)
	count := make([]int, 26)
	for _, c := range s {
		count[c-'A']++
	}
	sort.Slice(count, func(i, j int) bool {
		return count[i] > count[j]
	})
	res := 0
	for i := 0; i < 26; i++ {
		if count[i] >= k {
			res += k * k
			fmt.Println(res)
			return
		}
		k -= count[i]
		res += count[i] * count[i]
	}
	fmt.Println(res)
}

func readString(reader *bufio.Reader) string {
	str, _, err := reader.ReadRune()
	if err!= nil {
		panic(err)
	}
	var sb strings.Builder
	for str!= '\n' {
		sb.WriteRune(str)
		str, _, err = reader.ReadRune()
		if err!= nil {
			panic(err)
		}
	}
	return sb.String()
}

func readNums(reader *bufio.Reader) (int, int) {
	line, _, err := reader.ReadRune()
	if err!= nil {
		panic(err)
	}
	nums := strings.Split(string(line), " ")
	n, _ := strconv.Atoi(nums[0])
	k, _ := strconv.Atoi(nums[1])
	return n, k
}

