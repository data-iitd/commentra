
package main

import (
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
    "time"
)

func main() {
    // Reading two time inputs in "HH:MM" format and splitting them into hours and minutes
    s := strings.Split(read(), ":")
    t := strings.Split(read(), ":")

    // Creating time.Time objects from the input strings for the first and second time
    x, _ := time.Parse("15:04", strings.Join(s, ":"))
    y, _ := time.Parse("15:04", strings.Join(t, ":"))

    // Calculating the difference between the two times and printing the result
    fmt.Println(x.Add(-y))
}

func read() string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := bufio.NewReader(os.Stdin).ReadLine()
        if err == io.EOF {
            break
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return string(buf)
}

func readInt() int {
    str := read()
    num, err := strconv.Atoi(str)
    if err!= nil {
        panic(err)
    }
    return num
}

func readString() string {
    return read()
}

func readStrings(n int) []string {
    res := make([]string, n)
    for i := 0; i < n; i++ {
        res[i] = readString()
    }
    return res
}

func readInt64() int64 {
    str := read()
    num, err := strconv.ParseInt(str, 10, 64)
    if err!= nil {
        panic(err)
    }
    return num
}

func readInt64s(n int) []int64 {
    res := make([]int64, n)
    for i := 0; i < n; i++ {
        res[i] = readInt64()
    }
    return res
}

// END-OF-CODE