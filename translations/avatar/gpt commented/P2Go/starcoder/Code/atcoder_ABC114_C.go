// Read an integer input from the user
var N int
fmt.Scanf("%d", &N)

// Define a recursive function 'aaa' that takes a string 'n'
func aaa(n string) int {
    // Check if the integer value of 'n' exceeds the limit N
    if int(n) > N {
        return 0 // If it does, return 0 (base case)
    }

    // Check if the digits of 'n' are exactly '7', '5', and '3'
    ans := 1
    if len(n) == 1 {
        if n[0] == '7' || n[0] == '5' || n[0] == '3' {
            ans = 1
        } else {
            ans = 0
        }
    } else {
        if n[0] == '7' || n[0] == '5' || n[0] == '3' {
            ans = 1
        } else {
            ans = 0
        }
    }

    // Iterate over each character in the string '753'
    for i := 0; i < len(n); i++ {
        // Recursively call 'aaa' with the current number 'n' concatenated with 'i'
        ans += aaa(n + string(i))
    }

    // Return the accumulated answer
    return ans
}

// Print the result of calling 'aaa' with the initial value '0'
fmt.Println(aaa("0"))

