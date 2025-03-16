
package main

import (
"bufio"
"fmt"
"io"
"os"
"strconv"
"strings"
)

func main() {
r := bufio.NewReaderSize(os.Stdin, 1)
s, _ := r.ReadString('\n')
s = strings.TrimSpace(s)
fmt.Printf("%c\n", s[0]+1)
}

type RemRing struct {
module int64
}

func NewRemRing(module int64) *RemRing {
return &RemRing{module}
}

func (r *RemRing) Sum(a, b int64) int64 {
return (a + b + r.module) % r.module
}

func (r *RemRing) Sub(a, b int64) int64 {
return (a - b + r.module) % r.module
}

func (r *RemRing) Prod(a, b int64) int64 {
return (a * b) % r.module
}

func (r *RemRing) Div(a, b int64) int64 {
return (a * r.Inv(b)) % r.module
}

func (r *RemRing) Inv(a int64) int64 {
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

