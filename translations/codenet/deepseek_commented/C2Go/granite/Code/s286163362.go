
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	for {
		n, k := nextTwoInt64(reader)
		if n == 0 && k == 0 {
			break
		}

		data := make([]int, n+1)
		for i := 0; i < int(k); i++ {
			t := nextInt64(reader)
			data[int(t)]++
		}

		seq := make([]int, 0, 2*int(n))
		p := 0
		for i := 1; i <= int(n); i++ {
			if data[i] > 0 {
				seq = append(seq, data[i])
			} else {
				p += 2
			}
		}
		seq = append(seq, 0)

		ret := 0
		if data[0] > 0 {
			for i := 0; i < len(seq); i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i := 0; i < len(seq); i++ {
				ret = max(ret, seq[i])
			}
		}

		fmt.Println(ret)
	}
}

func nextInt64(r *bufio.Reader) int64 {
	res, err := r.ReadBytes('\n')
	if err!= nil {
		panic(err)
	}

	res = bytes.TrimSpace(res)
	return int64(nextInt64FromBytes(res))
}

func nextTwoInt64(r *bufio.Reader) (int64, int64) {
	res, err := r.ReadBytes('\n')
	if err!= nil {
		panic(err)
	}

	res = bytes.TrimSpace(res)

	var n1, n2 int64
	tmp := bytes.Split(res, []byte{' '})
	n1 = int64(nextInt64FromBytes(tmp[0]))
	n2 = int64(nextInt64FromBytes(tmp[1]))

	return n1, n2
}

func nextInt64FromBytes(bs []byte) int64 {
	var ret int64

	for i := 0; i < len(bs); i++ {
		ret *= 10
		ret += int64(bs[i]-'0')
	}

	return ret
}