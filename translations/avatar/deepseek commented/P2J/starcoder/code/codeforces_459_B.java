// Step 1: Take an integer input `n` which represents the number of elements in the list `l1`.
int n = Integer.parseInt(input());

// Step 2: Take a space-separated string of integers, convert them into a list of integers, and store it in `l1`.
List<Integer> l1 = Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Step 3: Sort the list `l1` in ascending order.
Collections.sort(l1);

// Step 4: Assign the last element of the sorted list `l1` to `a`, which is the maximum value in the list.
int a = l1.get(l1.size() - 1);

// Step 5: Assign the first element of the sorted list `l1` to `b`, which is the minimum value in the list.
int b = l1.get(0);

// Step 6: Check if `a` is equal to `b`.
if (a == b) {
    // Step 7: If `a` is equal to `b`, print the difference `a - b` and the number of ways to choose 2 elements from `n` elements.
    System.out.println(a - b + " " + (n * (n - 1) / 2));
} else {
    // Step 8: If `a` is not equal to `b`, calculate the count of occurrences of `a` and `b` in the list `l1`.
    int ac = Collections.frequency(l1, a);
    int bc = Collections.frequency(l1, b);
    // Step 9: Print the difference `a - b` and the product of the counts of `a` and `b`.
    System.out.println(a - b + " " + (ac * bc));
}

