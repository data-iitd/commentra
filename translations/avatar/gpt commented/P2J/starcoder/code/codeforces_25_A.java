// Read an integer input which represents the number of elements
int n = Integer.parseInt(sc.nextLine());

// Read a line of input, split it into individual elements, convert them to integers,
// and create a list that contains 1 for odd numbers and 0 for even numbers
List<Integer> list = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).map(x -> x % 2).collect(Collectors.toList());

// Check if there is exactly one odd number in the list
if (list.stream().filter(x -> x == 1).count() == 1) {
    // If there is one odd number, print its position (1-based index)
    System.out.println(list.indexOf(1) + 1);
} else {
    // If there are no odd numbers, print the position of the first even number (1-based index)
    System.out.println(list.indexOf(0) + 1);
}

