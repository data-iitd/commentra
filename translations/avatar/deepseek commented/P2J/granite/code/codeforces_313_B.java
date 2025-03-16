

Scanner scanner = new Scanner(System.in);
String soz = scanner.nextLine();  // Take a string input from the user
int[] a = new int[soz.length() + 1];  // Initialize an array 'a' with zeros, with a length of soz.length() + 1

// Iterate over the string from index 1 to soz.length() - 1
for (int i = 1; i < soz.length(); i++) {
    a[i] = a[i - 1];  // Set 'a[i]' to the value of 'a[i - 1]'
    if (soz.charAt(i - 1) == soz.charAt(i)) {  // If the characters at positions 'i - 1' and 'i' are the same
        a[i] += 1;  // Increment 'a[i]' by 1
    }
}

int n = scanner.nextInt();  // Take an integer input from the user
List<Integer> arr = new ArrayList<>();  // Initialize an empty list 'arr'

// Iterate 'n' times
for (int i = 0; i < n; i++) {
    int m = scanner.nextInt();  // Take an integer input from the user
    int l = scanner.nextInt();  // Take an integer input from the user
    arr.add(a[l - 1] - a[m - 1]);  // Append the difference 'a[l - 1] - a[m - 1]' to 'arr'
}

// Print each element in 'arr'
for (int i : arr) {
    System.out.println(i);
}
