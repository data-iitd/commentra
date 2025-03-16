

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements (n) and the parameter (k)
    reader := bufio.NewReader(os.Stdin)
    nk := strings.Split(readLine(reader), " ")
    nTemp, err := strconv.ParseInt(nk[0], 10, 64)
    checkError(err)
    n := int32(nTemp)
    kTemp, err := strconv.ParseInt(nk[1], 10, 64)
    checkError(err)
    k := int32(kTemp)
    
    // Read the list of elements
    elemsTemp := strings.Split(readLine(reader), " ")
    var elems []int32
    for _, elemsTempItem := range elemsTemp {
        elemsItemTemp, err := strconv.ParseInt(elemsTempItem, 10, 64)
        checkError(err)
        elemsItem := int32(elemsItemTemp)
        elems = append(elems, elemsItem)
    }
    
    // Define a function to check if all elements in a list are the same
    allSame := func(arr []int32) bool {
        for i := 1; i < len(arr); i++ {
            if arr[i]!= arr[i-1] {
                return false
            }
        }
        return true
    }
    
    // Check if all elements in the list are the same
    if allSame(elems) {
        // If all elements are the same, print 0 and return
        fmt.Println("0")
        return
    }
    
    // If k is 1, print -1 and return
    if k == 1 {
        fmt.Println("-1")
        return
    }
    
    // Check if elements from index k-1 to the end are all the same
    if!allSame(elems[k-1:]) {
        // If not, print -1 and return
        fmt.Println("-1")
        return
    }
    
    // Set the target to the last element of the list
    target := elems[n-1]
    
    // Initialize toDelete as elements from the start to k-1
    toDelete := elems[:k-1]
    
    // Remove elements from toDelete that are equal to target until a different element is found
    for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
        toDelete = toDelete[:len(toDelete)-1]
    }
    
    // Print the length of toDelete
    fmt.Println(len(toDelete))
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

