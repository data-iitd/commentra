

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
    checkError(err)

    levelsTemp, err := reader.ReadString('\n')
    checkError(err)
    levels, err := strconv.ParseInt(strings.TrimSpace(levelsTemp), 10, 64)
    checkError(err)

    sum := int32(0)
    sum2 := int32(0)
    sum3 := int32(0)
    arr := make([]int32, levels)
    count := int32(0)

    for i := int32(0); i < levels; i++ {
        arrTemp, err := reader.ReadString('\n')
        checkError(err)
        arrTemp = strings.TrimSpace(arrTemp)
        arr[i], err = strconv.ParseInt(arrTemp, 10, 64)
        checkError(err)
    }

    level2Temp, err := reader.ReadString('\n')
    checkError(err)
    level2, err := strconv.ParseInt(strings.TrimSpace(level2Temp), 10, 64)
    checkError(err)

    level3 := levels + level2
    arr2 := make([]int32, level3)

    for i := int32(0); i < levels; i++ {
        arr2[i] = arr[i]
    }

    for i := levels; i < level3; i++ {
        arr2[i], err = reader.ReadString('\n')
        checkError(err)
        arr2[i] = strings.TrimSpace(arr2[i])
        arr2[i], err = strconv.ParseInt(arr2[i], 10, 64)
        checkError(err)
    }

    arr3 := make([]int32, n)
    j := int32(0)

    for i := int32(0); i < n; i++ {
        j++
        arr3[i] = j
    }

    for i := int32(0); i < n; i++ {
        for x := int32(0); x < level3; x++ {
            if arr3[i] == arr2[x] {
                count++
                break
            }
        }
    }

    if count == n {
        fmt.Println("I become the guy.")
    } else {
        fmt.Println("Oh, my keyboard!")
    }

    fmt.Println("