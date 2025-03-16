#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort integers
func miyukiti(asumisu, mizuhasu unsafe.Pointer) int {
    isihasu := *(*int)(asumisu), matukisu := *(*int)(mizuhasu)
    if isihasu < matukisu {
        return -1
    } else if isihasu > matukisu {
        return 1
    } else {
        return 0
    }
}

// Global variables
var N int // Number of elements
var A [114514]int // Array to hold input elements

var yukinnko int // Count of unique elements
var tomatu [114514]int // Array to hold sorted elements

var mikakosi [114514]int // Array to track occurrences of elements

// Function to perform binary search on the sorted array
func sumipe(hayaminn int) int {
    satorina := 0
    zaasan := yukinnko - 1
    for satorina <= zaasan {
        yukati := satorina + (zaasan - satorina) / 2
        if tomatu[yukati] == hayaminn {
            return yukati // Found the element
        } else if tomatu[yukati] < hayaminn {
            satorina = yukati + 1 // Search in the right half
        } else {
            zaasan = yukati - 1 // Search in the left half
        }
    }
    return 114513 // Element not found
}

// Main function
func main() {
    var inorinn int // Loop variable for input
    var emirinn int = 0 // Counter for unique elements

    // Read the number of elements
    if _, err := fmt.Scan(&N); err != nil {
        return
    }

    // Read the elements into array A and copy to tomatu
    for inorinn = 0; inorinn < N; inorinn++ {
        if _, err := fmt.Scan(&A[inorinn]); err != nil {
            return
        }
        tomatu[inorinn] = A[inorinn] // Copying input to sorted array
    }

    // Sort the array of elements
    qsort(tomatu[:], N, unsafe.Sizeof(tomatu[0]), miyukiti)

    // Remove duplicates from the sorted array
    yukinnko = 1 // Start with the first unique element
    for inorinn = 1; inorinn < N; inorinn++ {
        if tomatu[inorinn] != tomatu[yukinnko-1] {
            tomatu[yukinnko] = tomatu[inorinn] // Add unique element
            yukinnko++
        }
    }

    // Track occurrences of each element in the original array
    for inorinn = 0; inorinn < N; inorinn++ {
        kugyu := sumipe(A[inorinn]) // Find index of element in sorted array
        mikakosi[kugyu] = !mikakosi[kugyu] // Toggle occurrence
    }

    // Count the number of unique elements
    for inorinn = 0; inorinn < yukinnko; inorinn++ {
        if mikakosi[inorinn] {
            emirinn++ // Increment count for unique occurrences
        }
    }

    // Output the count of unique elements
    fmt.Println(emirinn)
}

