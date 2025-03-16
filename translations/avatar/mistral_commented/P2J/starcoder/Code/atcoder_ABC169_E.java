
// Function to resolve the problem
public static void resolve( ) {

    // Read the number of test cases
    int n = Integer.parseInt(input());

    // Initialize empty lists to store low and high values
    List<Integer> low = new ArrayList<Integer>();
    List<Integer> high = new ArrayList<Integer>();

    // Read low and high values for each test case and append to respective lists
    for (int i = 0; i < n; i++) {
        int a, b = map(int, input().split());
        low.add(a);
        high.add(b);
    }

    // Sort the low and high lists in ascending order
    Collections.sort(low);
    Collections.sort(high);

    // Check if the number of test cases is odd
    if (n % 2) {
        // If it is odd, print the difference between the middle low and middle high values
        System.out.println(high.get((n+1)/2-1) - low.get((n+1)/2-1) + 1);
    } else {
        // If it is even, calculate the average of middle low and middle high values
        int hh = (high.get((n)/2-1) + high.get((n)/2)) / 2;
        int ll = (low.get((n)/2-1) + low.get((n)/2)) / 2;

        // Print the result which is twice the difference between the averages
        System.out.println(int((hh-ll)*2)+1);
    }
}

