#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;

#define INF 1001001001001001LL
#define inf 1000000007
#define MOD 1000000007LL
#define PI 3.1415926535897932

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

#define chmin(a,b) if(a>b) a=b
#define chmax(a,b) if(a<b) a=b

#define do_best do{
#define end_of_do }while(0);

#define do_best_2 do{
#define end_of_do_2 }while(0);

#define do_best_3 do{
#define end_of_do_3 }while(0);

#define do_best_4 do{
#define end_of_do_4 }while(0);

#define do_best_5 do{
#define end_of_do_5 }while(0);

#define do_best_6 do{
#define end_of_do_6 }while(0);

#define do_best_7 do{
#define end_of_do_7 }while(0);

#define do_best_8 do{
#define end_of_do_8 }while(0);

#define do_best_9 do{
#define end_of_do_9 }while(0);

#define do_best_10 do{
#define end_of_do_10 }while(0);

#define do_best_11 do{
#define end_of_do_11 }while(0);

#define do_best_12 do{
#define end_of_do_12 }while(0);

#define do_best_13 do{
#define end_of_do_13 }while(0);

#define do_best_14 do{
#define end_of_do_14 }while(0);

#define do_best_15 do{
#define end_of_do_15 }while(0);

#define do_best_16 do{
#define end_of_do_16 }while(0);

#define do_best_17 do{
#define end_of_do_17 }while(0);

#define do_best_18 do{
#define end_of_do_18 }while(0);

#define do_best_19 do{
#define end_of_do_19 }while(0);

#define do_best_20 do{
#define end_of_do_20 }while(0);

#define do_best_21 do{
#define end_of_do_21 }while(0);

#define do_best_22 do{
#define end_of_do_22 }while(0);

#define do_best_23 do{
#define end_of_do_23 }while(0);

#define do_best_24 do{
#define end_of_do_24 }while(0);

#define do_best_25 do{
#define end_of_do_25 }while(0);

#define do_best_26 do{
#define end_of_do_26 }while(0);

#define do_best_27 do{
#define end_of_do_27 }while(0);

#define do_best_28 do{
#define end_of_do_28 }while(0);

#define do_best_29 do{
#define end_of_do_29 }while(0);

#define do_best_30 do{
#define end_of_do_30 }while(0);

#define do_best_31 do{
#define end_of_do_31 }while(0);

#define do_best_32 do{
#define end_of_do_32 }while(0);

#define do_best_33 do{
#define end_of_do_33 }while(0);

#define do_best_34 do{
#define end_of_do_34 }while(0);

#define do_best_35 do{
#define end_of_do_35 }while(0);

#define do_best_36 do{
#define end_of_do_36 }while(0);

#define do_best_37 do{
#define end_of_do_37 }while(0);

#define do_best_38 do{
#define end_of_do_38 }while(0);

#define do_best_39 do{
#define end_of_do_39 }while(0);

#define do_best_40 do{
#define end_of_do_40 }while(0);

#define do_best_41 do{
#define end_of_do_41 }while(0);

#define do_best_42 do{
#define end_of_do_42 }while(0);

#define do_best_43 do{
#define end_of_do_43 }while(0);

#define do_best_44 do{
#define end_of_do_44 }while(0);

#define do_best_45 do{
#define end_of_do_45 }while(0);

#define do_best_46 do{
#define end_of_do_46 }while(0);

#define do_best_47 do{
#define end_of_do_47 }while(0);

#define do_best_48 do{
#define end_of_do_48 }while(0);

#define do_best_49 do{
#define end_of_do_49 }while(0);

#define do_best_50 do{
#define end_of_do_50 }while(0);

#define do_best_51 do{
#define end_of_do_51 }while(0);

#define do_best_52 do{
#define end_of_do_52 }while(0);

#define do_best_53 do{
#define end_of_do_53 }while(0);

#define do_best_54 do{
#define end_of_do_54 }while(0);

#define do_best_55 do{
#define end_of_do_55 }while(0);

#define do_best_56 do{
#define end_of_do_56 }while(0);

#define do_best_57 do{
#define end_of_do_57 }while(0);

#define do_best_58 do{
#define end_of_do_58 }while(0);

#define do_best_59 do{
#define end_of_do_59 }while(0);

#define do_best_60 do{
#define end_of_do_60 }while(0);

#define do_best_61 do{
#define end_of_do_61 }while(0);

#define do_best_62 do{
#define end_of_do_62 }while(0);

#define do_best_63 do{
#define end_of_do_63 }while(0);

#define do_best_64 do{
#define end_of_do_64 }while(0);

#define do_best_65 do{
#define end_of_do_65 }while(0);

#define do_best_66 do{
#define end_of_do_66 }while(0);

#define do_best_67 do{
#define end_of_do_67 }while(0);

#define do_best_68 do{
#define end_of_do_68 }while(0);

#define do_best_69 do{
#define end_of_do_69 }while(0);

#define do_best_70 do{
#define end_of_do_70 }while(0);

#define do_best_71 do{
#define end_of_do_71 }while(0);

#define do_best_72 do{
#define end_of_do_72 }while(0);

#define do_best_73 do{
#define end_of_do_73 }while(0);

#define do_best_74 do{
#define end_of_do_74 }while(0);

#define do_best_75 do{
#define end_of_do_75 }while(0);

#define do_best_76 do{
#define end_of_do_76 }while(0);

#define do_best_77 do{
#define end_of_do_77 }while(0);

#define do_best_78 do{
#define end_of_do_78 }while(0);

#define do_best_79 do{
#define end_of_do_79 }while(0);

#define do_best_80 do{
#define end_of_do_80 }while(0);

#define do_best_81 do{
#define end_of_do_81 }while(0);

#define do_best_82 do{
#define end_of_do_82 }while(0);

#define do_best_83 do{
#define end_of_do_83 }while(0);

#define do_best_84 do{
#define end_of_do_84 }while(0);

#define do_best_85 do{
#define end_of_do_85 }while(0);

#define do_best_86 do{
#define end_of_do_86 }while(0);

#define do_best_87 do{
#define end_of_do_87 }while(0);

#define do_best_88 do{
#define end_of_do_88 }while(0);

#define do_best_89 do{
#define end_of_do_89 }while(0);

#define do_best_90 do{
#define end_of_do_90 }while(0);

#define do_best_91 do{
#define end_of_do_91 }while(0);

#define do_best_92 do{
#define end_of_do_92 }while(0);

#define do_best_93 do{
#define end_of_do_93 }while(0);

#define do_best_94 do{
#define end_of_do_94 }while(0);

#define do_best_95 do{
#define end_of_do_95 }while(0);

#define do_best_96 do{
#define end_of_do_96 }while(0);

#define do_best_97 do{
#define end_of_do_97 }while(0);

#define do_best_98 do{
#define end_of_do_98 }while(0);

#define do_best_99 do{
#define end_of_do_99 }while(0);

#define do_best_100 do{
#define end_of_do_100 }while(0);

#define do_best_101 do{
#define end_of_do_101 }while(0);

#define do_best_102 do{
#define end_of_do_102 }while(0);

#define do_best_103 do{
#define end_of_do_103 }while(0);

#define do_best_104 do{
#define end_of_do_104 }while(0);

#define do_best_105 do{
#define end_of_do_105 }while(0);

#define do_best_106 do{
#define end_of_do_106 }while(0);

#define do_best_107 do{
#define end_of_do_107 }while(0);

#define do_best_108 do{
#define end_of_do_108 }while(0);

#define do_best_109 do{
#define end_of_do_109 }while(0);

#define do_best_110 do{
#define end_of_do_110 }while(0);

#define do_best_111 do{
#define end_of_do_111 }while(0);

#define do_best_112 do{
#define end_of_do_112 }while(0);

#define do_best_113 do{
#define end_of_do_113 }while(0);

#define do_best_114 do{
#define end_of_do_114 }while(0);

#define do_best_115 do{
#define end_of_do_115 }while(0);

#define do_best_116 do{
#define end_of_do_116 }while(0);

#define do_best_117 do{
#define end_of_do_117 }while(0);

#define do_best_118 do{
#define end_of_do_118 }while(0);

#define do_best_119 do{
#define end_of_do_119 }while(0);

#define do_best_120 do{
#define end_of_do_120 }while(0);

#define do_best_121 do{
#define end_of_do_121 }while(0);

#define do_best_122 do{
#define end_of_do_122 }while(0);

#define do_best_123 do{
#define end_of_do_123 }while(0);

#define do_best_124 do{
#define end_of_do_124 }while(0);

#define do_best_125 do{
#define end_of_do_125 }while(0);

#define do_best_126 do{
#define end_of_do_126 }while(0);

#define do_best_127 do{
#define end_of_do_127 }while(0);

#define do_best_128 do{
#define end_of_do_128 }while(0);

#define do_best_129 do{
#define end_of_do_129 }while(0);

#define do_best_130 do{
#define end_of_do_130 }while(0);

#define do_best_131 do{
#define end_of_do_131 }while(0);

#define do_best_132 do{
#define end_of_do_132 }while(0);

#define do_best_133 do{
#define end_of_do_133 }while(0);

#define do_best_134 do{
#define end_of_do_134 }while(0);

#define do_best_135 do{
#define end_of_do_135 }while(0);

#define do_best_136 do{
#define end_of_do_136 }while(0);

#define do_best_137 do{
#define end_of_do_137 }while(0);

#define do_best_138 do{
#define end_of_do_138 }while(0);

#define do_best_139 do{
#define end_of_do_139 }while(0);

#define do_best_140 do{
#define end_of_do_140 }while(0);

#define do_best_141 do{
#define end_of_do_141 }while(0);

#define do_best_142 do{
#define end_of_do_142 }while(0);

#define do_best_143 do{
#define end_of_do_143 }while(0);

#define do_best_144 do{
#define end_of_do_144 }while(0);

#define do_best_145 do{
#define end_of_do_145 }while(0);

#define do_best_146 do{
#define end_of_do_146 }while(0);

#define do_best_147 do{
#define end_of_do_147 }while(0);

#define do_best_148 do{
#define end_of_do_148 }while(0);

#define do_best_149 do{
#define end_of_do_149 }while(0);

#define do_best_150 do{
#define end_of_do_150 }while(0);

#define do_best_151 do{
#define end_of_do_151 }while(0);

#define do_best_152 do{
#define end_of_do_152 }while(0);

#define do_best_153 do{
#define end_of_do_153 }while(0);

#define do_best_154 do{
#define end_of_do_154 }while(0);

#define do_best_155 do{
#define end_of_do_155 }while(0);

#define do_best_156 do{
#define end_of_do_156 }while(0);

#define do_best_157 do{
#define end_of_do_157 }while(0);

#define do_best_158 do{
#define end_of_do_158 }while(0);

#define do_best_159 do{
#define end_of_do_159 }while(0);

#define do_best_160 do{
#define end_of_do_160 }while(0);

#define do_best_161 do{
#define end_of_do_161 }while(0);

#define do_best_162 do{
#define end_of_do_162 }while(0);

#define do_best_163 do{
#define end_of_do_163 }while(0);

#define do_best_164 do{
#define end_of_do_164 }while(0);

#define do_best_165 do{
#define end_of_do_16