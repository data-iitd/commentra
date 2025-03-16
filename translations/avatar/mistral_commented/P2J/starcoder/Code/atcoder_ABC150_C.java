
// Ask the user for the size of the permutation list
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Import the itertools module for generating permutations
import java.util.stream.*;

// Create a list of all possible permutations of numbers from 1 to n
List<List<Integer>> orig = IntStream.range(1, n+1).boxed().collect(Collectors.toList());

// Ask the user for two permutations as tuples
List<Integer> p = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
List<Integer> q = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Find the indices of p and q in the orig list
int pn = orig.indexOf(p);
int qn = orig.indexOf(q);

// Print the absolute difference between the indices of p and q
System.out.println(Math.abs(pn - qn));

