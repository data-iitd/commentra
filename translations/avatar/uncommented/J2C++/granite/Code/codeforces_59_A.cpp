
#include <iostream>
#include <string>
using namespace std;

int main() {
string word;
cin >> word;
int uppercase = 0;
int lowercase = 0;
for (int i = 0; i < word.length(); i++) {
char ch = word[i];
if (isupper(ch)) {
uppercase++;
} else {
lowercase++;
}
}
if (uppercase > lowercase) {
transform(word.begin(), word.end(), word.begin(), ::toupper);
cout << word << endl;
} else if (lowercase > uppercase) {
transform(word.begin(), word.end(), word.begin(), ::tolower);
cout << word << endl;
} else {
transform(word.begin(), word.end(), word.begin(), ::tolower);
cout << word << endl;
}
return 0;
}

