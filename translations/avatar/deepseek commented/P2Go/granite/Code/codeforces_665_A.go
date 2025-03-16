
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables
	var a, at, b, bt, t1, t2, st, fin, now, ans int

	// Read input from the user
	data := bufio.NewReader(os.Stdin)
	a, _ = strconv.Atoi(strings.TrimSpace(readLine(data)))
	at, _ = strconv.Atoi(strings.TrimSpace(readLine(data)))
	b, _ = strconv.Atoi(strings.TrimSpace(readLine(data)))
	bt, _ = strconv.Atoi(strings.TrimSpace(readLine(data)))
	t1, _ = strconv.Atoi(strings.TrimSpace(readLine(data)))
	t2, _ = strconv.Atoi(strings.TrimSpace(readLine(data)))

	// Calculate the start time
	st = t2 + (t1-5)*60

	// Calculate the finish time
	fin = st + at

	// Initialize now and ans variables
	now = 0
	ans = 0

	// Loop until now is less than fin and now is less than 1140
	for now < fin && now < 1140 {
		if now+bt > st { // Check if adding bt to now would exceed the start time
			ans++ // Increment ans if the condition is met
		}
		now += b // Increment now by b
	}

	// Print the final value of ans
	fmt.Println(ans)
}

func readLine(data *bufio.Reader) string {
	res, _ := data.ReadString('\n')
	return res
}

