import java.util.*;

//update 2019/12/13

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    // Read input values for n, a, and b
    long n = nextLong();
    long a = nextLong();
    long b = nextLong();

    // Calculate the absolute difference between a and b
    long sa = Math.abs(a-b);

    // Initialize the answer variable
    long ans = 0;

    // Check if the absolute difference is even
    if(sa%2==0){
      // If sa is even, the answer is half of sa
      ans = sa/2;
    }
    else{
      // If sa is odd, calculate the minimum steps for one position to reach the end
      long AAA = Math.min((n-a),(a-1));
      long BBB = Math.min((n-b),(b-1));

      // The answer is the minimum of the two calculated values
      ans = Math.min(AAA,BBB); // One position reaches the end first

      // Adjust to make the difference even by reducing sa by 1 and incrementing the answer by 1
      sa -= 1;
      ans += 1;

      // Add the remaining steps to make the difference even
      ans += sa/2;

    }

    // Print the final answer
    System.out.println(ans);

  }

  // Helper methods to read different types of input
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

  // Methods to split strings and convert characters to integers
  static String[] splitString(String s){
    return s.split("");
  }

  static char[] splitChar(String s){
    return s.toCharArray();
  }

  static int charToInt(char aaa){
    return aaa - 48;
  }

  // Methods to find maximum and minimum values in arrays
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
