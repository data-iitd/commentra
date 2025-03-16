#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Define constants for maximum sizes
#define MAX_STRING 30
#define MAX_LINE 2000000
#define MAX_HUMAN 200000

// Declare global arrays and variables
char sLongInputLine[MAX_LINE+1]="";
int  anComingSec[MAX_HUMAN];

int main() {

    // Declare variables for input and processing
    char sInput[MAX_STRING+1]="";
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

    // Read the first line of input which contains the number of humans and the water length
    fgets(sInput,MAX_STRING,stdin);
    if (strchr(sInput, '\n') != NULL) {
        sInput[strlen(sInput) - 1] = '\0';
    }
    psInput = strtok(sInput, " ");
    nHumanNumber = atoi(psInput);
    psInput = strtok(NULL, " ");
    nWaterLength = atoi(psInput);

    // Read the second line of input which contains the seconds when each human arrives
    fgets(sLongInputLine,MAX_LINE,stdin);
    if (strchr(sLongInputLine, '\n') != NULL) {
        sLongInputLine[strlen(sLongInputLine) - 1] = '\0';
    }
    psInput = strtok(sLongInputLine, " ");
    for (i=0;i<nHumanNumber;i++){
        anComingSec[i]=atoi(psInput);
        psInput = strtok(NULL, " ");
    }

    // Initialize the start time to the first human's arrival time
    nStart = anComingSec[0];

    // Process the data to calculate the water life
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

    // Output the result which is the total water life
    printf("%d\n",nWaterLife);

    return 0;
}
