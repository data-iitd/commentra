<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
 // Main function declaration

 var h,w int; // Variables for height and width of the grid
 fmt.Scanf("%d %d",&h,&w); // Read height and width from standard input
 var t string; // Initialize character array 't'
 var s string = "snuke" // Initialize character array's'
 for i:=0;i<h;i++{ // Iterate through each row of the grid
  for j:=0;j<w;j++{ // Iterate through each column of the grid
   fmt.Scanf("%s",&t); // Read a character from standard input
<<<<<<< HEAD
   if t == s{ // Check if current character matches the pattern'snuke'
=======
   if(s==t){ // Check if current character matches the pattern'snuke'
>>>>>>> 98c87cb78a (data updated)
    var c byte = byte(65+j); // Calculate the column index 'j' of the matching character and convert it to ASCII character
    fmt.Printf("%c%d\n",c,i+1); // Print the character and its row number to standard output
    return; // Exit the program if a match is found
   }
  }
 }

 return; // Return if no match is found
}

