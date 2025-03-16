// Read an integer input N, which represents the number of elements in the list
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Read a line of input, split it into individual string elements, convert them to integers,
// and store them in a list A
List<Integer> A = new ArrayList<>();
for (int i = 0; i < N; i++) {
    A.add(sc.nextInt());
}

// Import necessary modules for calculating the greatest common divisor (GCD)
import java.util.stream.Collectors;

// Calculate the GCD of all elements in the list A using Java 8 Stream API
int gcd = A.stream().mapToInt(i -> i).reduce(Integer::gcd).getAsInt();

// Print the calculated GCD
System.out.println(gcd);

