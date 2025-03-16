
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of rounds (n) and the number of George's complexities (m)
    reader := bufio.NewReader(os.Stdin)
    n, m := readTwoInt64s(reader)
    
    // Read the complexities for each round into a list
    roundComplexities := readNInt64s(reader, n)
    
    // Read George's complexities into another list
    georgeComplexities := readNInt64s(reader, m)
    
    // Initialize indices for both lists
    i, j := int64(0), int64(0)
    
    // Iterate through both lists to compare complexities
    for i < n && j < m {
        // If the current round's complexity is less than or equal to George's complexity,
        // move to the next round
        if roundComplexities[i] <= georgeComplexities[j] {
            i++
        }
        
        // Always move to the next complexity of George
        j++
    }
    
    // Output the number of rounds that George cannot handle
    fmt.Println(n - i)
}

func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp := int(bytes[i] - '0')
        *val = *val*10 + tmp
        i++
    }
    *val *= sign
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

func main() {
    reader := bufio.NewReader(os.Stdin)

    n, m := readTwoInt64s(reader)

    roundComplexities := readNInt64s(reader, n)

    georgeComplexities := readNInt64s(reader, m)

    i, j := int64(0), int64(0)

    for i < n && j < m {
        if roundComplexities[i] <= georgeComplexities[j] {
            i++
        }
        j++
    }

    fmt.Println(n - i)
}

func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp := int(bytes[i] - '0')
        *val = *val*10 + tmp
        i++
    }
    *val *= sign
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

func main() {
    reader := bufio.NewReader(os.Stdin)

    n, m := readTwoInt64s(reader)

    roundComplexities := readNInt64s(reader, n)

    georgeComplexities := readNInt64s(reader, m)

    i, j := int64(0), int64(0)

    for i < n && j < m {
        if roundComplexities[i] <= georgeComplexities[j] {
            i++
        }
        j++
    }

    fmt.Println(n - i)
}

func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp := int(bytes[i] - '0')
        *val = *val*10 + tmp
        i++
    }
    *val *= sign
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

func main() {
    reader := bufio.NewReader(os.Stdin)

    n, m := readTwoInt64s(reader)

    roundComplexities := readNInt64s(reader, n)

    georgeComplexities := readNInt64s(reader, m)

    i, j := int64(0), int64(0)

    for i < n && j < m {
        if roundComplexities[i] <= georgeComplexities[j] {
            i++
        }
        j++
    }

    fmt.Println(n - i)
}

func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp := int(bytes[i] - '0')
        *val = *val*10 + tmp
        i++
    }
    *val *= sign
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

    var pos in