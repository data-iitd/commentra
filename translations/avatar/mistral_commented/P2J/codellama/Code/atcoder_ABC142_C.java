// Define the number of elements in the list 'A'
int N = Integer.parseInt(input.nextLine());

// Initialize an empty list 'A' with 'N' elements
// Each element is a tuple containing an index and a value
List<Integer> A = new ArrayList<Integer>();
for (int i = 0; i < N; i++) {
    A.add(i + 1);
}

// Sort the list 'A' based on the second element of each tuple (the value)
Collections.sort(A, new Comparator<Integer>() {
    @Override
    public int compare(Integer a, Integer b) {
        return a - b;
    }
});

// Extract the first element (index) of each tuple in 'A_' into a new list 'A__'
List<Integer> A__ = new ArrayList<Integer>();
for (int i = 0; i < N; i++) {
    A__.add(A.get(i));
}

// Iterate through the list 'A__' (excluding the last element) and print each index
for (int i = 0; i < A__.size() - 1; i++) {
    System.out.print(A__.get(i) + " ");
}

// Print the last index in 'A__'
System.out.println(A__.get(A__.size() - 1));

