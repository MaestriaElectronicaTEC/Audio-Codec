/* Test for cfft: rand */
#define NX 128
#define FNAME "t5"
#define MAXERROR 70

#pragma DATA_SECTION (x,".input")

DATA x[2*NX] ={
481,	-351,	/* 0 */ 
383,	-45,	/* 1 */ 
-316,	198,	/* 2 */ 
-684,	-694,	/* 3 */ 
-706,	674,	/* 4 */ 
-633,	934,	/* 5 */ 
-159,	195,	/* 6 */ 
728,	-966,	/* 7 */ 
-20,	639,	/* 8 */ 
646,	225,	/* 9 */ 
-81,	412,	/* 10 */ 
-88,	-836,	/* 11 */ 
-101,	-154,	/* 12 */ 
-180,	-255,	/* 13 */ 
822,	-684,	/* 14 */ 
-1013,	682,	/* 15 */ 
-415,	693,	/* 16 */ 
-924,	-100,	/* 17 */ 
395,	935,	/* 18 */ 
307,	-723,	/* 19 */ 
989,	757,	/* 20 */ 
107,	551,	/* 21 */ 
-205,	-115,	/* 22 */ 
-617,	247,	/* 23 */ 
256,	924,	/* 24 */ 
477,	286,	/* 25 */ 
-255,	-518,	/* 26 */ 
-1004,	-302,	/* 27 */ 
-165,	-640,	/* 28 */ 
519,	-20,	/* 29 */ 
601,	-186,	/* 30 */ 
859,	-75,	/* 31 */ 
705,	227,	/* 32 */ 
-271,	-879,	/* 33 */ 
247,	-381,	/* 34 */ 
473,	221,	/* 35 */ 
-627,	-666,	/* 36 */ 
828,	247,	/* 37 */ 
141,	-521,	/* 38 */ 
269,	178,	/* 39 */ 
-544,	12,	/* 40 */ 
99,	-73,	/* 41 */ 
883,	84,	/* 42 */ 
-338,	905,	/* 43 */ 
318,	-325,	/* 44 */ 
-222,	-202,	/* 45 */ 
260,	-394,	/* 46 */ 
407,	-182,	/* 47 */ 
-211,	-439,	/* 48 */ 
-177,	-217,	/* 49 */ 
317,	6,	/* 50 */ 
691,	454,	/* 51 */ 
-263,	-397,	/* 52 */ 
-154,	-795,	/* 53 */ 
193,	-117,	/* 54 */ 
134,	-69,	/* 55 */ 
443,	-994,	/* 56 */ 
23,	335,	/* 57 */ 
566,	458,	/* 58 */ 
-22,	-448,	/* 59 */ 
-644,	-488,	/* 60 */ 
410,	426,	/* 61 */ 
988,	581,	/* 62 */ 
627,	995,	/* 63 */ 
416,	-55,	/* 64 */ 
-31,	824,	/* 65 */ 
-790,	-101,	/* 66 */ 
337,	623,	/* 67 */ 
-276,	673,	/* 68 */ 
-738,	-684,	/* 69 */ 
136,	-218,	/* 70 */ 
661,	42,	/* 71 */ 
356,	446,	/* 72 */ 
1022,	141,	/* 73 */ 
945,	-81,	/* 74 */ 
-904,	-112,	/* 75 */ 
-287,	-845,	/* 76 */ 
99,	-116,	/* 77 */ 
-488,	-274,	/* 78 */ 
199,	-405,	/* 79 */ 
-923,	720,	/* 80 */ 
145,	531,	/* 81 */ 
411,	921,	/* 82 */ 
946,	118,	/* 83 */ 
513,	-995,	/* 84 */ 
491,	196,	/* 85 */ 
-140,	647,	/* 86 */ 
274,	976,	/* 87 */ 
620,	-570,	/* 88 */ 
-853,	417,	/* 89 */ 
912,	45,	/* 90 */ 
851,	886,	/* 91 */ 
208,	436,	/* 92 */ 
-505,	-557,	/* 93 */ 
764,	-104,	/* 94 */ 
27,	-672,	/* 95 */ 
476,	960,	/* 96 */ 
-160,	-296,	/* 97 */ 
944,	-924,	/* 98 */ 
-877,	522,	/* 99 */ 
109,	808,	/* 100 */ 
-426,	-438,	/* 101 */ 
733,	-510,	/* 102 */ 
-337,	886,	/* 103 */ 
369,	-756,	/* 104 */ 
-915,	902,	/* 105 */ 
-294,	413,	/* 106 */ 
-4,	711,	/* 107 */ 
-135,	-596,	/* 108 */ 
127,	-92,	/* 109 */ 
238,	-858,	/* 110 */ 
-792,	719,	/* 111 */ 
815,	127,	/* 112 */ 
521,	-371,	/* 113 */ 
596,	-257,	/* 114 */ 
644,	753,	/* 115 */ 
348,	-262,	/* 116 */ 
-613,	-873,	/* 117 */ 
-465,	-615,	/* 118 */ 
258,	-923,	/* 119 */ 
75,	136,	/* 120 */ 
-903,	-775,	/* 121 */ 
-842,	45,	/* 122 */ 
-469,	-785,	/* 123 */ 
-187,	552,	/* 124 */ 
-54,	-256,	/* 125 */ 
837,	662,	/* 126 */ 
197,	-929,	/* 127 */ 
};

#pragma DATA_SECTION (rtest,".test")

DATA rtest[2*NX] ={
9831,	-169,	 /* 0 */ 
-10151,	-2722,	 /* 1 */ 
4014,	-1154,	 /* 2 */ 
6246,	-4766,	 /* 3 */ 
3508,	3271,	 /* 4 */ 
-4285,	-7229,	 /* 5 */ 
-95,	9761,	 /* 6 */ 
5371,	-2234,	 /* 7 */ 
6523,	-923,	 /* 8 */ 
6768,	-3833,	 /* 9 */ 
-1271,	10179,	 /* 10 */ 
29,	1422,	 /* 11 */ 
3500,	11316,	 /* 12 */ 
2598,	-6763,	 /* 13 */ 
1931,	-4041,	 /* 14 */ 
-5278,	-4240,	 /* 15 */ 
11586,	6666,	 /* 16 */ 
1251,	2580,	 /* 17 */ 
9864,	4099,	 /* 18 */ 
-2783,	-4280,	 /* 19 */ 
3470,	-3467,	 /* 20 */ 
7862,	768,	 /* 21 */ 
-13074,	-4681,	 /* 22 */ 
-7614,	-8417,	 /* 23 */ 
-13167,	4584,	 /* 24 */ 
-363,	303,	 /* 25 */ 
204,	-3998,	 /* 26 */ 
14982,	-2226,	 /* 27 */ 
1203,	70,	 /* 28 */ 
-1308,	-2439,	 /* 29 */ 
7531,	4502,	 /* 30 */ 
10802,	5098,	 /* 31 */ 
-8732,	5107,	 /* 32 */ 
4732,	916,	 /* 33 */ 
6070,	-9717,	 /* 34 */ 
2238,	694,	 /* 35 */ 
2591,	7317,	 /* 36 */ 
-4624,	-7985,	 /* 37 */ 
8405,	-8026,	 /* 38 */ 
-5357,	-5254,	 /* 39 */ 
3032,	684,	 /* 40 */ 
-6323,	-6601,	 /* 41 */ 
-44,	-4145,	 /* 42 */ 
-3609,	2624,	 /* 43 */ 
5962,	-7308,	 /* 44 */ 
7692,	9400,	 /* 45 */ 
-4230,	-13485,	 /* 46 */ 
-5659,	-8228,	 /* 47 */ 
1156,	2528,	 /* 48 */ 
-409,	2947,	 /* 49 */ 
-799,	-1348,	 /* 50 */ 
-7681,	7511,	 /* 51 */ 
7662,	2136,	 /* 52 */ 
-354,	-1094,	 /* 53 */ 
-1407,	-10554,	 /* 54 */ 
12596,	3135,	 /* 55 */ 
-275,	-811,	 /* 56 */ 
1272,	-106,	 /* 57 */ 
2872,	-8061,	 /* 58 */ 
9630,	-4813,	 /* 59 */ 
4324,	2527,	 /* 60 */ 
-7001,	12551,	 /* 61 */ 
-13932,	6058,	 /* 62 */ 
2688,	4279,	 /* 63 */ 
10001,	-1779,	 /* 64 */ 
8098,	14855,	 /* 65 */ 
979,	9952,	 /* 66 */ 
-5083,	-1615,	 /* 67 */ 
-3555,	5738,	 /* 68 */ 
-7229,	11368,	 /* 69 */ 
-2324,	-5611,	 /* 70 */ 
5581,	605,	 /* 71 */ 
3030,	7596,	 /* 72 */ 
5198,	-8008,	 /* 73 */ 
352,	-10220,	 /* 74 */ 
-6277,	5449,	 /* 75 */ 
-4691,	-4136,	 /* 76 */ 
-2003,	1683,	 /* 77 */ 
-2706,	110,	 /* 78 */ 
1948,	7204,	 /* 79 */ 
3553,	940,	 /* 80 */ 
5754,	401,	 /* 81 */ 
-1857,	804,	 /* 82 */ 
-8505,	-347,	 /* 83 */ 
-2651,	1857,	 /* 84 */ 
-4818,	-9892,	 /* 85 */ 
7739,	3038,	 /* 86 */ 
10103,	4471,	 /* 87 */ 
1484,	7716,	 /* 88 */ 
-11141,	-7423,	 /* 89 */ 
-1348,	753,	 /* 90 */ 
3109,	1305,	 /* 91 */ 
-9628,	-1854,	 /* 92 */ 
-1279,	-12093,	 /* 93 */ 
-8178,	-10786,	 /* 94 */ 
-3163,	2289,	 /* 95 */ 
-3078,	-2095,	 /* 96 */ 
2564,	11903,	 /* 97 */ 
-1549,	2526,	 /* 98 */ 
-7826,	-1867,	 /* 99 */ 
3426,	6197,	 /* 100 */ 
-11429,	8436,	 /* 101 */ 
2385,	-10589,	 /* 102 */ 
9909,	6880,	 /* 103 */ 
-2826,	-3488,	 /* 104 */ 
-7013,	5384,	 /* 105 */ 
-4672,	1977,	 /* 106 */ 
2332,	598,	 /* 107 */ 
15191,	-10798,	 /* 108 */ 
1494,	-5045,	 /* 109 */ 
-518,	-953,	 /* 110 */ 
3412,	-1210,	 /* 111 */ 
-1084,	2605,	 /* 112 */ 
-1833,	-7646,	 /* 113 */ 
12873,	-3791,	 /* 114 */ 
-2457,	-1146,	 /* 115 */ 
14804,	-15739,	 /* 116 */ 
6673,	-7082,	 /* 117 */ 
-1368,	-10025,	 /* 118 */ 
5484,	-2143,	 /* 119 */ 
516,	991,	 /* 120 */ 
1545,	590,	 /* 121 */ 
-2645,	17747,	 /* 122 */ 
-5660,	159,	 /* 123 */ 
-115,	-2259,	 /* 124 */ 
-3347,	-4946,	 /* 125 */ 
-12320,	-1284,	 /* 126 */ 
-4019,	-3073,	 /* 127 */ 
};

DATA error;

