
package main
import (
    "bufio"
    "bytes"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)
func main() {
    reader := bufio.NewReader(os.Stdin)
    var s string
    _, _ = fmt.Fscan(reader, &s)
    var t string
    _, _ = fmt.Fscan(reader, &t)
    ss := make([]int, 0)
    tt := make([]int, 0)
    for _, v := range strings.Split(s, "") {
        count, _ := strconv.Atoi(string(v))
        ss = append(ss, count)
    }
    for _, v := range strings.Split(t, "") {
        count, _ := strconv.Atoi(string(v))
        tt = append(tt, count)
    }
    sort.Ints(ss)
    sort.Ints(tt)
    if bytes.Equal(Int32ToBytes(int32(ss)), Int32ToBytes(int32(tt))) {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}
func Int32ToBytes(n int32) []byte {
    var x uint32 = uint32(n)
    bytesBuffer := bytes.NewBuffer([]byte{})
    _ = binary.Write(bytesBuffer, binary.BigEndian, x)
    return bytesBuffer.Bytes()
}
