
// Read two integers n and k from input
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
int k = scanner.nextInt();

// Read the string s from input
String s = scanner.next();

// Initialize a list to count occurrences of each letter (A-Z)
int[] count = new int[26];

// Count the occurrences of each character in the string
for (int i = 0; i < s.length(); i++) {
    count[s.charAt(i) - 'A']++;
}

// Sort the count list in descending order to prioritize higher counts
Arrays.sort(count);

// Initialize the result variable to accumulate the final score
int res = 0;

// Iterate through the sorted count list
for (int i = 25; i >= 0; i--) {
    // If the current count is greater than or equal to k
    if (count[i] >= k) {
        // Add k squared to the result and print it
        res += k * k;
        System.out.println(res);
        break;  // Exit the loop since we have found the result
    }

    // Decrease k by the current count
    k -= count[i];

    // Add the square of the current count to the result
    res += count[i] * count[i];
}

// Print the final result after processing all counts
System.out.println(res);

