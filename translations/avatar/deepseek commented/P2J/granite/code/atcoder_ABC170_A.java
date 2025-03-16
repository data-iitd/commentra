

Scanner scanner = new Scanner(System.in);  // Create a scanner to read input from the user
String[] input = scanner.nextLine().split(" ");  // Read input as a string, split it into an array of strings
int[] a = new int[input.length];  // Create an array of integers with the same length as the input array
for (int i = 0; i < input.length; i++) {  // Iterate over the input array, converting each string to an integer
    a[i] = Integer.parseInt(input[i]);
}
for (int i = 0; i < a.length; i++) {  // Iterate over the array of integers
    if (a[i] == 0) {  // If an element is 0
        System.out.println(i + 1);  // Print the position (1-indexed) of that element and break the loop
        break;
    }
}
