// Define a lambda function to read an integer input
IntSupplier num_inp = () -> Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());

// Define a lambda function to read a list of integers from input
Function<String, List<Integer>> arr_inp = (s) -> Arrays.stream(s.split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Define a lambda function to read a space-separated list of integers as a map object
Function<String, Map<Integer, Integer>> sp_inp = (s) -> Arrays.stream(s.split(" ")).map(Integer::parseInt).collect(Collectors.toMap(x -> x, x -> 1));

// Read the input from the first line of the standard input, sort it, and convert it to a list of integers
List<Integer> a = Arrays.stream(new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ")).map(Integer::parseInt).sorted().collect(Collectors.toList());

// Check if any element in the list 'a' is not divisible by the first element of 'a'
// If all elements are divisible, print the first element; otherwise, print -1
System.out.println(a.stream().anyMatch(x -> x % a.get(0) != 0) ? -1 : a.get(0));

