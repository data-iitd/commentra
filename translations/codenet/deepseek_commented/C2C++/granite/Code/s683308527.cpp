
#include<iostream>  // Include necessary headers
#include<string> // Include necessary headers

int main(){
  int n;  // Declare an integer to store the number of lines
  std::string s;  // Declare a string to store the input line
  std::cin>>n;  // Read the number of lines
  while(n--){  // Loop through each line
    std::getline(std::cin,s);  // Read the input line
    size_t pos=0;  // Initialize the position for string operations
    while((pos=s.find("Hoshino",pos))!=std::string::npos)s.replace(pos,7,"Hoshina");  // Replace "Hoshino" with "Hoshina"
    std::cout<<s<<std::endl;  // Print the modified line
  }
  return 0;  // Return 0 to indicate successful execution
}


