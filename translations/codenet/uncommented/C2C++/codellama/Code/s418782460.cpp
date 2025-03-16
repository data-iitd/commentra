#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define MAX_STRING 30
#define MAX_LINE 2000000
#define MAX_HUMAN 200000

using namespace std;

string sLongInputLine;
int anComingSec[MAX_HUMAN];

int main() {

	string sInput;
	char* psWord=NULL;
	char* psInput=NULL;

	int nHumanNumber=0;
	int nNextHumanIndex=0;
	int nWaterLength=0;
	int nWaterLife=0;
	int nStart=0;
	int nStop=0;

	int nIndex=0;
	int i=0;
	int j=0;

	// read line 1
	getline(cin,sInput);
	psInput = strtok((char*)sInput.c_str(), " ");
	nHumanNumber = atoi(psInput);
	psInput = strtok(NULL, " ");
	nWaterLength = atoi(psInput);

	getline(cin,sLongInputLine);
	psInput = strtok((char*)sLongInputLine.c_str(), " ");
	for (i=0;i<nHumanNumber;i++){
		anComingSec[i]=atoi(psInput);
		psInput = strtok(NULL, " ");
	}

	nStart = anComingSec[0];

	while(nNextHumanIndex<nHumanNumber){
		if (nNextHumanIndex == nHumanNumber){
			break;
		} else {
			nStop=nStart+nWaterLength;
			if (anComingSec[nNextHumanIndex]<nStop){
				while(nNextHumanIndex<nHumanNumber && anComingSec[nNextHumanIndex] < nStop){
					if (nStop <= anComingSec[nNextHumanIndex]+nWaterLength){
						nStop = anComingSec[nNextHumanIndex]+nWaterLength;
						nNextHumanIndex++;
					}
				}
				if (nNextHumanIndex == nHumanNumber){
					nWaterLife = nWaterLife + (nStop-nStart);
					break;
				}
			}
			nWaterLife = nWaterLife + (nStop-nStart);
			nStart=nStop;
			if (nStart<anComingSec[nNextHumanIndex]){
				nStart=anComingSec[nNextHumanIndex];
			}
		}
	}
	cout << nWaterLife << endl;

	return 0;

}

