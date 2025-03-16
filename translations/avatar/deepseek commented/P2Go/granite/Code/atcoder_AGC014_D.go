
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	readBuf  [1024]byte
	readIdx   = 0
	readLen   = 0
	writeBuf  [1024]byte
	writeIdx  = 0
)

func read() (r rune) {
	if readIdx == readLen {
		readLen = len(os.Stdin.Read(readBuf[:]))
		readIdx = 0
	}
	r, readIdx = rune(readBuf[readIdx]), readIdx+1
	return
}

func readInt() (r int) {
	for {
		c := read()
		if c =='' {
			break
		}
		r = r*10 + int(c-'0')
	}
	return
}

func readString() (r string) {
	for {
		c := read()
		if c =='' {
			break
		}
		r += string(c)
	}
	read()
	return
}

func readLine() (r string) {
	for {
		c := read()
		if c == '\n' {
			break
		}
		r += string(c)
	}
	read()
	return
}

func flush() {
	os.Stdout.Write(writeBuf[:writeIdx])
	writeIdx = 0
}

func writeInt(x int, width int) {
	writeByte(rune(x/10%10 + '0'))
	writeByte(rune(x%10 + '0'))
	for i := width - 2; i > 0; i-- {
		writeByte(' ')
	}
}

func writeString(s string) {
	for _, c := range s {
		writeByte(c)
	}
}

func writeByte(b rune) {
	if writeIdx == len(writeBuf) {
		flush()
	}
	writeBuf[writeIdx] = b
	writeIdx++
}

func main() {
	N := readInt()
	adj := make([][]int, N+1)
	for i := 0; i < N-1; i++ {
		a := readInt()
		b := readInt()
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}
	que := make([]int, N)
	head, tail := 0, 0
	que[tail] = 1
	tail++
	seen := make([]bool, N+1)
	seen[1] = true
	par := make([]int, N+1)
	childNum := make([]int, N+1)
	for head < tail {
		v := que[head]
		head++
		for _, u := range adj[v] {
			if!seen[u] {
				seen[u] = true
				par[u] = v
				childNum[v]++
				que[tail] = u
				tail++
			}
		}
	}
	seq := make([]int, N)
	head, tail = 0, 0
	for i := 1; i <= N; i++ {
		if childNum[i] == 0 {
			seq[tail] = i
			tail++
		}
	}
	for head < tail {
		c := seq[head]
		head++
		seen[c] = false
		if seen[par[c]] {
			writeByte('F')
			writeByte('i')
			writeByte('r')
			writeByte('s')
			writeByte('t')
			writeByte('\n')
			flush()
			os.Exit(0)
		}
		seen[par[par[c]]] = false
		childNum[par[par[c]]]--
		if childNum[par[par[c]]] == 0 {
			seq[tail] = par[par[c]]
			tail++
		}
	}
	writeByte('S')
	writeByte('e')
	writeByte('c')
	writeByte('o')
	writeByte('n')
	writeByte('d')
	writeByte('\n')
	flush()
}

