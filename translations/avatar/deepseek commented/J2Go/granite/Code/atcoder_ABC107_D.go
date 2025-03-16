

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
    var N int
    fmt.Fscanf(reader, "%d\n", &N)
    arr := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Fscanf(reader, "%d", &arr[i])
    }
    tsk := Task{}
    fmt.Fprintf(&buf, "%d\n", tsk.solve(arr))
    fmt.Print(buf.String())
}

type Task struct{}

func (tsk *Task) solve(arr []int) int {
    n := len(arr)
    sorted := make([]int, n)
    copy(sorted, arr)
    sort.Ints(sorted)
    total := int64(n) * (n + 1) / 2
    l, r := 0, n-1
    for l < r {
        mid := l + (r-l)/2
        target := sorted[mid]
        cur := 0
        cnt := int64(0)
        bit := make([]int, 2*n+2)
        for i := 0; i < n; i++ {
            cur += int(arr[i] <= target)
            for x := cur + n + 1; x < len(bit); x += x & -x {
                bit[x]++
            }
            for x := cur + n; x > 0; x -= x & -x {
                cnt += int64(bit[x])
            }
        }
        if cnt >= total/2+1 {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return sorted[l]
}

// END-OF-CODE