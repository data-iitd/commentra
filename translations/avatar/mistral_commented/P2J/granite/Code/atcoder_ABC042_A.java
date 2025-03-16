
// Define a tuple 'ABC' by applying Integer.parseInt() method to each element of a list obtained by splitting a user input by space
Tuple ABC = Tuple.of(Arrays.stream(input.split(" ")).mapToInt(Integer::parseInt).toArray());

// Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
if (ABC.count(5) == 2) {
    // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
    System.out.println(ABC.stream().mapToInt(Integer::intValue).sum() == 17? "YES" : "NO");
} else {
    // If the condition is not met, print 'NO'
    System.out.println("NO");
}

