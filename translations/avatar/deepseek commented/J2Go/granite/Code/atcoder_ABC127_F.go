
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
	writer := bufio.NewWriter(os.Stdout)

	var t int
	fmt.Fscanf(reader, "%d\n", &t)

	var min int
	pq1 := make([]int, 0)
	pq2 := make([]int, 0)
	var sum1, sum2, sum3 int64

	for t > 0 {
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)
		s = strings.Replace(s, "\r", "", -1)
		s = strings.Replace(s, "\n", "", -1)

		if s[0] == '2' {
			ans := int64(min)
			ans *= int64(len(pq1))
			ans -= sum1
			ans1 := int64(min)
			ans1 *= int64(len(pq2))
			ans1 = sum2 - ans1
			fmt.Fprintf(writer, "%d %d\n", min, ans+ans1+sum3)
		} else {
			a := strings.Split(s, " ")
			in, _ := strconv.Atoi(a[1])
			sum3 += int64(mustParseInt(a[2]))

			if in > min {
				pq2 = append(pq2, in)
				sum2 += int64(in)
			} else {
				pq1 = append(pq1, in)
				sum1 += int64(in)
			}

			if len(pq1) > len(pq2)+1 {
				x := pq1[0]
				pq1 = pq1[1:]
				sum1 -= int64(x)
				pq2 = append(pq2, x)
				sum2 += int64(x)
				sort.Ints(pq2)
			} else if len(pq2) > len(pq1) {
				x := pq2[len(pq2)-1]
				pq2 = pq2[:len(pq2)-1]
				sum2 -= int64(x)
				pq1 = append(pq1, x)
				sum1 += int64(x)
				sort.Sort(sort.Reverse(sort.IntSlice(pq1)))
			}

			if len(pq1) > 0 {
				min = pq1[0]
			} else {
				min = pq2[len(pq2)-1]
			}
		}

		t--
	}

	writer.Flush()
}

func mustParseInt(s string) int {
	n, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return n
}

