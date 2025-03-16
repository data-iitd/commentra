// Define lambda functions for input handling
// num_inp: takes a single input as an integer
// arr_inp: takes a list input where each element is an integer
// sp_inp: takes a list input where each element is an integer, space-separated

Function<Integer, Integer> num_inp = (x) -> Integer.parseInt(x);
// This line reads a single integer input from the user

Function<String, List<Integer>> arr_inp = (x) -> Arrays.stream(x.split(" ")).map(Integer::parseInt).collect(Collectors.toList());
// This line reads a list input from the user, where each element is an integer

Function<String, List<Integer>> sp_inp = (x) -> Arrays.stream(x.split(" ")).map(Integer::parseInt).collect(Collectors.toList());
// This line reads a list input from the user, where each element is an integer, space-separated

// Read input from file instead of user input
List<Integer> a = Arrays.stream(new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ")).map(Integer::parseInt).sorted().collect(Collectors.toList());
// This block reads the input from the file, converts each line to a list of integers,
// and sorts the list of integers

// Find the largest number that leaves a remainder when divided by any number in the list
System.out.println(a.get(0) == 1? -1 : a.stream().filter(x -> a.get(0) % x == 0).max(Integer::compare).get());
// This block calculates the answer and prints it

