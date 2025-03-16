// Read an integer input which represents the number of elements
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Read a list of integers from input and convert them to a list of integers
List<Integer> number = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Initialize two variables to hold the sums of the two halves
int h1 = 0;  // Sum of the first half
int h2 = 0;  // Sum of the second half
int x = 0;   // Flag to check if any number is not 4 or 7

// Iterate through the list of numbers
for (int i = 0; i < n; i++) {
    // Check if the current number is neither 4 nor 7
    if (number.get(i)!= 4 && number.get(i)!= 7) {
        System.out.println("NO");  // Print "NO" if an invalid number is found
        x++;                      // Increment the flag to indicate an invalid number was found
        break;                    // Exit the loop since we found an invalid number
    }
    
    // Sum the first half of the numbers
    if (i < n / 2) {
        h1 += number.get(i);
    } else {
        // Sum the second half of the numbers
        h2 += number.get(i);
    }
}

// After checking all numbers, determine if the sums of both halves are equal
if (x == 0) {  // Proceed only if no invalid numbers were found
    if (h1 == h2) {
        System.out.println("YES");  // Print "YES" if the sums are equal
    } else {
        System.out.println("NO");   // Print "NO" if the sums are not equal
}

