import java.util.*;

class Main{
    public static void main( String[] args ) {
	/* 
	 * The Scanner class is imported from the java.util package to enable input reading from the user.
	 */
	Scanner sc = new Scanner(System.in);
	/* 
	 * An instance of the Scanner class is created to read input from the standard input stream (keyboard).
	 */
	int A = sc.nextInt();
	int B = sc.nextInt();
	int C = sc.nextInt();
	/* 
	 * The program reads three integers A, B, and C from the user.
	 */
	if ( A == B && B == C && C == A ) System.out.println("Yes");
	else System.out.println("No");
	/* 
	 * The program checks if all three integers are equal. If they are, it prints "Yes"; otherwise, it prints "No".
	 */
    }
}