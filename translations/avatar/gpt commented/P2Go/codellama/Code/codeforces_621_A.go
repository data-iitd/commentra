// Read an integer input for the number of elements
n, _ := strconv.Atoi(input())

// Read a list of integers from input and convert them to a list of integers
lst := make([]int, n)
for i := 0; i < n; i++ {
	lst[i], _ = strconv.Atoi(input())
}

// Sort the list in ascending order
sort.Ints(lst)

// Reverse the list to get it in descending order
for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
	lst[i], lst[j] = lst[j], lst[i]
}

// Initialize a counter for odd numbers
od := 0

// Count the number of odd integers in the list
for _, v := range lst {
	if v%2 == 1 {
		od++
	}
}

// Initialize variables for sum and a flag to track even number inclusion
sum := 0
ok := false

// Iterate through the sorted list to calculate the desired sum
for i := 0; i < n; i++ {
	if lst[i]%2 == 0 {
		sum += lst[i]
	} else {
		if ok || od > 1 {
			sum += lst[i]
			od--
			ok = !ok
		}
	}
}

// Print the final calculated sum
fmt.Println(sum)

// 