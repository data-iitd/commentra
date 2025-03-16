
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	n, b := 0, 0
	ans := make([]int, 0)
	q := make([]int, 0)

	// Read the number of tasks
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())

	// Read the buffer size
	sc.Scan()
	b, _ = strconv.Atoi(sc.Text())

	// Process each task
	for i := 0; i < n; i++ {
		sc.Scan()
		t, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		d, _ := strconv.Atoi(sc.Text())

		// Remove completed tasks from the front of the queue
		for len(q) > 0 && q[0] <= t {
			q = q[1:]
		}

		// Check if the task can be added to the buffer
		if len(q) <= b {
			ans = append(ans, 0)
			if len(q) == 0 {
				ans[i] = t
			} else {
				ans[i] = q[len(q)-1]
			}
			q = append(q, ans[i]+d)
		} else {
			ans = append(ans, -1)
		}
	}

	// Output the completion times of all tasks
	for _, v := range ans {
		fmt.Printf("%d ", v)
	}
}

