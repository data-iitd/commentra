
<<<<<<< HEAD

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
=======
package main

import (
	"fmt"
	"sort"
>>>>>>> 98c87cb78a (data updated)
)

const SIZE = (1e5 * 2) + 13

func main() {
<<<<<<< HEAD
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	k, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	a := make([]int, 0)
	cnt := make([]int, SIZE)
	for i := 0; i < n; i++ {
		x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		cnt[x]++
	}
	for i := 0; i < cnt.size(); i++ {
=======
	var n, k int
	fmt.Scanf("%d %d\n", &n, &k)
	cnt := make([]int, SIZE)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d\n", &x)
		cnt[x]++
	}
	a := make([]int, 0)
	for i := 0; i < len(cnt); i++ {
>>>>>>> 98c87cb78a (data updated)
		if cnt[i] > 0 {
			a = append(a, cnt[i])
		}
	}
<<<<<<< HEAD
	ans := 0
	sort.Ints(a)
	m := len(a) - k
=======
	sort.Ints(a)
	m := len(a) - k
	ans := 0
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i < m; i++ {
		ans += a[i]
	}
	fmt.Println(ans)
}

<<<<<<< HEAD
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

=======
>>>>>>> 98c87cb78a (data updated)
