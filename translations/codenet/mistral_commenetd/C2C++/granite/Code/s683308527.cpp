

#include<iostream> // Include standard input/output library
#include<string> // Include string manipulation library

int main(){ // Start of the main function
  int n; // Declare an integer variable 'n' to store the number of strings to be processed
  std::string s; // Declare a string variable's' to store each string read from the input

  std::cin>>n; // Read an integer 'n' from the standard input

  while(n--){ // Start of the while loop that processes each string
    std::getline(std::cin,s); // Read a string from the standard input into the string variable's'

    size_t pos=0; // Initialize a size_t variable 'pos' to store the position of the substring "Hoshino" in the string's'

    while((pos=s.find("Hoshino",pos))!=std::string::npos){ // Start of the inner while loop that replaces the substring "Hoshino" with "aana"
      s.replace(pos,6,"aana"); // Replace the substring "Hoshino" with "aana" starting at position 'pos' and of length 6
      pos+=5; // Increment the position 'pos' by 5 to move to the next occurrence of the substring "Hoshino"
    }

    std::cout<<s<<std::endl; // Print the modified string to the standard output
  }

  return 0; // End of the main function with a return value of 0 indicating successful execution
}

