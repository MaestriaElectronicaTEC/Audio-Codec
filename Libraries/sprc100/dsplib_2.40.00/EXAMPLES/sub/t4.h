/* This is a test for sub: rand */
#define NX 32
#define FNAME "t4"
#define MAXERROR 2

#define SUB_SCALE 1

DATA x[NX] ={
-1800,
14149,
-1115,
-2666,
11344,
824,
-9744,
5640,
11079,
-15741,
5940,
-3950,
10872,
92,
6863,
-2331,
-6403,
-10170,
-10046,
5971,
-6464,
1365,
-11441,
6484,
-3986,
11796,
11588,
3065,
-113,
13099,
10539,
4748,
};

DATA y[NX] ={
10419,
5250,
-5178,
-6890,
-5204,
1117,
7442,
-6249,
11092,
2231,
-4246,
6643,
1526,
-1806,
6376,
3975,
9661,
14970,
740,
12456,
-10717,
15720,
-7489,
-8116,
12312,
7776,
-11911,
-15999,
12907,
-9859,
-6595,
5290,
};

DATA rtest[NX] ={
-6109,
4450,
2032,
2112,
8274,
-146,
-8593,
5945,
-6,
-8986,
5093,
-5296,
4673,
949,
244,
-3153,
-8031,
-12570,
-5393,
-3243,
2127,
-7177,
-1975,
7300,
-8149,
2010,
11750,
9532,
-6510,
11479,
8567,
-271,
};

DATA r[NX]; 
