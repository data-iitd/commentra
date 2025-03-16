
package main

import (
	"fmt"
	"math"
	"math/cmplx"
	"math/rand"
	"os"
	"sort"
	"strconv"
	"strings"
	"time"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	ans := 0
	ans += n * (n - 1) / 2
	ans += m * (m - 1) / 2
	fmt.Println(ans)
}

