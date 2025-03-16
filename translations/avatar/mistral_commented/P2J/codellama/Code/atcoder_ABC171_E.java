// Importing necessary functions
import java.util.Scanner;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

// Reading input
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int[] a = IntStream.range(0, N).map(i -> sc.nextInt()).toArray();

// Calculating the XOR of all elements in the list 'a'
int total = IntStream.range(0, N).map(i -> a[i]).reduce(0, (x, y) -> x ^ y);

// Printing the result
String result = IntStream.range(0, N).mapToObj(i -> String.valueOf(a[i] ^ total)).collect(Collectors.joining(" "));
System.out.println(result);

