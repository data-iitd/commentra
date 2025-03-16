// Function to read input as a list of integers
public static int[] _input () {
    String[] s = sc.nextLine().split(" ");
    int[] arr = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        arr[i] = Integer.parseInt(s[i]);
    }
    return arr;
}

// Read number of elements 'n' and size 'm' of the list 'lst'
int[] arr = _input();
int n = arr[0];
int m = arr[1];

// Initialize an empty dictionary 'l' to store the frequency of each element
int[] lst = _input();
HashMap<Integer, Integer> l = new HashMap<>();

// Iterate through each element in the list 'lst'
for (int i = 0; i < n; i++) {
    // If the current element is not already present in the dictionary 'l'
    if (!l.containsKey(lst[i])) {
        // Add the current element to the dictionary 'l' with a frequency of 1
        l.put(lst[i], 1);
    }
    // If the current element is already present in the dictionary 'l'
    else {
        // Increment the frequency of the current element in the dictionary 'l'
        l.put(lst[i], l.get(lst[i]) + 1);
    }
}

// Initialize result variable 'res' to 0
int res = 0;

// Iterate through each element in the list 'lst'
for (int i = 0; i < n; i++) {
    // If the frequency of the current element in the dictionary 'l' is greater than 1
    if (l.get(lst[i]) > 1) {
        // Calculate the number of elements that have a smaller frequency than the current element
        // and add it to the result variable 'res'
        res += n - i - l.get(lst[i]);
        // Decrease the frequency of the current element in the dictionary 'l' by 1
        l.put(lst[i], l.get(lst[i]) - 1);
    }
    // If the frequency of the current element in the dictionary 'l' is equal to 1
    else {
        // Calculate the number of elements that have not been processed yet and add it to the result variable 'res'
        res += n - i - 1;
    }
}

// Print the final result
System.out.println(res);

