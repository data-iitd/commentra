// Importing necessary functions
import java.util.stream.IntStream;

// Reading input
int N = Integer.parseInt(sc.nextLine());
int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

// Calculating the XOR of all elements in the list 'a'
int total = IntStream.of(a).reduce(0, (x, y) -> x ^ y);

// Printing the result
System.out.println(Arrays.stream(a).mapToObj(i -> Integer.toString(i ^ total)).collect(Collectors.joining(" ")));

