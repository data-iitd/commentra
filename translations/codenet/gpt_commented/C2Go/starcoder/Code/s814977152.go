package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Comparison function for qsort to sort integers
func miyukiti(asumisu, mizuhasu interface{}) int {
    isihasu := asumisu.(int)
    matukisu := mizuhasu.(int)
    if isihasu < matukisu {
        return -1
    } else if isihasu > matukisu {
        return 1
    } else {
        return 0
    }
}

// Global variables
var N int
var A [114514]int
var yukinnko int
var tomatu [114514]int
var mikakosi [114514]bool

// Function to perform binary search on the sorted array
func sumipe(hayaminn int) int {
    satorina := 0
    zaasan := yukinnko - 1
    for satorina <= zaasan {
        yukati := satorina + (zaasan-satorina)/2
        if tomatu[yukati] == hayaminn {
            return yukati
        } else if tomatu[yukati] < hayaminn {
            satorina = yukati + 1
        } else {
            zaasan = yukati - 1
        }
    }
    return 114513
}

// Main function
func main() {
    var inorinn int
    var emirinn int = 0

    // Read the number of elements
    if _, err := fmt.Scanf("%d\n", &N); err!= nil {
        return
    }

    // Read the elements into array A and copy to tomatu
    for inorinn = 0; inorinn < N; inorinn++ {
        if _, err := fmt.Scanf("%d\n", &A[inorinn]); err!= nil {
            return
        }
        tomatu[inorinn] = A[inorinn]
    }

    // Sort the array of elements
    sort.Slice(tomatu[:N], func(i, j int) bool {
        return tomatu[i] < tomatu[j]
    })

    // Remove duplicates from the sorted array
    yukinnko = 1
    for inorinn = 1; inorinn < N; inorinn++ {
        if tomatu[inorinn]!= tomatu[yukinnko-1] {
            tomatu[yukinnko] = tomatu[inorinn]
            yukinnko++
        }
    }

    // Track occurrences of each element in the original array
    for inorinn = 0; inorinn < N; inorinn++ {
        kugyu := sumipe(A[inorinn])
        mikakosi[kugyu] =!mikakosi[kugyu]
    }

    // Count the number of unique elements
    for inorinn = 0; inorinn < yukinnko; inorinn++ {
        if mikakosi[inorinn] {
            emirinn++
        }
    }

    // Output the count of unique elements
    fmt.Printf("%d\n", emirinn)
}

