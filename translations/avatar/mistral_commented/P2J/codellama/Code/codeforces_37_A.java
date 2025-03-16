// Take the number of elements in the list as input
int n = sc.nextInt();

// Initialize an empty list 'l' to store the input elements
List<Integer> l = new ArrayList<>();

// Read the list elements from the standard input, convert them to integers and append to the list
for (int i = 0; i < n; i++) {
    l.add(sc.nextInt());
}

// Initialize variables 'high' and 'tower' with initial values
int high = 1;
int tower = n;

// Iterate through the list starting from the second element
for (int i = 1; i < n; i++) {
    // If the current element is same as the previous one, decrement 'tower' and increment 'high'
    if (l.get(i) == l.get(i-1)) {
        tower--;
        high++;
    }
    // If the current element is different, check if 'high' is greater than the current maximum and update it if true
    else {
        if (high > maximum) {
            maximum = high;
        }
        high = 1;
    }
}

// Check if the last 'high' value is greater than the current maximum and update it if true
if (high > maximum) {
    maximum = high;
}

// Print the final result
System.out.println(maximum + " " + tower);

