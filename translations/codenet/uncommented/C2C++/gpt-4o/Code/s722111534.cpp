#include <iostream>
using namespace std;

int main() {
    int hcell, wcell, hpaint, wpaint, nblack, nwhite;
    // 順にマス行、マス列、塗る行、塗る列、塗られたマス、白いマス
    cin >> hcell >> wcell;
    cin >> hpaint >> wpaint;
    nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);
    nwhite = (hcell * wcell) - nblack;
    cout << nwhite << endl;
    return 0;
}

// <END-OF-CODE>
