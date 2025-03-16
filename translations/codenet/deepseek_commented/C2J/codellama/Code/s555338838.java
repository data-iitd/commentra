
public class InsertionSort {
  public static void main(String[] args) {
    int key, i, j, len, a[] = new int[101];
    
    // Step 1: Read the length of the array
    len = Integer.parseInt(args[0]);
    
    // Step 2: Read the elements of the array
    for(i = 0;i < len;i++) a[i] = Integer.parseInt(args[i + 1]);

    // Step 3: Perform Insertion Sort
    for(j = 1;j < len;j++){
      // Print the array before each iteration
      for(i = 0;i < len;i++) System.out.print(i != 0 ? " " + a[i]: a[i]);
      System.out.println();
      
      // Store the current element to be inserted
      key = a[j];
      
      // Shift elements to the right to make space for the key
      for(i = j - 1;i >= 0 && a[i] > key;i--) a[i + 1] = a[i];
      
      // Insert the key into the correct position
      a[i + 1] = key;
    }

    // Step 4: Print the sorted array
    for(i = 0;i < len;i++) System.out.print(i != 0 ? " " + a[i]: a[i]);
    System.out.println();
  }
}

