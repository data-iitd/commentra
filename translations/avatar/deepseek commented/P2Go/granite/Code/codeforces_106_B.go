

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

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    var inputArray [][4]int32

    for i := int32(0); i < n; i++ {
        inputArrayTemp := strings.Split(readLine(reader), " ")

        var inputArrayItem [4]int32

        for j, inputArrayItemTemp := range inputArrayTemp {
            inputArrayItemVal, err := strconv.ParseInt(inputArrayItemTemp, 10, 64)
            checkError(err)
            inputArrayItem[j] = int32(inputArrayItemVal)
        }

        inputArray = append(inputArray, inputArrayItem)
    }

    var outdated [][4]int32

    for i := int32(0); i < n; i++ {
        for j := int32(0); j < n; j++ {
            if (inputArray[i][0] < inputArray[j][0] &&
                inputArray[i][1] < inputArray[j][1] &&
                inputArray[i][2] < inputArray[j][2]) {
                outdated = append(outdated, inputArray[i])
            }
        }
    }

    outdatedMap := make(map[[4]int32]bool)

    for _, outdatedItem := range outdated {
        outdatedMap[outdatedItem] = true
    }

    minimumCost := int32(100000)
    inputNumber := int32(0)

    for i := int32(0); i < n; i++ {
        currentItem := inputArray[i]
        cost := currentItem[3]

        if _, ok := outdatedMap[currentItem];!ok && cost < minimumCost {
            minimumCost = cost
            inputNumber = i + 1
        }
    }

    fmt.Println(inputNumber)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

