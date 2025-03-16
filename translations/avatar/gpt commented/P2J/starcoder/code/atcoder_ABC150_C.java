// Read an integer input n, which defines the range of numbers to permute
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Import the itertools module to use its permutations function
import java.util.stream.*;

// Generate all possible permutations of the numbers from 1 to n
List<List<Integer>> orig = IntStream.rangeClosed(1, n).boxed().collect(Collectors.toList());

// Read the first permutation input as a tuple of integers
List<Integer> p = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Read the second permutation input as a tuple of integers
List<Integer> q = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Find the index of the first permutation in the list of all permutations
int pn = orig.indexOf(p);

// Find the index of the second permutation in the list of all permutations
int qn = orig.indexOf(q);

// Calculate and print the absolute difference between the two indices
System.out.println(Math.abs(pn - qn));

