// Read a line of input, split it into parts, and convert each part to an integer
int[] cookies = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

// Calculate the leftover cookies after taking some from the third type
int leftOver = cookies[0] - cookies[2];

// Determine the number of cookies Takahashi can take, ensuring it's not negative
int takahashi = Math.max(0, leftOver);

// Print the number of cookies Takahashi can take, and the remaining cookies of the second type
// If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
System.out.print(takahashi + " " + (cookies[1] > 0 ? cookies[1] : Math.max(0, cookies[1] - Math.abs(leftOver))));

