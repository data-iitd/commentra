
Scanner scanner = new Scanner(System.in);

// Take input from user, split it into integers, and store in array ABC
int[] ABC = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

// Check if the array contains exactly two 5s
if (Arrays.stream(ABC).filter(x -> x == 5).count() == 2) {
    // Check if the sum of the elements in ABC is 17
    if (Arrays.stream(ABC).sum() == 17) {
        System.out.println("YES");
    } else {
        System.out.println("NO");
    }
} else {
    System.out.println("NO");
}

