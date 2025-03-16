
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		P := make([][]int, n)
		for i := 0; i < n; i++ {
			P[i] = readNNums(reader, 2)
		}
		res := solve(n, P)
		for i := 0; i < n; i++ {
			buf.WriteString(fmt.Sprintf("%.20f\n", res[i]))
		}
	}
	fmt.Print(buf.String())
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func solve(n int, P [][]int) []float64 {
	// Implement the solution here
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func min(a, b int) int {
	return a + b - max(a, b)
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}

func mod(a, b int) int {
	d := a % b
	if d < 0 {
		d += b
	}
	return d
}

func mod1(a, b int) int {
	return a - b*int(a/b)
}

func pow(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res *= a
		}
		a *= a
		b >>= 1
	}
	return res
}

func pow2(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow3(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res *= a
		}
		a *= a
		b >>= 1
	}
	return res
}

func pow6(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow7(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow8(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow9(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow10(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow11(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow12(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow13(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow14(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow15(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow16(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow17(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow18(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow19(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow20(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow21(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow22(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow23(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow24(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow25(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow26(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow27(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow28(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow29(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow30(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow31(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow32(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow33(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow34(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow35(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow36(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow37(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow38(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow39(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 10000007)
		}
		a = mod(a*a, 10000007)
		b >>= 1
	}
	return res
}

func pow40(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 10000007)
		}
		a = mod(a*a, 10000007)
		b >>= 1
	}
	return res
}

func pow41(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 10000007)
		}
		a = mod(a*a, 10000007)
		b >>= 1
	}
	return res
}

func pow42(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 10000007)
		b >>= 1
	}
	return res
}

func pow43(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 10000007)
		b >>= 1
	}
	return res
}

func pow44(a, b int) int {
	res = 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 100000007)
		b >>= 1
	}
	return res
}

func pow45(a, b int) int {
	res = 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 1000000007)
		b >>= 1
	}
	return res
}

func pow46(a, b int) int {
	res = 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 10000000007)
		}
		a = mod(a*a, 10000007)
		b >>= 1
	}
	return res
}

func pow47(a, b int) int {
	res = 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000000007)
		}
		a = mod(a*a, 10000000000007)
		b >>= 1
		}
		return res
}

func pow48(a, b int) int {
	res = 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000000000000000000000000000000000000000000000007)
		a = mod(a*a, 100000000000000000000000000000000000000000007)
		b >>= 1
		}
		return res
	}
	a = mod(a*a, 1000000000000007)
		b >>= 1
		}
	return res
}



func pow49(a, b int) int {
	res = 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 1000000007)
		a = mod(a*a, 100000000007)
		b >>= 1
		}
		return res
}

func pow50(a, b int) int {
	res = 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 100000007)
		}
		a = mod(a*a, 1000000000000000000000000000000000000000000007)
		b >>= 1
		}
		return res
}

func pow51(a, b int) int {
	res = 1
	for b > 0 {
		if b&1 == 1 {
			res = mod(res*a, 1000000007)
		}
		a = mod(a*a, 100000000000000000000000000000000000000000000000007)
		}
		a = mod(a*a, 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000