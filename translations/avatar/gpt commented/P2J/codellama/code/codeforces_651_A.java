// Read two integers from input and assign them to x and y
Scanner scanner = new Scanner(System.in);
int x = scanner.nextInt();
int y = scanner.nextInt();

// Calculate the maximum value based on the formula and print it
// The formula computes x + y - 3 and adjusts based on the difference between y and x
// It ensures the result is not negative by taking the maximum with 0
System.out.println(Math.max(x + y - 3 + ((y - x) % 3 > 0 ? 1 : 0), 0));

// Define a lambda function to read a single integer from input
Function<Integer> numInp = () -> Integer.parseInt(scanner.next());

// Define a lambda function to read a list of integers from input
Function<List<Integer>> arrInp = () -> Arrays.stream(scanner.next().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Define a lambda function to read a space-separated list of integers from input
Function<Stream<Integer>> spInp = () -> Arrays.stream(scanner.next().split(" ")).map(Integer::parseInt);

// Define a lambda function to read a string from input
Function<String> strInp = () -> scanner.next();

