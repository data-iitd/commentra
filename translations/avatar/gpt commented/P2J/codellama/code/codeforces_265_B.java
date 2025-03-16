// Read the number of elements from user input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize an empty list to store the elements
ArrayList<Integer> l = new ArrayList<Integer>();

// Loop to read 'n' integers from user input and append them to the list
for (int i = 0; i < n; i++) {
    l.add(sc.nextInt());
}

// Initialize the answer variable to n - 1 (to account for n-1 gaps between n elements)
int ans = n - 1;

// Initialize a variable to keep track of the last element processed
int last = 0;

// Loop through each element in the list
for (int i : l) {
    // Calculate the distance from the last element to the current element
    // and add 1 for the step to the current element
    ans += Math.abs(last - i) + 1;
    
    // Update 'last' to the current element for the next iteration
    last = i;
}

// Print the final calculated answer
System.out.println(ans);

