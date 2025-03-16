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
 t, _ := fmt.Sscan(in.Text(), &t)

 for i := 0; i < t; i++ {
 var n, a, b int64
 _, _ = fmt.Sscan(in.Scan(), &n, &a, &b)

 if n < a {
 fmt.Fprintln(out, "No")
 continue
 }

 if a == b {
 if n%a == 0 {
 fmt.Fprintln(out, "Yes")
 } else {
 fmt.Fprintln(out, "No")
 }
 continue
 }

 x := b / (b - a)
 if n > x*a {
 fmt.Fprintln(out, "Yes")
 continue
 }

 low := int64(1)
 high := x + 1
 ans := int64(1)

 for low <= high {
 mid := (low + high) / 2
 if mid*a < n {
 low = mid + 1
 } else {
 ans = mid
 high = mid - 1
 }
 }

 if n > (ans-1)*b && n < ans*a {
 fmt.Fprintln(out, "No")
 } else {
 fmt.Fprintln(out, "Yes")
 }
 }
}

