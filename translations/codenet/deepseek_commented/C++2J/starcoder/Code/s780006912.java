import java.util.*;
public class Main{
  public static void main(String[] args){
    // Step 1: Declare the necessary variables.
    // We need to declare a variable to store the number of elements in the array and an array to store the elements.
    int n;
    int array[]=new int[100];
    
    // Step 2: Read the number of elements and the elements of the array.
    // We need to read the number of elements from the user and then read the elements of the array from the user.
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();
    for(int i=0;i<n;i++){
      array[i]=sc.nextInt();
    }
    
    // Step 3: Calculate the sum of the products of all pairs of elements in the array.
    // We need to use nested loops to iterate through all pairs of elements in the array and calculate their products.
    int sum=0;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        sum+=array[i]*array[j];
      }
    }
    
    // Step 4: Print the result.
    // Finally, we need to print the calculated sum.
    System.out.println(sum);
  }
}
