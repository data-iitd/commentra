// Define a tuple 'ABC' by applying int() function to each element of a list obtained by splitting a user input by space
int[] ABC = Arrays.stream(input().split(" ")).mapToInt(Integer::parseInt).toArray();

// Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
if (Arrays.stream(ABC).filter(x -> x == 5).count() == 2) {
    // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
    System.out.println("YES" + (Arrays.stream(ABC).sum() == 17? "" : "NO"));
} else {
    // If the condition is not met, print 'NO'
    System.out.println("NO");
}

