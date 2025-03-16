
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to read a single line of input and convert it to a tuple of integers
void value(int *a, int *b) {
    int c;
    scanf("%d %d", a, b);
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
void values(int *a, int *b) {
    int c;
    scanf("%d %d", a, b);
}

// Function to read a single line of input and return a list of integers
void inlst(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
}

// Function to read a single line of input from stdin and return a list of integers
void inlsts(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
}

// Function to read a single integer from input
int inp() {
    int a;
    scanf("%d", &a);
    return a;
}

// Function to read a single integer from stdin
int inps() {
    int a;
    scanf("%d", &a);
    return a;
}

// Function to read a single line of input and return it as a string
char* instr() {
    char a[1000];
    scanf("%s", a);
    return a;
}

// Function to read a single line of input and return it as a list of strings
void stlst(char** a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
}

// Helper function to determine if a specific arrangement is possible
int help(int a, int b, int* l, int n) {
    int i, j, k;
    int tot[1000];
    memset(tot, 0, sizeof(tot));
    
    // Create sublists of length 'a' from the list 'l'
    for (i = 0; i < b; i++) {
        for (j = i * a; j < i * a + a; j++) {
            tot[j] = 1;
        }
    }
    
    // Check if any combination of the sublists sums to 'b'
    for (i = 0; i < n; i++) {
        if (tot[i] == 1) {
            for (j = i + 1; j < n; j++) {
                if (tot[j] == 1) {
                    for (k = j + 1; k < n; k++) {
                        if (tot[k] == 1) {
                            if (l[i] + l[j] + l[k] == b) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// Main function to solve the problem
void solve() {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h;
    int A, B, C, D, E, F, G, H;
    int tc, t;
    char ch, ch1, ch2, ch3;
    char* str;
    int* ar;
    int ars[1000];
    int res;
    int fl;
    int fl1;
    int fl2;
    int fl3;
    int fl4;
    int fl5;
    int fl6;
    int fl7;
    int fl8;
    int fl9;
    int fl10;
    int fl11;
    int fl12;
    int fl13;
    int fl14;
    int fl15;
    int fl16;
    int fl17;
    int fl18;
    int fl19;
    int fl20;
    int fl21;
    int fl22;
    int fl23;
    int fl24;
    int fl25;
    int fl26;
    int fl27;
    int fl28;
    int fl29;
    int fl30;
    int fl31;
    int fl32;
    int fl33;
    int fl34;
    int fl35;
    int fl36;
    int fl37;
    int fl38;
    int fl39;
    int fl40;
    int fl41;
    int fl42;
    int fl43;
    int fl44;
    int fl45;
    int fl46;
    int fl47;
    int fl48;
    int fl49;
    int fl50;
    int fl51;
    int fl52;
    int fl53;
    int fl54;
    int fl55;
    int fl56;
    int fl57;
    int fl58;
    int fl59;
    int fl60;
    int fl61;
    int fl62;
    int fl63;
    int fl64;
    int fl65;
    int fl66;
    int fl67;
    int fl68;
    int fl69;
    int fl70;
    int fl71;
    int fl72;
    int fl73;
    int fl74;
    int fl75;
    int fl76;
    int fl77;
    int fl78;
    int fl79;
    int fl80;
    int fl81;
    int fl82;
    int fl83;
    int fl84;
    int fl85;
    int fl86;
    int fl87;
    int fl88;
    int fl89;
    int fl90;
    int fl91;
    int fl92;
    int fl93;
    int fl94;
    int fl95;
    int fl96;
    int fl97;
    int fl98;
    int fl99;
    int fl100;
    int fl101;
    int fl102;
    int fl103;
    int fl104;
    int fl105;
    int fl106;
    int fl107;
    int fl108;
    int fl109;
    int fl110;
    int fl111;
    int fl112;
    int fl113;
    int fl114;
    int fl115;
    int fl116;
    int fl117;
    int fl118;
    int fl119;
    int fl120;
    int fl121;
    int fl122;
    int fl123;
    int fl124;
    int fl125;
    int fl126;
    int fl127;
    int fl128;
    int fl129;
    int fl130;
    int fl131;
    int fl132;
    int fl133;
    int fl134;
    int fl135;
    int fl136;
    int fl137;
    int fl138;
    int fl139;
    int fl140;
    int fl141;
    int fl142;
    int fl143;
    int fl144;
    int fl145;
    int fl146;
    int fl147;
    int fl148;
    int fl149;
    int fl150;
    int fl151;
    int fl152;
    int fl153;
    int fl154;
    int fl155;
    int fl156;
    int fl157;
    int fl158;
    int fl159;
    int fl160;
    int fl161;
    int fl162;
    int fl163;
    int fl164;
    int fl165;
    int fl166;
    int fl167;
    int fl168;
    int fl169;
    int fl170;
    int fl171;
    int fl172;
    int fl173;
    int fl174;
    int fl175;
    int fl176;
    int fl177;
    int fl178;
    int fl179;
    int fl180;
    int fl181;
    int fl182;
    int fl183;
    int fl184;
    int fl185;
    int fl186;
    int fl187;
    int fl188;
    int fl189;
    int fl190;
    int fl191;
    int fl192;
    int fl193;
    int fl194;
    int fl195;
    int fl196;
    int fl197;
    int fl198;
    int fl199;
    int fl200;
    int fl201;
    int fl202;
    int fl203;
    int fl204;
    int fl205;
    int fl206;
    int fl207;
    int fl208;
    int fl209;
    int fl210;
    int fl211;
    int fl212;
    int fl213;
    int fl214;
    int fl215;
    int fl216;
    int fl217;
    int fl218;
    int fl219;
    int fl220;
    int fl221;
    int fl222;
    int fl223;
    int fl224;
    int fl225;
    int fl226;
    int fl227;
    int fl228;
    int fl229;
    int fl230;
    int fl231;
    int fl232;
    int fl233;
    int fl234;
    int fl235;
    int fl236;
    int fl237;
    int fl238;
    int fl239;
    int fl240;
    int fl241;
    int fl242;
    int fl243;
    int fl244;
    int fl245;
    int fl246;
    int fl247;
    int fl248;
    int fl249;
    int fl250;
    int fl251;
    int fl252;
    int fl253;
    int fl254;
    int fl255;
    int fl256;
    int fl257;
    int fl258;
    int fl259;
    int fl260;
    int fl261;
    int fl262;
    int fl263;
    int fl264;
    int fl265;
    int fl266;
    int fl267;
    int fl268;
    int fl269;
    int fl270;
    int fl271;
    int fl272;
    int fl273;
    int fl274;
    int fl275;
    int fl276;
    int fl277;
    int fl278;
    int fl279;
    int fl280;
    int fl281;
    int fl282;
    int fl283;
    int fl284;
    int fl285;
    int fl286;
    int fl287;
    int fl288;
    int fl289;
    int fl290;
    int fl291;
    int fl292;
    int fl293;
    int fl294;
    int fl295;
    int fl296;
    int fl297;
    int fl298;
    int fl299;
    int fl300;
    int fl301;
    int fl302;
    int fl303;
    int fl304;
    int fl305;
    int fl306;
    int fl307;
    int fl308;
    int fl309;
    int fl310;
    int fl311;
    int fl312;
    int fl313;
    int fl314;
    int fl315;
    int fl316;
    int fl317;
    int fl318;
    int fl319;
    int fl320;
    int fl321;
    int fl322;
    int fl323;
    int fl324;
    int fl325;
    int fl326;
    int fl327;
    int fl328;
    int fl329;
    int fl330;
    int fl331;
    int fl332;
    int fl333;
    int fl334;
    int fl335;
    int fl336;
    int fl337;
    int fl338;
    int fl339;
    int fl340;
    int fl341;
    int fl342;
    int fl343;
    int fl344;
    int fl345;
    int fl346;
    int fl347;
    int fl348;
    int fl349;
    int fl350;
    int fl351;
    int fl352;
    int fl353;
    int fl354;
    int fl355;
    int fl356;
    int fl357;
    int fl358;
    int fl359;
    int fl360;
    int fl361;
    int fl362;
    int fl363;
    int fl364;
    int fl365;
    int fl366;
    int fl367;
    int fl368;
    int fl369;
    int fl370;
    int fl371;
    int fl372;
    int fl373;
    int fl374;
    int fl375;
    int fl376;
    int fl377;
    int fl378;
    int fl379;
    int fl380;
    int fl381;
    int fl382;
    int fl383;
    int fl384;
    int fl385;
    int fl386;
    int fl387;
    int fl388;
    int fl389;
    int fl390;
    int fl391;
    int fl392;
    int fl393;
    int fl394;
    int fl395;
    int fl396;
    int fl397;
    int fl398;
    int fl399;
    int fl400;
    int fl401;
    int fl402;
    int fl403;
    int fl404;
    int fl405;
    int fl406;
    int fl407;
    int fl408;
    int fl409;
    int fl410;
    int fl411;
    int fl412;
    int fl413;
    int fl414;
    int fl415;
    int fl416;
    int fl417;
    int fl418;
    int fl419;
    int fl420;
    int fl421;
    int fl422;
    int fl423;
    int fl424;
    int fl425;
    int fl426;
    int fl427;
    int fl428;
    int fl429;
    int fl430;
    int fl431;
    int fl432;
    int fl433;
    int fl434;
    int fl435;
    int fl436;
    int fl437;
    int fl438;
    int fl439;
    int fl440;
    int fl441;
    int fl442;
    int fl443;
    int fl444;
    int fl445;
    int fl446;
    int fl447;
    int fl448;
    int fl449;
    int fl450;
    int fl451;
    int fl452;
    int fl453;
    int fl454;
    int fl455;
    int fl456;
    int fl457;
    int fl458;
    int fl459;
    int fl460;
    int fl461;
    int fl462;
    int fl463;
    int fl464;
    int fl465;
    int fl466;
    int fl467;
    int fl468;
    int fl469;
    int fl470;
    int fl471;
    int fl472;
    int fl473;
    int fl474;
    int fl475;
    int fl476;
    int fl477;
    int fl478;
    int fl479;
    int fl480;
    int fl481;
    int fl482;
    int fl483;
    int fl484;
    int fl485;
    int fl486;
    int fl487;
    int fl488;
    int fl489;
    int fl490;
    int fl491;
    int fl492;
    int fl493;
    int fl494;
    int fl495;
    int fl496;
    int fl497;
    int fl498;
    int fl499;
    int fl500;
    int fl501;
    int fl502;
    int fl503;
    int fl504;
    int fl505;
    int fl506;
    int fl507;
    int fl508;