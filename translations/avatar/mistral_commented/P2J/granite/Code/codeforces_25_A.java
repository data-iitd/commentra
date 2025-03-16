
// Read user input and assign it to the variable 'n'
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();

// Create a list 'list' with the same length as 'n'
// Each element in the list is the remainder of the corresponding input value divided by 2
List<Integer> list = new ArrayList<>();
for (int i = 0; i < n; i++) {
    int x = scanner.nextInt();
    list.add(x % 2);
}

// Check if the sum of all elements in the list is equal to 1
int sum = 0;
for (int i = 0; i < list.size(); i++) {
    sum += list.get(i);
}
if (sum == 1) {
    // If the condition is true, print the index of the first occurrence of the number 1 in the list
    for (int i = 0; i < list.size(); i++) {
        if (list.get(i) == 1) {
            System.out.println("The first number with remainder 1 is: " + (i + 1));
            break;
        }
    }
} else {
    // If the condition is false, print the index of the first occurrence of the number 0 in the list
    for (int i = 0; i < list.size(); i++) {
        if (list.get(i) == 0) {
            System.out.println("The first number with remainder 0 is: " + (i + 1));
            break;
        }
    }
}

