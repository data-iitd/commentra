#######
# Code
#######

// Define the number of elements 'n' and the modulus'm' in the list 'l'
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Initialize an empty list 'l2' to store the quotient of each element in 'l' divided by'm'
List<Integer> l2 = new ArrayList<>();

// Iterate through each element 'i' in the list 'l'
for (int i = 0; i < n; i++) {
    // Check if the element 'i' is divisible by'm'. If yes, append the quotient (integer division) to 'l2'. If not, append the quotient plus one.
    if (l.get(i) % m == 0) {
        l2.add(l.get(i) / m);
    } else {
        l2.add(l.get(i) / m + 1);
    }
}

// Find the maximum quotient in 'l2'
int mx = Collections.max(l2);

// Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
for (int i = 0; i < n; i++) {
    // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient'mx'. If yes, store the index 'i' in the variable 'ind'.
    if (l2.get(i) == mx) {
        ind = i;
    }
}

// Print the index 'ind' plus one (since the indices in Java start from 0)
System.out.println(ind + 1);

