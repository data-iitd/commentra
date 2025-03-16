// Read a line of input, split it into components, and convert each component to an integer, storing them in a tuple
Scanner scanner = new Scanner(System.in);
String[] input = scanner.nextLine().split(" ");
int[] ABC = new int[input.length];
for (int i = 0; i < input.length; i++) {
    ABC[i] = Integer.parseInt(input[i]);
}

// Check if the number 5 appears exactly twice in the tuple
int count = 0;
for (int i = 0; i < ABC.length; i++) {
    if (ABC[i] == 5) {
        count++;
    }
}
if (count == 2) {
    // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
    int sum = 0;
    for (int i = 0; i < ABC.length; i++) {
        sum += ABC[i];
    }
    if (sum == 17) {
        System.out.println("YES");
    } else {
        System.out.println("NO");
    }
} else {
    // If 5 does not appear exactly twice, print 'NO'
    System.out.println("NO");
}

