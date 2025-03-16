// Take the number of elements in the array as input
n := int(input())

// Initialize an empty list 'arr' of size 'n' and fill it with integers taken as input
arr := make([]int, n)
for i := 0; i < n; i++ {
    arr[i] = int(input())
}

// Initialize an empty list 'ans' of size 'n' with zeros
ans := make([]int, n)

// Variable'mx' stores the maximum element in the array
mx := arr[n-1]

// Iterate through the array from index 'n-2' to '0' in reverse order
for i := n - 2; i >= 0; i-- {

    // Update the answer at current index 'i' based on the maximum element'mx' and current element 'arr[i]'
    ans[i] = max(0, mx - arr[i] + 1)

    // If the current element 'arr[i]' is greater than the maximum element'mx', update'mx'
    if arr[i] > mx {
        mx = arr[i]
    }
}

// Print the answer list
for i := 0; i < n; i++ {
    fmt.Printf("%d ", ans[i])
}

// 