

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

func permutation(list []string, target string, ans string) []string {
 if len(target) <= 1 { // Base case: if the target string length is less than or equal to 1
 list = append(list, ans+target) // Add the current permutation to the list
 } else {
 for i := 0; i < len(target); i++ { // Iterate through each character in the target string
 list = permutation(list, target[:i]+target[i+1:], ans+string(target[i])) // Recursive call to find permutations of the remaining string
 }
 }
 return list // Return the list of permutations
}

func main() {
 scanner := bufio.NewScanner(os.Stdin) // Create a new Scanner object to read user input
 n := 0 // Declare an integer variable to store the number of test cases

 // Read the number of test cases from the user
 scanner.Scan()
 n, _ = strconv.Atoi(scanner.Text())

 number := "" // Declare an empty string variable to store the number string
 for i := 1; i <= n; i++ { // Iterate through each test case and create the number string
 number += strconv.Itoa(i)
 }

 listA := []string{} // Declare an empty slice to store the permutations
 listA = permutation(listA, number, "") // Call the permutation function to find all permutations of the number string

 sum := 0 // Declare an integer variable to store the sum of the indices of the matching permutations
 scanner.Scan()
 line := strings.Split(scanner.Text(), " ") // Split the line read from the user into an array of strings

 for j := 0; j < len(line); j++ { // Iterate through each line read from the user
 for i := 0; i < len(listA); i++ { // Iterate through each permutation in the list
 if listA[i] == line[j][0] { // Check if the current permutation matches the current line
 if sum == 0 { // If this is the first matching permutation
 sum += i // Add the index of the matching permutation to the sum
 } else { // If there is already a matching permutation in the sum
 sum -= i // Subtract the index of the previous matching permutation from the sum
 }
 }
 }
 }

 fmt.Println(int(math.Abs(float64(sum)))) // Print the absolute value of the sum
}

