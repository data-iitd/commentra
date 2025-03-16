
// Including necessary header files
import java.io.*;
import java.util.*;

// Macros for iteration
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)

// Function prototypes and necessary definitions
inline int read();
inline void write(int x);
inline void writeln(int x);

// Main function
public class Main{

	// Main function
	public static void main(String[] args){

		// Reading input
		int n=read();

		// Reading array 'a'
		int[] a=new int[n+1];
		For(i,1,n)	a[i]=read();

		// Sorting array 'a' in ascending order
		Arrays.sort(a);

		// Finding duplicate elements and storing them in 'q'
		int[] q=new int[n+1];
		int tot=0;
		For(i,1,n)	// Iterating through array 'a'
			if (a[i]==a[i+1])	// Checking if current element is same as next element
				q[++tot]=a[i],	// If yes, storing it in 'q'
				i++;		// Incrementing index 'i'

		// Outputting the result
		writeln(q[tot]*q[tot-1]);

	}

	// Function definitions
	public static void write(int x){
		System.out.print(x);
	}

	public static void writeln(int x){
		System.out.println(x);
	}

	public static int read(){
		return Integer.parseInt(System.console().readLine());
	}

}

