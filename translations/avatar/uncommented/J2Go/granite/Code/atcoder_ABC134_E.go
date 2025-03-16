
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
	mp := make(map[int]int)
	for n > 0 {
		num, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		if _, ok := mp[num];!ok {
			mp[num] = 1
		} else {
			delete(mp, num)
		}
		if lower, ok := mp.lowerKey(num); ok {
			mp[lower]++
		}
		n--
	}
	ans := 0
	for _, v := range mp {
		ans += v
	}
	fmt.Println(ans)
}

func (mp map[int]int) lowerKey(key int) (int, bool) {
	for k := range mp {
		if k < key {
			return k, true
		}
	}
	return 0, false
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

