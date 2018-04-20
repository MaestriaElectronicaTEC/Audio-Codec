/* Test for cfft: rand */
#define NX 128
#define FNAME "t5"
#define MAXERROR 16

#pragma DATA_SECTION (x,".input")

DATA x[2*NX] ={
-10290,	17199,	/* 0 */ 
-22899,	-2458,	/* 1 */ 
9811,	23191,	/* 2 */ 
7624,	-17922,	/* 3 */ 
24531,	18789,	/* 4 */ 
2675,	13684,	/* 5 */ 
-5076,	-2837,	/* 6 */ 
-15299,	6126,	/* 7 */ 
6359,	22941,	/* 8 */ 
11852,	7111,	/* 9 */ 
-6304,	-12834,	/* 10 */ 
-24894,	-7482,	/* 11 */ 
-4071,	-15854,	/* 12 */ 
12884,	-476,	/* 13 */ 
14926,	-4609,	/* 14 */ 
21330,	-1853,	/* 15 */ 
17508,	5634,	/* 16 */ 
-6717,	-21781,	/* 17 */ 
6135,	-9433,	/* 18 */ 
11746,	5504,	/* 19 */ 
-15548,	-16507,	/* 20 */ 
20560,	6147,	/* 21 */ 
3515,	-12903,	/* 22 */ 
6693,	4437,	/* 23 */ 
-13490,	307,	/* 24 */ 
2477,	-1789,	/* 25 */ 
21920,	2103,	/* 26 */ 
-8371,	22466,	/* 27 */ 
7899,	-8038,	/* 28 */ 
-5491,	-4988,	/* 29 */ 
6466,	-9768,	/* 30 */ 
10111,	-4492,	/* 31 */ 
-5223,	-10873,	/* 32 */ 
-4387,	-5378,	/* 33 */ 
7883,	153,	/* 34 */ 
17146,	11274,	/* 35 */ 
-6522,	-9843,	/* 36 */ 
-3797,	-19699,	/* 37 */ 
4808,	-2881,	/* 38 */ 
3338,	-1689,	/* 39 */ 
10998,	-24651,	/* 40 */ 
574,	8332,	/* 41 */ 
14038,	11380,	/* 42 */ 
-542,	-11092,	/* 43 */ 
-15954,	-12098,	/* 44 */ 
10190,	10588,	/* 45 */ 
24517,	14417,	/* 46 */ 
15574,	24692,	/* 47 */ 
10339,	-1354,	/* 48 */ 
-764,	20459,	/* 49 */ 
-19575,	-2486,	/* 50 */ 
8373,	15466,	/* 51 */ 
-6838,	16703,	/* 52 */ 
-18283,	-16951,	/* 53 */ 
3391,	-5389,	/* 54 */ 
16405,	1054,	/* 55 */ 
8835,	11078,	/* 56 */ 
25367,	3514,	/* 57 */ 
23447,	-1991,	/* 58 */ 
-22406,	-2778,	/* 59 */ 
-7095,	-20939,	/* 60 */ 
2464,	-2871,	/* 61 */ 
-12100,	-6791,	/* 62 */ 
4944,	-10030,	/* 63 */ 
-22893,	17870,	/* 64 */ 
3609,	13179,	/* 65 */ 
10201,	22843,	/* 66 */ 
23480,	2942,	/* 67 */ 
12724,	-24673,	/* 68 */ 
12189,	4884,	/* 69 */ 
-3461,	16060,	/* 70 */ 
6819,	24232,	/* 71 */ 
15391,	-14125,	/* 72 */ 
-21136,	10345,	/* 73 */ 
22625,	1120,	/* 74 */ 
21126,	21987,	/* 75 */ 
5180,	10836,	/* 76 */ 
-12517,	-13814,	/* 77 */ 
18967,	-2558,	/* 78 */ 
680,	-16650,	/* 79 */ 
11816,	23811,	/* 80 */ 
-3951,	-7329,	/* 81 */ 
23433,	-22905,	/* 82 */ 
-21736,	12968,	/* 83 */ 
2712,	20052,	/* 84 */ 
-10566,	-10862,	/* 85 */ 
18181,	-12637,	/* 86 */ 
-8343,	21979,	/* 87 */ 
9152,	-18743,	/* 88 */ 
-22682,	22389,	/* 89 */ 
-7281,	10252,	/* 90 */ 
-87,	17658,	/* 91 */ 
-3330,	-14767,	/* 92 */ 
3172,	-2281,	/* 93 */ 
5923,	-21278,	/* 94 */ 
-19639,	17833,	/* 95 */ 
20227,	3151,	/* 96 */ 
12928,	-9179,	/* 97 */ 
14786,	-6355,	/* 98 */ 
15996,	18680,	/* 99 */ 
8634,	-6493,	/* 100 */ 
-15193,	-21653,	/* 101 */ 
-11526,	-15246,	/* 102 */ 
6411,	-22882,	/* 103 */ 
1871,	3388,	/* 104 */ 
-22374,	-19203,	/* 105 */ 
-20878,	1123,	/* 106 */ 
-11616,	-19450,	/* 107 */ 
-4619,	13709,	/* 108 */ 
-1319,	-6347,	/* 109 */ 
20773,	16425,	/* 110 */ 
4888,	-23027,	/* 111 */ 
-8688,	4973,	/* 112 */ 
-1108,	22812,	/* 113 */ 
4935,	-10728,	/* 114 */ 
-17196,	19749,	/* 115 */ 
16734,	-20236,	/* 116 */ 
23166,	-22079,	/* 117 */ 
4852,	-13496,	/* 118 */ 
-23936,	21997,	/* 119 */ 
15852,	-22190,	/* 120 */ 
5592,	-11976,	/* 121 */ 
10234,	25371,	/* 122 */ 
-20713,	-14629,	/* 123 */ 
-3815,	-81,	/* 124 */ 
-6320,	-10642,	/* 125 */ 
-16957,	8774,	/* 126 */ 
16921,	23261,	/* 127 */ 
};

#pragma DATA_SECTION (rtest,".test")

DATA rtest[2*NX] ={
2078,	-23,	 /* 0 */ 
-814,	-1672,	 /* 1 */ 
440,	952,	 /* 2 */ 
1,	1787,	 /* 3 */ 
-552,	-238,	 /* 4 */ 
-438,	2057,	 /* 5 */ 
1630,	478,	 /* 6 */ 
-44,	-752,	 /* 7 */ 
699,	-183,	 /* 8 */ 
991,	75,	 /* 9 */ 
-2147,	-788,	 /* 10 */ 
-2,	-733,	 /* 11 */ 
-182,	-2506,	 /* 12 */ 
-696,	625,	 /* 13 */ 
-363,	22,	 /* 14 */ 
-1237,	692,	 /* 15 */ 
1933,	1727,	 /* 16 */ 
-722,	616,	 /* 17 */ 
-1298,	1572,	 /* 18 */ 
765,	-473,	 /* 19 */ 
-421,	-114,	 /* 20 */ 
-274,	-1804,	 /* 21 */ 
82,	2285,	 /* 22 */ 
-1146,	99,	 /* 23 */ 
-1656,	1510,	 /* 24 */ 
500,	898,	 /* 25 */ 
995,	1076,	 /* 26 */ 
-1904,	3380,	 /* 27 */ 
-739,	868,	 /* 28 */ 
-959,	1131,	 /* 29 */ 
-131,	-1231,	 /* 30 */ 
1144,	-1043,	 /* 31 */ 
-2523,	215,	 /* 32 */ 
154,	-408,	 /* 33 */ 
2171,	-160,	 /* 34 */ 
584,	-928,	 /* 35 */ 
1022,	-2018,	 /* 36 */ 
1266,	1884,	 /* 37 */ 
-35,	-716,	 /* 38 */ 
-484,	1459,	 /* 39 */ 
849,	1740,	 /* 40 */ 
-336,	-384,	 /* 41 */ 
58,	901,	 /* 42 */ 
-643,	-476,	 /* 43 */ 
-1683,	1408,	 /* 44 */ 
82,	-2477,	 /* 45 */ 
-2443,	812,	 /* 46 */ 
-1590,	-81,	 /* 47 */ 
470,	1042,	 /* 48 */ 
-428,	1061,	 /* 49 */ 
49,	554,	 /* 50 */ 
-354,	-1509,	 /* 51 */ 
-1891,	-17,	 /* 52 */ 
-420,	482,	 /* 53 */ 
-2235,	566,	 /* 54 */ 
2037,	-873,	 /* 55 */ 
-231,	453,	 /* 56 */ 
-200,	911,	 /* 57 */ 
860,	1306,	 /* 58 */ 
-1675,	2531,	 /* 59 */ 
-2041,	-316,	 /* 60 */ 
1513,	-1053,	 /* 61 */ 
308,	1996,	 /* 62 */ 
596,	-691,	 /* 63 */ 
2156,	-1149,	 /* 64 */ 
-252,	2768,	 /* 65 */ 
-1092,	457,	 /* 66 */ 
1534,	463,	 /* 67 */ 
734,	300,	 /* 68 */ 
1834,	956,	 /* 69 */ 
-2521,	1675,	 /* 70 */ 
-1047,	-70,	 /* 71 */ 
-1394,	1359,	 /* 72 */ 
91,	-1107,	 /* 73 */ 
721,	-993,	 /* 74 */ 
-694,	-2712,	 /* 75 */ 
385,	-158,	 /* 76 */ 
53,	-754,	 /* 77 */ 
-487,	-243,	 /* 78 */ 
718,	-188,	 /* 79 */ 
295,	-952,	 /* 80 */ 
687,	-434,	 /* 81 */ 
252,	-1544,	 /* 82 */ 
1991,	-1922,	 /* 83 */ 
1387,	-592,	 /* 84 */ 
-91,	2340,	 /* 85 */ 
623,	-866,	 /* 86 */ 
1359,	-222,	 /* 87 */ 
-873,	1573,	 /* 88 */ 
-1845,	-3169,	 /* 89 */ 
-1244,	-1582,	 /* 90 */ 
-1141,	-1541,	 /* 91 */ 
2028,	-1548,	 /* 92 */ 
-688,	144,	 /* 93 */ 
-873,	341,	 /* 94 */ 
1266,	28,	 /* 95 */ 
737,	-639,	 /* 96 */ 
-153,	2131,	 /* 97 */ 
336,	106,	 /* 98 */ 
1794,	-286,	 /* 99 */ 
-581,	-701,	 /* 100 */ 
2460,	701,	 /* 101 */ 
-2526,	-550,	 /* 102 */ 
1849,	-978,	 /* 103 */ 
-692,	-1662,	 /* 104 */ 
-1303,	-1408,	 /* 105 */ 
619,	-1937,	 /* 106 */ 
1044,	-293,	 /* 107 */ 
-1416,	2261,	 /* 108 */ 
286,	1294,	 /* 109 */ 
331,	1226,	 /* 110 */ 
89,	349,	 /* 111 */ 
-914,	927,	 /* 112 */ 
50,	-1624,	 /* 113 */ 
421,	1547,	 /* 114 */ 
916,	-1361,	 /* 115 */ 
-1706,	2125,	 /* 116 */ 
-266,	-224,	 /* 117 */ 
-317,	766,	 /* 118 */ 
1669,	87,	 /* 119 */ 
659,	1607,	 /* 120 */ 
50,	1602,	 /* 121 */ 
-3944,	416,	 /* 122 */ 
119,	-336,	 /* 123 */ 
-496,	521,	 /* 124 */ 
-502,	1020,	 /* 125 */ 
-302,	2240,	 /* 126 */ 
-873,	49,	 /* 127 */ 
};

DATA error;

