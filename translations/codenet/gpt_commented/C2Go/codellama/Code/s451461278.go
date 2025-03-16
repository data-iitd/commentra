#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

// Function prototypes for partitioning and sorting
func Partition(C []string, A []int, p, r int) int {
    var i, j int
    var tmpC string
    var tmpN int

    // Choose the last element as pivot
    x := C[r]
    y := A[r]
    i = p - 1

    // Rearrange elements based on the pivot
    for j = p; j < r; j++ {
        if A[j] <= y {
            i = i + 1
            // Swap elements to partition the array
            tmpN = A[j]
            tmpC = C[j]
            A[j] = A[i]
            C[j] = C[i]
            A[i] = tmpN
            C[i] = tmpC
        }
    }

    // Place the pivot in the correct position
    tmpN = A[i + 1]
    tmpC = C[i + 1]
    A[i + 1] = A[r]
    C[i + 1] = C[r]
    A[r] = tmpN
    C[r] = tmpC

    return i + 1 // Return the pivot index
}

// Function to perform quicksort
func Quicksort(C []string, A []int, p, r int) {
    // Base case for recursion
    if p < r {
        q = Partition(C, A, p, r) // Partition the array
        Quicksort(C, A, p, q - 1) // Recursively sort the left subarray
        Quicksort(C, A, q + 1, r) // Recursively sort the right subarray
    }
}

// Function to merge two sorted subarrays
func Merge(MC []string, MN []int, left, mid, right int) {
    n1 := mid - left + 1 // Size of left subarray
    n2 := right - mid // Size of right subarray
    LN := make([]int, n1 + 1) // Left subarray for integers
    RN := make([]int, n2 + 1) // Right subarray for integers
    LC := make([]string, n1 + 1) // Left subarray for characters
    RC := make([]string, n2 + 1) // Right subarray for characters
    
    var i, j, k int

    // Copy data to temporary arrays
    for i = 1; i <= n1; i++ {
        LN[i] = MN[left + i - 1]
        LC[i] = MC[left + i - 1]
    }
    
    for i = 1; i <= n2; i++ {
        RN[i] = MN[mid + i]
        RC[i] = MC[mid + i]
    }
    
    // Sentinel values for merging
    LN[n1 + 1] = 1000000000
    RN[n2 + 1] = 1000000000
    
    i = 1 // Index for left subarray
    j = 1 // Index for right subarray
    
    // Merge the temporary arrays back into the original arrays
    for k = left; k <= right; k++ {
        if LN[i] <= RN[j] {
            MN[k] = LN[i]
            MC[k] = LC[i]
            i++
        } else {
            MN[k] = RN[j]
            MC[k] = RC[j]
            j++
        }
    }
}

// Function to perform merge sort
func Merge_Sort(MC []string, MN []int, left, right int) {
    var mid int

    // Base case for recursion
    if left < right {
        mid = (left + right) / 2 // Find the midpoint
        Merge_Sort(MC, MN, left, mid) // Recursively sort the left half
        Merge_Sort(MC, MN, mid + 1, right) // Recursively sort the right half
        Merge(MC, MN, left, mid, right) // Merge the sorted halves
    }
}


func main() {
    // Declare arrays for storing values and characters
    var A [MAX + 1]int // Array for integer values
    var C [MAX + 1]string // Array for characters
    var MC [MAX + 1]string // Array for characters for merge sort
    var MN [MAX + 1]int // Array for integer values for merge sort

    var i, p, n int
    var count int // Counter for stable sorting check

    // Read the number of elements
    fmt.Scan(&n)

    // Read character and integer pairs into arrays
    for i = 1; i <= n; i++ {
        fmt.Scan(&C[i], &A[i])
    }

    // Copy original arrays to auxiliary arrays for merge sort
    for i = 1; i <= n; i++ {
        MC[i] = C[i]
        MN[i] = A[i]
    }

    // Perform merge sort on the auxiliary arrays
    Merge_Sort(MC, MN, 1, n)

    // Perform quicksort on the original arrays
    p = 1
    Quicksort(C, A, p, n)

    // Check if the sorting is stable by comparing original and sorted arrays
    for i = 1; i <= n; i++ {
        if MN[i] == A[i] && MC[i] == C[i] {
            count++
        }
    }

    // Output stability result
    if count == n {
        fmt.Println("Stable")
    } else {
        fmt.Println("Not stable")
    }

    // Print the sorted character and integer pairs
    for i = 1; i <= n; i++ {
        fmt.Println(C[i], A[i])
    }
}

