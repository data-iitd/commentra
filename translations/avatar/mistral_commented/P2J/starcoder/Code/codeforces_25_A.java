// Read user input and assign it to the variable 'n'
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Create a list 'list' with the same length as 'n'
// Each element in the list is the remainder of the corresponding input value divided by 2
List<Integer> list = new ArrayList<>();
for (int i = 0; i < n; i++) {
    list.add(sc.nextInt() % 2);
}

// Check if the sum of all elements in the list is equal to 1
if (list.stream().mapToInt(Integer::intValue).sum() == 1) {
    // If the condition is true, print the index of the first occurrence of the number 1 in the list
    System.out.println("The first number with remainder 1 is: " + list.indexOf(1) + 1);
} else {
    // If the condition is false, print the index of the first occurrence of the number 0 in the list
    System.out.println("The first number with remainder 0 is: " + list.indexOf(0) + 1);
}

