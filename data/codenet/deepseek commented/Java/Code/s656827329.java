
import java.util.*;
public class Main {
  public static void main(String[] args){
    // Import the Scanner class to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read the number of elements in the array
    int n = sc.nextInt();
    
    // Initialize an array to store the elements
    int[] a = new int[n];
    
    // Read the elements of the array
    for(int i = 0;i<n;i++){
      a[i] = sc.nextInt();
    }
    
    // Initialize variables to count the number of trend changes and to track the current and previous trends
    int count = 1;
    int now = 0;
    int bef = 0;
    
    // Loop through the array starting from the second element
    for(int i = 1;i<n;i++){
      // Determine the current trend
      if(a[i-1]<a[i]){
        now = 1;
      }else if(a[i-1]>a[i]){
        now = -1;
      }else{
        continue;
      }
      
      // If this is the first comparison, set the previous trend
      if(bef == 0){
        bef = now;
      }
      
      // If the current trend is different from the previous trend, increment the count and reset the previous trend
      if(bef != now){
        count++;
        bef = 0;
      }
    }
    
    // Print the number of trend changes
    System.out.println(count);
  }
}

