// Step 1: Take two integers as input and assign them to x and y.
int x = Integer.parseInt(input());
int y = Integer.parseInt(input());

// Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
System.out.println(Math.max(x + y - 3 + (y - x) % 3 > 0? 0 : x + y - 3, 0));

// Step 3: Define lambda functions for taking different types of inputs.
IntSupplier num_inp = () -> Integer.parseInt(input());
IntSupplier[] arr_inp = () -> Arrays.stream(input().split(" ")).mapToInt(Integer::parseInt).toArray();
IntSupplier[] sp_inp = () -> Stream.of(input().split(" ")).mapToInt(Integer::parseInt).toArray();
IntSupplier str_inp = () -> Integer.parseInt(input());

