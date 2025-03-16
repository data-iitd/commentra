
// Take input string'soz' from the user
Scanner sc = new Scanner(System.in);
String soz = sc.nextLine();

// Initialize an array 'a' of size 'len(soz)+1' with zeros
int[] a = new int[soz.length() + 1];

// Iterate through the string'soz' starting from index 1
for (int i = 1; i < soz.length(); i++) {
    // Assign the value of the previous index to the current index
    a[i] = a[i - 1];
    
    // If the current character is same as the previous character, increment the count
    if (soz.charAt(i - 1) == soz.charAt(i)) {
        a[i] += 1;
    }
}

// Take the number of test cases 'n' as input
int n = sc.nextInt();

// Initialize an empty list 'arr' to store the differences
List<Integer> arr = new ArrayList<>();

// Iterate through the test cases
for (int i = 0; i < n; i++) {
    // Take two integers'm' and 'l' as input, separated by a space
    int m = sc.nextInt();
    int l = sc.nextInt();
    
    // Calculate the difference between the count at index 'l' and index'm'
    arr.add(a[l - 1] - a[m - 1]);
}

// Iterate through the list 'arr' and print each difference
for (int i : arr) {
    System.out.println(i);
}
