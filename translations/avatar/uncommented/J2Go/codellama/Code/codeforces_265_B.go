package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	scn := bufio.NewScanner(os.Stdin)
	scn.Split(bufio.ScanWords)
	var n int
	scn.Scan()
	n, _ = strconv.Atoi(scn.Text())
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scn.Scan()
		arr[i], _ = strconv.Atoi(scn.Text())
	}
	ans := arr[0] + 1
	for i := 1; i < n; i++ {
		ans += int(math.Abs(float64(arr[i]-arr[i-1]))) + 2
	}
	fmt.Println(ans)
}

