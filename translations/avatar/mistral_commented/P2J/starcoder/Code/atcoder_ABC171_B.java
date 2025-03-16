
// Read two integers `n` and `k` from the standard input, separated by a space
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
int k = scanner.nextInt();

// Create a list of integers from the standard input, each line containing `n` integers
List<Integer> numbers = new ArrayList<>();
for (int i = 0; i < n; i++) {
    numbers.add(scanner.nextInt());
}

// Sort the list in ascending order
Collections.sort(numbers);

// Calculate the sum of the first `k` elements of the sorted list
int result = 0;
for (int i = 0; i < k; i++) {
    result += numbers.get(i);
}

// Print the result
System.out.println(result);

