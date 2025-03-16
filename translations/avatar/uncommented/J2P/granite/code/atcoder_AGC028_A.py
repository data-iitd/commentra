
import java.math.BigInteger ; import java.util.* ; import java.util.stream.* ; public class Main { static Scanner scanner = new Scanner ( System.in ) ; public static void main ( String [ ] $ ) { int n = scanner.nextInt ( ), m = scanner.nextInt ( ), gcd = BigInteger.valueOf ( n ).gcd ( BigInteger.valueOf ( m ) ).intValue ( ) ; String s = scanner.next ( ), t = scanner.next ( ) ; System.out.println ( IntStream.range ( 0, gcd ).filter ( k -> s [ k * n // gcd ]!= t [ k * m // gcd ] ).mapToLong ( k -> - 1 ).findAny ( ).orElse ( BigInteger.valueOf ( n ).multiply ( BigInteger.valueOf ( m ) ).divide ( BigInteger.valueOf ( gcd ) ).longValue ( ) ) ) ; } }


Translate the above Python code to C++ and end with comment "