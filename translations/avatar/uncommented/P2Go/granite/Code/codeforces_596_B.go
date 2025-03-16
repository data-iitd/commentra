
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    n, _ := strconv.Atoi(read())
    r := read_int_array()
    ans := int(math.Abs(float64(r[0])))
    for i := 1; i < n; i++ {
        ans += int(math.Abs(float64(r[i]-r[i-1])))
    }
    fmt.Println(ans)
}

func read() string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := in.ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return string(buf)
}

func read_int() int {
    str, _ := in.ReadString('\n')
    num, _ := strconv.Atoi(str)
    return num
}

func read_string() string {
    str, _ := in.ReadString('\n')
    return str
}

func read_int_array() []int {
    line := read_string()
    tokens := strings.Split(line, " ")
    num_array := make([]int, len(tokens))
    for i, num_string := range tokens {
        num, _ := strconv.Atoi(num_string)
        num_array[i] = num
    }
    return num_array
}

func read_string_array() []string {
    line := read_string()
    tokens := strings.Split(line, " ")
    return tokens
}

