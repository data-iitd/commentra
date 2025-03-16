// Define the number of elements 'n' and the difference 'd' in the input list
int n, d;

// Initialize an empty list 'x' to store the input elements
List<Integer> x = new ArrayList<>();

// Initialize variables 'm' and 'q' to 0
int m = 0, q = 0;

// Read the 'n' elements from the input and convert them to integers
Scanner sc = new Scanner(System.in);
n = sc.nextInt();
d = sc.nextInt();
for (int i = 0; i < n; i++) {
    x.add(sc.nextInt());
}

// Iterate through the list 'x' to find the elements that are not in increasing order
for (int i = 0; i < n - 1; i++) {
    // Check if the current element is greater than or equal to the next element
    if (x.get(i) >= x.get(i + 1)) {
        // Calculate the number of elements that need to be added to the next element
        q = (int) ((x.get(i) - x.get(i + 1)) / d + 1);
        // Add the calculated number of elements to the current and next elements
        m += q;
        x.set(i + 1, x.get(i + 1) + q * d);
    }
}

// Print the final result 'm'
System.out.println(m);

