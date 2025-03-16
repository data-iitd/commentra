#include <iostream>                                                                                                                               
#include <map>                                                                                                                                    
using namespace std;                                                                                                                              
                                                                                                                                                  
int main() {                                                                                                                                      
    string str;                                                                                                                                   
    cin >> str;                                                                                                                                   
                                                                                                                                                  
    int max = 0, cnt = 0;                                                                                                                         
    for sc in str:                                                                                                                                
        if sc == 'A' or sc == 'C' or sc == 'G' or sc == 'T':                                                                                      
            cnt += 1                                                                                                                              
        else:                                                                                                                                     
            cnt = 0                                                                                                                               
        max = max if max > cnt else cnt                                                                                                           
                                                                                                                                                  
    print(max)                                                                                                                                   
}    

