// Read an integer input which represents the number of elements
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Read a line of input, split it into individual strings, convert them to integers, and store them in a list
List<Integer> r = new ArrayList<>();
for (int i = 0; i < n; i++) {
    r.add(sc.nextInt());
}

// Initialize the answer with the absolute value of the first element in the list
int ans = Math.abs(r.get(0));

// Iterate through the list starting from the second element
for (int i = 1; i < n; i++) {
    // Add the absolute difference between the current element and the previous element to the answer
    ans += Math.abs(r.get(i) - r.get(i - 1));
}

// Print the final computed answer
System.out.println(ans);

