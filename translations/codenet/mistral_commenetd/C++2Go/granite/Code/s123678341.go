

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    // Initialize input variables
    reader := bufio.NewReader(os.Stdin)
    X, Y, Z, K := readNInt64s(reader, 4) // Read input values for X, Y, Z, and K from standard input

    // Initialize vectors A, B, and C
    A := make([]int64, X) // A vector of size X, initialized with zeroes
    B := make([]int64, Y) // B vector of size Y, initialized with zeroes
    C := make([]int64, Z) // C vector of size Z, initialized with zeroes

    // Read input values for vectors A, B, and C from standard input
    for i := int64(0); i < X; i++ {
        a, _ := strconv.ParseInt(readWord(reader), 10, 64) // Read each element of vector A
        A[i] = a
    }
    for i := int64(0); i < Y; i++ {
        b, _ := strconv.ParseInt(readWord(reader), 10, 64) // Read each element of vector B
        B[i] = b
    }
    for i := int64(0); i < Z; i++ {
        c, _ := strconv.ParseInt(readWord(reader), 10, 64) // Read each element of vector C
        C[i] = c
    }

    // Sort vectors A, B, and C in descending order
    sort.Slice(A, func(i, j int) bool {
        return A[i] > A[j]
    })
    sort.Slice(B, func(i, j int) bool {
        return B[i] > B[j]
    })
    sort.Slice(C, func(i, j int) bool {
        return C[i] > C[j]
    })

    // Create a new vector AB by adding each element of A to each element of B
    AB := make([]int64, 0)
    for i := int64(0); i < X; i++ {
        for j := int64(0); j < Y; j++ {
            AB = append(AB, A[i]+B[j]) // Add A[i] and B[j] and push the sum into vector AB
        }
    }

    // Sort vector AB in descending order
    sort.Slice(AB, func(i, j int) bool {
        return AB[i] > AB[j]
    })

    // Create a new vector ABC by adding each element of AB to each element of C
    ABC := make([]int64, 0)
    for i := int64(0); i < min(K, int64(len(AB))); i++ {
        for j := int64(0); j < Z; j++ {
            ABC = append(ABC, AB[i]+C[j]) // Add AB[i] and C[j] and push the sum into vector ABC
        }
    }

    // Sort vector ABC in descending order
    sort.Slice(ABC, func(i, j int) bool {
        return ABC[i] > ABC[j]
    })

    // Print K smallest elements of vector ABC
    for i := int64(0); i < K; i++ {
        fmt.Println(ABC[i]) // Print each element of vector ABC
    }
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

func readInt64(bytes []byte, from int, val *int64) int {
    i := from
    var tmp int64
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + int64(bytes[i]-'0')
        i++
    }
    *val = tmp
    return i
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    res := make([]int64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readInt64(s, pos, &res[i])
    }

    return res
}

func readUint64s(reader *bufio.Reader, n int) []uint64 {
    res := make([]uint64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readUint64(s, pos, &res[i])
    }

    return res
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

func readInt64(bytes []byte, from int, val *int64) int {
    i := from
    var tmp int64
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + int64(bytes[i]-'0')
        i++
    }
    *val = tmp
    return i
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    res := make([]int64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readInt64(s, pos, &res[i])
    }

    return res
}

func readUint64s(reader *bufio.Reader, n int) []uint64 {
    res := make([]uint64, n)
    s, _ := reader.ReadBytes('\n')

    var pos int

    for i := 0; i < n; i++ {
        pos = readUint64(s, pos, &res[i])
    }

    return res
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

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}