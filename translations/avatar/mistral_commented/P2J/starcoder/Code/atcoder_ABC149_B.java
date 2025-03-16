// Define a list 'cookies' by using list comprehension
List<Integer> cookies = Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Calculate the difference between the number of cookies given to the first and second child
int leftOver = cookies.get(0) - cookies.get(2);

// Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
int takahashi = Math.max(0, leftOver);

// Print the result using string concatenation
System.out.println(takahashi + " " + (cookies.get(1) if takahashi > 0 else Math.max(0, cookies.get(1) - Math.abs(leftOver))));

