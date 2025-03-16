// Define a tuple 'ABC' by applying int() function to each element of a list obtained by splitting a user input by space
String[] ABC = input.split(" ");

// Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
if (Arrays.asList(ABC).contains("5") && Arrays.asList(ABC).contains("5") && Arrays.asList(ABC).indexOf("5") != Arrays.asList(ABC).lastIndexOf("5")) {
    // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
    if (Integer.parseInt(ABC[0]) + Integer.parseInt(ABC[1]) + Integer.parseInt(ABC[2]) == 17) {
        System.out.println("YES");
    } else {
        System.out.println("NO");
    }
} else {
    // If the condition is not met, print 'NO'
    System.out.println("NO");
}

