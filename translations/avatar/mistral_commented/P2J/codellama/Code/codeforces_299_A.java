// Define lambda functions for input handling
// num_inp: takes a single input as an integer
// arr_inp: takes a list input where each element is an integer
// sp_inp: takes a list input where each element is an integer, space-separated

num_inp = () -> Integer.parseInt(input());
// This line reads a single integer input from the user

arr_inp = () -> Arrays.stream(input().split()).mapToInt(Integer::parseInt).toArray();
// This line reads a list input from the user, where each element is an integer

sp_inp = () -> Arrays.stream(input().split()).mapToInt(Integer::parseInt);
// This line reads a list input from the user, where each element is an integer, space-separated

// Read input from file instead of user input
a = Arrays.stream(new String(Files.readAllBytes(Paths.get("input.txt"))).split("\n")).map(Integer::parseInt).sorted().toArray();
// This block reads the input from the file, converts each line to a list of integers,
// and sorts the list of integers

// Find the largest number that leaves a remainder when divided by any number in the list
System.out.println(a[0] % a[1] == 0 ? a[0] : -1);
// This block calculates the answer and prints it

