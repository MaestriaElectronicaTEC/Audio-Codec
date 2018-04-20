/* Test for interp: nois */
#define NX 200
#define NH 17
#define I 4
#define FNAME "t2"
#define MAXERROR 100

DATA x[NX] ={
7374,
-4406,
1750,
-230,
6411,
4294,
-714,
-7889,
5265,
-906,
1891,
4783,
6910,
3902,
-5305,
-1545,
7134,
6830,
-1471,
6449,
-7244,
-2411,
5130,
-8031,
-5917,
-4870,
-4937,
1700,
-3733,
-4935,
-7942,
4043,
-900,
7074,
-558,
-1333,
5672,
412,
-4872,
2820,
5539,
-7871,
2970,
-1975,
5436,
46,
3431,
-1166,
-3202,
-5085,
-5023,
2985,
-3232,
682,
-5721,
3242,
-1993,
5898,
5794,
1532,
-57,
6549,
5269,
2374,
5209,
2625,
-2590,
-3446,
-2602,
558,
3721,
-3125,
5545,
1115,
-2124,
3321,
763,
-904,
3187,
1987,
4830,
7484,
370,
6228,
-5359,
7860,
-3745,
-4058,
6156,
3888,
-5956,
-8000,
6453,
-4930,
-3298,
2645,
-3533,
-505,
-7131,
8000,
1356,
-1254,
254,
-2721,
-1100,
-4491,
1307,
4265,
488,
2302,
-4767,
-1970,
4642,
2962,
-638,
1111,
4820,
-7223,
1685,
-7369,
-1387,
-3195,
6133,
-7947,
4390,
7714,
8029,
4732,
-1006,
-28,
-4687,
2350,
-2949,
7538,
3713,
-1443,
4006,
-3802,
-985,
7100,
3003,
-4710,
5558,
2110,
-6001,
-4799,
1756,
2128,
-2123,
1231,
-796,
-7473,
-7747,
-3069,
-7982,
-1902,
3000,
-6671,
-7614,
1841,
1778,
-7934,
-7925,
-5078,
1424,
-7249,
-2170,
2153,
3565,
3156,
-6815,
-748,
-954,
-2405,
-5676,
2877,
3263,
3727,
-355,
898,
-6209,
-807,
3537,
6436,
-3718,
-4018,
5990,
-4386,
4995,
6691,
-4393,
-4272,
-7377,
-6908,
2307,
-5065,
5633,
-5343,
-5394,
8098,
};

DATA rtest[] ={
0,
-430,
-684,
-586,
0,
2349,
4732,
6577,
7375,
4876,
1579,
-1766,
-4405,
-3795,
-2219,
-183,
1751,
1389,
705,
50,
-230,
1236,
3063,
4905,
6411,
6692,
6363,
5515,
4294,
3374,
2236,
869,
-713,
-3488,
-5929,
-7532,
-7889,
-5058,
-1387,
2322,
5266,
4706,
3112,
1039,
-906,
-925,
-355,
653,
1891,
2623,
3355,
4080,
4783,
5622,
6317,
6773,
6911,
6872,
6387,
5399,
3903,
1332,
-1319,
-3651,
-5304,
-5643,
-5039,
-3603,
-1545,
743,
3135,
5353,
7135,
8171,
8466,
7999,
6831,
4408,
1882,
-231,
-1470,
468,
2957,
5206,
6450,
3648,
-105,
-4009,
-7244,
-7612,
-6733,
-4874,
-2411,
463,
3011,
4708,
5131,
2590,
-927,
-4715,
-8030,
-8583,
-8200,
-7187,
-5916,
-5452,
-5120,
-4931,
-4870,
-5142,
-5357,
-5340,
-4936,
-3081,
-1099,
616,
1701,
1056,
-276,
-1990,
-3732,
-4224,
-4502,
-4694,
-4935,
-6359,
-7577,
-8210,
-7942,
-5115,
-1744,
1520,
4043,
3377,
1923,
289,
-900,
959,
3297,
5528,
7075,
5965,
4028,
1695,
-557,
-1741,
-2290,
-2146,
-1333,
504,
2557,
4412,
5672,
5297,
4142,
2422,
412,
-1649,
-3402,
-4551,
-4872,
-3669,
-1755,
535,
2820,
4799,
6082,
6387,
5540,
2048,
-1903,
-5474,
-7870,
-6128,
-3203,
109,
2970,
2256,
809,
-798,
-1975,
-363,
1749,
3853,
5436,
4560,
3078,
1424,
46,
649,
1643,
2687,
3432,
2750,
1622,
242,
-1165,
-1868,
-2406,
-2830,
-3201,
-3761,
-4283,
-4735,
-5085,
-5639,
-5905,
-5735,
-5023,
-2802,
-423,
1649,
2986,
1963,
258,
-1643,
-3232,
-2439,
-1240,
-60,
683,
-979,
-2954,
-4706,
-5720,
-3848,
-1331,
1233,
3242,
2283,
716,
-898,
-1993,
-604,
1451,
3766,
5898,
6694,
6897,
6561,
5794,
4863,
3753,
2599,
1533,
437,
-280,
-470,
-56,
1382,
3175,
5007,
6550,
6892,
6713,
6123,
5270,
4300,
3390,
2705,
2374,
2912,
3713,
4557,
5210,
5106,
4613,
3762,
2625,
1269,
-143,
-1471,
-2589,
-3221,
-3539,
-3590,
-3445,
-3474,
-3356,
-3068,
-2602,
-1982,
-1223,
-362,
558,
1916,
3040,
3700,
3721,
1888,
-217,
-2056,
-3125,
-1425,
971,
3491,
5546,
5371,
4391,
2866,
1115,
-295,
-1413,
-2063,
-2123,
-983,
528,
2077,
3322,
3243,
2675,
1782,
763,
-61,
-686,
-993,
-903,
-34,
1084,
2233,
3188,
3046,
2669,
2252,
1988,
2360,
3007,
3863,
4830,
6023,
7000,
7546,
7485,
5679,
3579,
1660,
370,
1798,
3671,
5354,
6228,
3251,
-253,
-3403,
-5358,
-2571,
1236,
5051,
7860,
6237,
3286,
-297,
-3745,
-5296,
-5874,
-5436,
-4058,
-1609,
1217,
3956,
6156,
6971,
6817,
5739,
3888,
1571,
-1041,
-3649,
-5955,
-7983,
-9139,
-9184,
-7999,
-4164,
104,
3918,
6454,
4878,
1941,
-1603,
-4929,
-5765,
-5667,
-4769,
-3298,
-1437,
402,
1866,
2645,
1523,
-167,
-2000,
-3532,
-2920,
-1950,
-1016,
-504,
-2635,
-4890,
-6594,
-7131,
-3790,
431,
4655,
8001,
7780,
6263,
3931,
1356,
140,
-705,
-1160,
-1253,
-935,
-459,
-4,
254,
-394,
-1228,
-2065,
-2721,
-2368,
-1846,
-1358,
-1099,
-2062,
-3145,
-4049,
-4490,
-3582,
-2159,
-445,
1308,
2643,
3638,
4196,
4266,
3503,
2452,
1364,
489,
1005,
1683,
2213,
2302,
668,
-1307,
-3244,
-4767,
-5037,
-4593,
-3518,
-1969,
-140,
1734,
3404,
4642,
4954,
4700,
3984,
2963,
1888,
830,
-56,
-637,
-739,
-444,
202,
1111,
2778,
4206,
4996,
4820,
1835,
-1667,
-4930,
-7222,
-5574,
-3009,
-322,
1685,
-13,
-2533,
-5213,
-7368,
-6563,
-4992,
-3106,
-1386,
-1850,
-2571,
-3149,
-3195,
-384,
2588,
4985,
6134,
2923,
-1173,
-5132,
-7946,
-6401,
-3369,
482,
4390,
6059,
7088,
7585,
7714,
8168,
8383,
8337,
8030,
7569,
6859,
5905,
4733,
3075,
1443,
29,
-1005,
-959,
-610,
-212,
-28,
-1410,
-2888,
-4093,
-4686,
-3116,
-1093,
891,
2351,
1081,
-615,
-2148,
-2949,
-754,
2128,
5097,
7538,
7737,
7003,
5561,
3713,
1894,
260,
-922,
-1443,
-155,
1511,
3060,
4007,
2477,
345,
-1911,
-3802,
-4222,
-3836,
-2707,
-984,
1310,
3659,
5700,
7100,
7201,
6451,
4982,
3004,
312,
-2174,
-3980,
-4709,
-2761,
23,
3015,
5558,
6016,
5488,
4110,
2110,
-83,
-2351,
-4411,
-6000,
-6698,
-6689,
-6017,
-4798,
-3201,
-1424,
302,
1756,
2592,
2919,
2743,
2128,
984,
-274,
-1388,
-2122,
-1565,
-646,
377,
1231,
1418,
1145,
394,
-796,
-2439,
-4243,
-5993,
-7473,
-8266,
-8563,
-8372,
-7747,
-6354,
-4906,
-3720,
-3069,
-4130,
-5583,
-7008,
-7981,
-7210,
-5787,
-3929,
-1901,
268,
2003,
2989,
3000,
1235,
-1269,
-4066,
-6671,
-8139,
-8822,
-8642,
-7613,
-5480,
-2929,
-358,
1841,
3126,
3564,
3098,
1778,
-434,
-3044,
-5673,
-7934,
-8793,
-8990,
-8643,
-7924,
-7585,
-7018,
-6187,
-5078,
-2832,
-734,
799,
1424,
-325,
-2742,
-5249,
-7249,
-6975,
-5853,
-4143,
-2170,
-853,
332,
1342,
2154,
2819,
3261,
3498,
3566,
4133,
4373,
4093,
3157,
492,
-2406,
-5007,
-6814,
-6162,
-4637,
-2673,
-748,
-221,
-142,
-429,
-953,
-1097,
-1372,
-1806,
-2404,
-3733,
-4915,
-5648,
-5675,
-3975,
-1720,
701,
2878,
3590,
3781,
3607,
3264,
3606,
3864,
3934,
3728,
2736,
1591,
497,
-354,
22,
549,
934,
899,
-928,
-3005,
-4903,
-6209,
-5749,
-4524,
-2776,
-807,
440,
1579,
2608,
3537,
5094,
6266,
6781,
6436,
4333,
1638,
-1200,
-3717,
-5139,
-5687,
-5298,
-4018,
-1142,
1908,
4483,
5990,
3842,
850,
-2166,
-4385,
-3151,
-819,
2093,
4995,
6721,
7665,
7672,
6691,
4256,
1280,
-1763,
-4393,
-5023,
-5015,
-4657,
-4271,
-4948,
-5780,
-6636,
-7377,
-7984,
-8191,
-7860,
-6908,
-4298,
-1543,
820,
2307,
731,
-1498,
-3667,
-5065,
-2550,
615,
3610,
5634,
3958,
1141,
-2190,
-5343,
-6961,
-7567,
-7042,
};

#pragma DATA_SECTION (h,".coeffs")
DATA h[NH] ={
0,
-1909,
-3039,
-2602,
0,
9297,
19206,
27667,
32765,
27667,
19206,
9297,
0,
-2602,
-3039,
-1909,
0,
};

#pragma DATA_SECTION (db,".dbuffer")
DATA db[(NH/I)+1];
DATA r[NX*I];

