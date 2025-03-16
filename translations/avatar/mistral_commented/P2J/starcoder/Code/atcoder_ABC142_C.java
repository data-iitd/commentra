// Define the number of elements in the list 'A'
int N = Integer.parseInt(input());

// Initialize an empty list 'A' with 'N' elements
// Each element is a tuple containing an index and a value
List<Tuple<Integer, Integer>> A = new ArrayList<>();
for (int i = 0; i < N; i++) {
    String[] tokens = input().split(" ");
    A.add(new Tuple<>(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1])));
}

// Sort the list 'A' based on the second element of each tuple (the value)
A.sort(Comparator.comparingInt(Tuple::getSecond));

// Extract the first element (index) of each tuple in 'A' into a new list 'A_'
List<Integer> A_ = new ArrayList<>();
for (Tuple<Integer, Integer> a : A) {
    A_.add(a.getFirst());
}

// Iterate through the list 'A_' (excluding the last element) and print each index
for (int i = 0; i < A_.size() - 1; i++) {
    System.out.print(A_.get(i) + " ");
}

// Print the last index in 'A_'
System.out.println(A_.get(A_.size() - 1));

