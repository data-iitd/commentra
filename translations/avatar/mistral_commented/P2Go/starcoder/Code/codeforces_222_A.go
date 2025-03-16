// Function to define the main logic of the program
func main() {

    // Read input: number of elements 'n' and the difference 'k'
    n, k := 0, 0
    fmt.Scanf("%d %d", &n, &k)

    // Read input: list of elements 'elems'
    elems := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &elems[i])
    }

    // Helper function to check if all elements in a list are the same
    func allSame(arr []int) bool {
        // Return True if all elements in the list are the same, else False
        for i := 1; i < len(arr); i++ {
            if arr[i]!= arr[0] {
                return false
            }
        }
        return true
    }

    // Check if all elements in the list are the same
    if allSame(elems) {
        // If all elements are the same, print 0 and exit
        fmt.Println(0)
        return
    }

    // Check if difference 'k' is 1
    if k == 1 {
        // If difference is 1, print -1 and exit
        fmt.Println(-1)
        return
    }

    // Check if last 'k' elements in the list are not all the same
    if!allSame(elems[k-1:]) {
        // If last 'k' elements are not all the same, print -1 and exit
        fmt.Println(-1)
        return
    }

    // Initialize target element
    target := elems[len(elems)-1]

    // Initialize list 'to_delete' to store elements to be deleted
    to_delete := make([]int, 0)

    // While 'to_delete' is not empty and its last element is 'target'
    for len(to_delete) > 0 && to_delete[len(to_delete)-1] == target {
        // Pop the last element from 'to_delete'
        to_delete = to_delete[:len(to_delete)-1]
    }

    // Print the length of 'to_delete'
    fmt.Println(len(to_delete))
}

