

String[] input = scanner.nextLine().split(" ");  // Take input from user, split it into strings, and store in array input
int[] ABC = new int[3];  // Create an array of size 3 to store the integers

// Convert the strings in input to integers and store in ABC
for (int i = 0; i < 3; i++) {
    ABC[i] = Integer.parseInt(input[i]);
}

// Check if the array ABC contains exactly two 5s
int count = 0;
for (int i = 0; i < 3; i++) {
    if (ABC[i] == 5) {
        count++;
    }
}
if (count == 2) {
    // Check if the sum of the elements in ABC is 17
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += ABC[i];
    }
    System.out.println(sum == 17? "YES" : "NO");
} else {
    System.out.println("NO");
}

