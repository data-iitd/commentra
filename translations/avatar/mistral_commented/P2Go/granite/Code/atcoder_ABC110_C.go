
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	s := readString(reader)
	t := readString(reader)

	res := run(s, t)

	fmt.Println(res)
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
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

func solve(s string, t string) string {
	cnt1 := make(map[byte]int)
	cnt2 := make(map[byte]int)

	for i := 0; i < len(s); i++ {
		cnt1[s[i]]++
	}

	for i := 0; i < len(t); i++ {
		cnt2[t[i]]++
	}

	var buf bytes.Buffer

	for i := 0; i < 26; i++ {
		b := byte(i + 'a')
		if cnt1[b]!= cnt2[b] {
			return "No"
		}
	}

	return "Yes"
}

func run(s string, t string) string {
	return solve(s, t)
}

func main1() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		s := readString(reader)
		t := readString(reader)
		res := solve(s, t)
		fmt.Println(res)
	}
}

func main2() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		s := readString(reader)
		t := readString(reader)
		res := solve(s, t)
		buf.WriteString(res)
		buf.WriteByte('\n')
	}

	fmt.Print(buf.String())
}

func main3() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(n, A)
		fmt.Println(res)
	}
}

func main4() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(n, A)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main5() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main6() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main7() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main8() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main9() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main10() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main11() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main12() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main13() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main14() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main15() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main16() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main17() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main18() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main19() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main20() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main21() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main22() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main23() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main24() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main25() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main26() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main27() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main28() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main29() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		fmt.Println(res)
	}
}

func main30() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	var buf bytes.Buffer

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		A := readNNums(reader, n)
		B := readNNums(reader, m)
		res := solve(n, A, m, B)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func main31() {
	reader := bufio.NewReader(os.Stdin)

	tc := r