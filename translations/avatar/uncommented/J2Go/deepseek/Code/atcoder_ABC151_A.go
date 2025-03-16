package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	fmt.Printf("%c", s[0]+1)
}

type RemRing struct {
	module int64
}

func (r *RemRing) sum(a, b int64) int64 {
	return (a + b + r.module) % r.module
}

func (r *RemRing) sub(a, b int64) int64 {
	return (a - b + r.module) % r.module
}

func (r *RemRing) prod(a, b int64) int64 {
	return (a * b) % r.module
}

func (r *RemRing) div(a, b int64) int64 {
	return (a * r.inv(b)) % r.module
}

func (r *RemRing) inv(a int64) int64 {
	b := r.module
	u := int64(1)
	v := int64(0)
	for b > 0 {
		t := a / b
		a -= t * b
		u -= t * v
		a, b = b, a
		u, v = v, u
	}
	u %= r.module
	if u < 0 {
		u += r.module
	}
	return u
}
