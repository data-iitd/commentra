import java.util.*;

//update 2019/12/13

public class Main {

  static Scanner sc = new Scanner(System.in); // Initialize Scanner object for reading input

  public static void main(String[] args) {

    long n = nextLong(); // Read the first long integer from the input
    long a = nextLong(); // Read the second long integer from the input
    long b = nextLong(); // Read the third long integer from the input

    long sa = Math.abs(a-b); // Calculate the absolute difference between 'a' and 'b'

    long ans = 0; // Initialize answer variable to zero

    if(sa%2==0){ // Check if the difference is even
      ans = sa/2; // If even, then the answer is half of the difference
    }
    else{ // If the difference is odd
      long AAA = Math.min((n-a),(a-1)); // Calculate the minimum number between 'n-a' and 'a-1'
      long BBB = Math.min((n-b),(b-1)); // Calculate the minimum number between 'n-b' and 'b-1'

      ans = Math.min(AAA,BBB); // Choose the smaller minimum value

      // Decrease the difference by 1 to make it even
      sa -= 1;
      ans += 1;

      // Since the difference is even now, the answer is half of the difference plus 1
      ans += sa/2;

    }

    System.out.println(ans); // Print the answer

    //System.out.println(1/2); // Avoid division by zero error

  }

  static String next(){
    return sc.next();
  }

  static int nextInt(){
    return Integer.parseInt(sc.next());
  }

  static long nextLong(){
    return Long.parseLong(sc.next());
  }

  static double nextDouble(){
    return Double.parseDouble(sc.next());
  }

  static String[] splitString(String s){
    return s.split("");
  }

  static char[] splitChar(String s){
    return s.toCharArray();
  }

  static int charToInt(char aaa){
    return aaa - 48;
  }

  public static int maxInt(int[] a,int lng){
    int max=a[0];
    for(int i=1;i<lng;i++){
      max = Math.max(max,a[i]);
    }
    return max;
  }

  public static int minInt(int[] a,int lng){
    int min=a[0];
    for(int i=1;i<lng;i++){
      min = Math.min(min,a[i]);
    }
    return min;
  }

  public static long maxLong(long[] a,int lng){
    long max=a[0];
    for(int i=1;i<lng;i++){
      max = Math.max(max,a[i]);
    }
    return max;
  }

  public static long minLong(long[] a,int lng){
    long min=a[0];
    for(int i=1;i<lng;i++){
      min = Math.min(min,a[i]);
    }
    return min;
  }

}
