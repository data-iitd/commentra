
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <ctype.h>
#include <complex.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>

using namespace std;


bool solve(){
	int maxsize=0;
	int maxcnt=0;
	int ans_num;
	int ans_num2;
	vector<string> str_v;
	
	char in[100];
	while(scanf("%s",in)!=EOF){
		str_v.push_back(in);
		if(maxsize < strlen(in)){
			maxsize = strlen(in);
			ans_num = str_v.size()-1;
		}
	}
	for(int i=0;i<str_v.size();i++){
		int cnt=0;
		for(int j=0;j<str_v.size();j++){
			if(str_v[i] == str_v[j]) cnt++;
		}
		if(maxcnt < cnt){
			maxcnt = cnt;
			ans_num2 = i;
		}
	}
	
	printf("%s %s\n", str_v[ans_num2].c_str(), str_v[ans_num].c_str());
	
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	solve();

	return 0;
}

