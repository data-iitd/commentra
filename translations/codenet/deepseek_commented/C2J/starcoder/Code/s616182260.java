import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int a[]=new int[3];
    int b[]=new int[3];
    int c[][]=new int[3][3];
    int i,j;
    
    // Read the 3x3 matrix from the input
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        c[i][j]=sc.nextInt();
      }
    }
    
    // Initialize the first element of array a to 0
    a[0]=0;
    
    // Assign the first row of the matrix to array b
    for(i=0;i<3;i++){
      b[i]=c[0][i];
    }
    
    // Calculate the remaining elements of array a
    for(i=1;i<3;i++){
      a[i]=c[i][0]-b[0];
    }
    
    // Check if each element of the matrix is equal to the sum of the corresponding elements of a and b
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        if(c[i][j]!=a[i]+b[j]){
          System.out.println("No");
          return;
        }
      }
    }
    
    // If all elements match, print "Yes"
    System.out.println("Yes");
  }
}
