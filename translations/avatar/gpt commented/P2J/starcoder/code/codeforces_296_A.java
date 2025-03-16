// Read an integer input n which represents the threshold for majority
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Read a line of input, split it into a list of strings, and store it in m
String[] m = sc.nextLine().split(" ");

// Initialize a variable to track if a majority element is possible
boolean possible = true;

// Iterate through each unique element in the list m
for (String i : new HashSet<String>(Arrays.asList(m))) {
    // Check if the count of the current element i is greater than or equal to n/2 + 1
    if (Arrays.asList(m).stream().filter(x -> x.equals(i)).count() >= n / 2 + 1) {
        // If it is, set possible to False and break the loop
        possible = false;
        break;
    }
}

// Print 'YES' if a majority element is not found, otherwise print 'NO'
System.out.println("YES" if possible else "NO");

