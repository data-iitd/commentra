// Read two integers n and d from input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int d = sc.nextInt();

// Initialize an empty list to store the elements
List<Integer> x = new ArrayList<Integer>();
// Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
int m = 0;
int q = 0;

// Read the elements of the list from input and split them into individual strings
String[] x_temp = sc.nextLine().split(" ");

// Convert the list of strings into a list of integers
for (int i = 0; i < x_temp.length; i++) {
    x.add(Integer.parseInt(x_temp[i]));
}

// Iterate through the list to compare adjacent elements
for (int a = 0; a < x.size() - 1; a++) {
    // Check if the current element is greater than or equal to the next element
    if (x.get(a) >= x.get(a + 1)) {
        // Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
        q = (x.get(a) - x.get(a + 1)) / d + 1;
        // Update the total adjustments made
        m = m + q;
        // Adjust the next element by adding the necessary increments of d
        x.set(a + 1, x.get(a + 1) + q * d);
    }
}

// Print the total number of adjustments made
System.out.println(m);

