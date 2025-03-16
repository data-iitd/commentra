// Read an integer input for the number of elements
int n = Integer.parseInt(input());

// Read a list of integers from input and convert them to a list of integers
List<Integer> lst = Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Sort the list in ascending order
Collections.sort(lst);

// Reverse the list to get it in descending order
Collections.reverse(lst);

// Initialize a counter for odd numbers
int od = 0;

// Count the number of odd integers in the list
for (int i : lst) {
    if ((i & 1) == 1) {  // Check if the number is odd using bitwise AND
        od++;  // Increment the odd counter
    }
}

// Initialize variables for sum and a flag to track even number inclusion
int sum = 0;
boolean ok = false;

// Iterate through the sorted list to calculate the desired sum
for (int i = 0; i < n; i++) {
    if ((lst.get(i) % 2) == 0) {  // Check if the current number is even
        sum += lst.get(i);  // Add even numbers directly to the sum
    } else {
        // If we have already included an odd number or there is more than one odd number left
        if (ok || od > 1) {
            sum += lst.get(i);  // Add the odd number to the sum
            od--;  // Decrement the odd counter
            ok =!ok;  // Toggle the flag to indicate an odd number has been included
        }
    }
}

// Print the final calculated sum
System.out.println(sum);

