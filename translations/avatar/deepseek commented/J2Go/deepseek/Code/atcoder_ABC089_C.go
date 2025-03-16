package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n := in.Text()
	cnt := [5]int{0, 0, 0, 0, 0}

	for i := 0; i < n; i++ {
		in.Scan()
		str := in.Text()
		switch str[0] {
		case 'M':
			cnt[0]++
		case 'A':
			cnt[1]++
		case 'R':
			cnt[2]++
		case 'C':
			cnt[3]++
		case 'H':
			cnt[4]++
		}
	}

	res := cnt[0] * cnt[1] * cnt[2]
	res += cnt[0] * cnt[1] * cnt[3]
	res += cnt[0] * cnt[1] * cnt[4]
	res += cnt[0] * cnt[2] * cnt[3]
	res += cnt[0] * cnt[2] * cnt[4]
	res += cnt[0] * cnt[3] * cnt[4]
	res += cnt[1] * cnt[2] * cnt[3]
	res += cnt[1] * cnt[2] * cnt[4]
	res += cnt[1] * cnt[3] * cnt[4]
	res += cnt[2] * cnt[3] * cnt[4]

	fmt.Fprintln(out, res)
}

