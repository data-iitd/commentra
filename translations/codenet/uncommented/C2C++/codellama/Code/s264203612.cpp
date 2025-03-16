#include <iostream>

int main(){
    double r;
    double s,l;
    double p = 3.141592653589;
    std::cin >> r;
    
    s = r*r*p;
    l = 2*p*r;
    
    std::cout << s << " " << l << std::endl;
    
    return 0;
}

