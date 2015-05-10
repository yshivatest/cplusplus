/*
 * test_temp.cc
 *
 *  Created on: Aug 4, 2014
 *      Author: syerramreddy
 */
#include<iostream>
#include <string.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
typedef unsigned int u_int;
typedef unsigned char u_char;
# define UNLIKELY(x) __builtin_expect(!!(x),0)
#define COMPILE_TIME_ASSERT(var)
static const int FP_POINT = 257;
const u_int fp_scan_thresh_orig[] = {
    0,
    0xfe0001bf, 0xfe0001be, 0xfe0001bd, 0xfe0001bc,
    0xfe0001bb, 0xfe0001ba, 0xfe0001b9, 0xfe0001b8,
    0xfe0001b7, 0xfe0001b6, 0xfe0001b5, 0xfe0001b4,
    0xfe0001b3, 0xfe0001b2, 0xfe0001b1, 0xfe0001b0,
    0xfe0001af, 0xfe0001ae, 0xfe0001ad, 0xfe0001ac,
    0xfe0001ab, 0xfe0001aa, 0xfe0001a9, 0xfe0001a8,
    0xfe0001a7, 0xfe0001a6, 0xfe0001a5, 0xfe0001a4,
    0xfe0001a3, 0xfe0001a2, 0xfe0001a1, 0xfe0001a0,
    0xfe00019f, 0xfe00019e, 0xfe00019d, 0xfe00019c,
    0xfe00019b, 0xfe00019a, 0xfe000199, 0xfe000198,
    0xfe000197, 0xfe000196, 0xfe000195, 0xfe000194,
    0xfe000193, 0xfe000192, 0xfe000191, 0xfe000190,
    0xfe00018f, 0xfe00018e, 0xfe00018d, 0xfe00018c,
    0xfe00018b, 0xfe00018a, 0xfe000189, 0xfe000188,
    0xfe000187, 0xfe000186, 0xfe000185, 0xfe000184,
    0xfe000183, 0xfe000182, 0xfe000181, 0xfe000180,
    0xfe00017f, 0xfe00017e, 0xfe00017d, 0xfe00017c,
    0xfe00017b, 0xfe00017a, 0xfe000179, 0xfe000178,
    0xfe000177, 0xfe000176, 0xfe000175, 0xfe000174,
    0xfe000173, 0xfe000172, 0xfe000171, 0xfe000170,
    0xfe00016f, 0xfe00016e, 0xfe00016d, 0xfe00016c,
    0xfe00016b, 0xfe00016a, 0xfe000169, 0xfe000168,
    0xfe000167, 0xfe000166, 0xfe000165, 0xfe000164,
    0xfe000163, 0xfe000162, 0xfe000161, 0xfe000160,
    0xfe00015f, 0xfe00015e, 0xfe00015d, 0xfe00015c,
    0xfe00015b, 0xfe00015a, 0xfe000159, 0xfe000158,
    0xfe000157, 0xfe000156, 0xfe000155, 0xfe000154,
    0xfe000153, 0xfe000152, 0xfe000151, 0xfe000150,
    0xfe00014f, 0xfe00014e, 0xfe00014d, 0xfe00014c,
    0xfe00014b, 0xfe00014a, 0xfe000149, 0xfe000148,
    0xfe000147, 0xfe000146, 0xfe000145, 0xfe000144,
    0xfe000143, 0xfe000142, 0xfe000141, 0xfe000140,
    0xfe00013f, 0xfe00013e, 0xfe00013d, 0xfe00013c,
    0xfe00013b, 0xfe00013a, 0xfe000139, 0xfe000138,
    0xfe000137, 0xfe000136, 0xfe000135, 0xfe000134,
    0xfe000133, 0xfe000132, 0xfe000131, 0xfe000130,
    0xfe00012f, 0xfe00012e, 0xfe00012d, 0xfe00012c,
    0xfe00012b, 0xfe00012a, 0xfe000129, 0xfe000128,
    0xfe000127, 0xfe000126, 0xfe000125, 0xfe000124,
    0xfe000123, 0xfe000122, 0xfe000121, 0xfe000120,
    0xfe00011f, 0xfe00011e, 0xfe00011d, 0xfe00011c,
    0xfe00011b, 0xfe00011a, 0xfe000119, 0xfe000118,
    0xfe000117, 0xfe000116, 0xfe000115, 0xfe000114,
    0xfe000113, 0xfe000112, 0xfe000111, 0xfe000110,
    0xfe00010f, 0xfe00010e, 0xfe00010d, 0xfe00010c,
    0xfe00010b, 0xfe00010a, 0xfe000109, 0xfe000108,
    0xfe000107, 0xfe000106, 0xfe000105, 0xfe000104,
    0xfe000103, 0xfe000102, 0xfe000101, 0xfe000100,
    0xfe0000ff, 0xfe0000fe, 0xfe0000fd, 0xfe0000fc,
    0xfe0000fb, 0xfe0000fa, 0xfe0000f9, 0xfe0000f8,
    0xfe0000f7, 0xfe0000f6, 0xfe0000f5, 0xfe0000f4,
    0xfe0000f3, 0xfe0000f2, 0xfe0000f1, 0xfe0000f0,
    0xfe0000ef, 0xfe0000ee, 0xfe0000ed, 0xfe0000ec,
    0xfe0000eb, 0xfe0000ea, 0xfe0000e9, 0xfe0000e8,
    0xfe0000e7, 0xfe0000e6, 0xfe0000e5, 0xfe0000e4,
    0xfe0000e3, 0xfe0000e2, 0xfe0000e1, 0xfe0000e0,
    0xfe0000df, 0xfe0000de, 0xfe0000dd, 0xfe0000dc,
    0xfe0000db, 0xfe0000da, 0xfe0000d9, 0xfe0000d8,
    0xfe0000d7, 0xfe0000d6, 0xfe0000d5, 0xfe0000d4,
    0xfe0000d3, 0xfe0000d2, 0xfe0000d1, 0xfe0000d0,
    0xfe0000cf, 0xfe0000ce, 0xfe0000cd, 0xfe0000cc,
    0xfe0000cb, 0xfe0000ca, 0xfe0000c9, 0xfe0000c8,
    0xfe0000c7, 0xfe0000c6, 0xfe0000c5, 0xfe0000c4,
    0xfe0000c3, 0xfe0000c2, 0xfe0000c1, 0xfe0000c0,
    0xfe0000bf, 0xfe0000be, 0xfe0000bd, 0xfe0000bc,
    0xfe0000bb, 0xfe0000ba, 0xfe0000b9, 0xfe0000b8,
    0xfe0000b7, 0xfe0000b6, 0xfe0000b5, 0xfe0000b4,
    0xfe0000b3, 0xfe0000b2, 0xfe0000b1, 0xfe0000b0,
    0xfe0000af, 0xfe0000ae, 0xfe0000ad, 0xfe0000ac,
    0xfe0000ab, 0xfe0000aa, 0xfe0000a9, 0xfe0000a8,
    0xfe0000a7, 0xfe0000a6, 0xfe0000a5, 0xfe0000a4,
    0xfe0000a3, 0xfe0000a2, 0xfe0000a1, 0xfe0000a0,
    0xfe00009f, 0xfe00009e, 0xfe00009d, 0xfe00009c,
    0xfe00009b, 0xfe00009a, 0xfe000099, 0xfe000098,
    0xfe000097, 0xfe000096, 0xfe000095, 0xfe000094,
    0xfe000093, 0xfe000092, 0xfe000091, 0xfe000090,
    0xfe00008f, 0xfe00008e, 0xfe00008d, 0xfe00008c,
    0xfe00008b, 0xfe00008a, 0xfe000089, 0xfe000088,
    0xfe000087, 0xfe000086, 0xfe000085, 0xfe000084,
    0xfe000083, 0xfe000082, 0xfe000081, 0xfe000080,
    0xfe00007f, 0xfe00007e, 0xfe00007d, 0xfe00007c,
    0xfe00007b, 0xfe00007a, 0xfe000079, 0xfe000078,
    0xfe000077, 0xfe000076, 0xfe000075, 0xfe000074,
    0xfe000073, 0xfe000072, 0xfe000071, 0xfe000070,
    0xfe00006f, 0xfe00006e, 0xfe00006d, 0xfe00006c,
    0xfe00006b, 0xfe00006a, 0xfe000069, 0xfe000068,
    0xfe000067, 0xfe000066, 0xfe000065, 0xfe000064,
    0xfe000063, 0xfe000062, 0xfe000061, 0xfe000060,
    0xfe00005f, 0xfe00005e, 0xfe00005d, 0xfe00005c,
    0xfe00005b, 0xfe00005a, 0xfe000059, 0xfe000058,
    0xfe000057, 0xfe000056, 0xfe000055, 0xfe000054,
    0xfe000053, 0xfe000052, 0xfe000051, 0xfe000050,
    0xfe00004f, 0xfe00004e, 0xfe00004d, 0xfe00004c,
    0xfe00004b, 0xfe00004a, 0xfe000049, 0xfe000048,
    0xfe000047, 0xfe000046, 0xfe000045, 0xfe000044,
    0xfe000043, 0xfe000042, 0xfe000041, 0xfe000040,
    0xfe00003f, 0xfe00003e, 0xfe00003d, 0xfe00003c,
    0xfe00003b, 0xfe00003a, 0xfe000039, 0xfe000038,
    0xfe000037, 0xfe000036, 0xfe000035, 0xfe000034,
    0xfe000033, 0xfe000032, 0xfe000031, 0xfe000030,
    0xfe00002f, 0xfe00002e, 0xfe00002d, 0xfe00002c,
    0xfe00002b, 0xfe00002a, 0xfe000029, 0xfe000028,
    0xfe000027, 0xfe000026, 0xfe000025, 0xfe000024,
    0xfe000023, 0xfe000022, 0xfe000021, 0xfe000020,
    0xfe00001f, 0xfe00001e, 0xfe00001d, 0xfe00001c,
    0xfe00001b, 0xfe00001a, 0xfe000019, 0xfe000018,
    0xfe000017, 0xfe000016, 0xfe000015, 0xfe000014,
    0xfe000013, 0xfe000012, 0xfe000011, 0xfe000010,
    0xfe00000f, 0xfe00000e, 0xfe00000d, 0xfe00000c,
    0xfe00000b, 0xfe00000a, 0xfe000009, 0xfe000008,
    0xfe000007, 0xfe000006, 0xfe000005, 0xfe000004,
    0xfe000003, 0xfe000002, 0xfe000001, 0xfe000000,
    0xfdf7df7d, 0xfdef7bde, 0xfde6d1d6, 0xfddddddd,
    0xfdd49c34, 0xfdcb08d3, 0xfdc11f70, 0xfdb6db6d,
    0xfdac37da, 0xfda12f68, 0xfd95bc60, 0xfd89d89d,
    0xfd7d7d7d, 0xfd70a3d7, 0xfd6343eb, 0xfd555555,
    0xfd46cefa, 0xfd37a6f4, 0xfd27d27d, 0xfd1745d1,
    0xfd05f417, 0xfcf3cf3c, 0xfce0c7ce, 0xfccccccc,
    0xfcb7cb7c, 0xfca1af28, 0xfc8a60dd, 0xfc71c71c,
    0xfc57c57c, 0xfc3c3c3c, 0xfc1f07c1, 0xfc000000,
    0xfbdef7bd, 0xfbbbbbbb, 0xfb9611a7, 0xfb6db6db,
    0xfb425ed0, 0xfb13b13b, 0xfae147ae, 0xfaaaaaaa,
    0xfa6f4de9, 0xfa2e8ba2, 0xf9e79e79, 0xf9999999,
    0xf9435e50, 0xf8e38e38, 0xf8787878, 0xf8000000,
    0xf7777777, 0xf6db6db6, 0xf6276276, 0xf5555555,
    0xf45d1745, 0xf3333333, 0xf1c71c71, 0xf0000000,
    0xedb6db6d, 0xeaaaaaaa, 0xe6666666, 0xe0000000,
    0xd5555555, 0xc0000000, 0x80000000, 0x00000000
};
static inline uint64_t
fingerprint(const u_int8_t *p, unsigned plen)
{
    u_int fp = 0;
    for (u_int i=0; i<plen; i++) {
	fp *= FP_POINT;
	fp += p[i];
    }
    return (fp);
}

const u_int fp_tab8[] = {
    0x00000000, 0x381c0801, 0x70381002, 0xa8541803, 0xe0702004, 0x188c2805,
    0x50a83006, 0x88c43807, 0xc0e04008, 0xf8fc4809, 0x3118500a, 0x6934580b,
    0xa150600c, 0xd96c680d, 0x1188700e, 0x49a4780f, 0x81c08010, 0xb9dc8811,
    0xf1f89012, 0x2a149813, 0x6230a014, 0x9a4ca815, 0xd268b016, 0x0a84b817,
    0x42a0c018, 0x7abcc819, 0xb2d8d01a, 0xeaf4d81b, 0x2310e01c, 0x5b2ce81d,
    0x9348f01e, 0xcb64f81f, 0x03810020, 0x3b9d0821, 0x73b91022, 0xabd51823,
    0xe3f12024, 0x1c0d2825, 0x54293026, 0x8c453827, 0xc4614028, 0xfc7d4829,
    0x3499502a, 0x6cb5582b, 0xa4d1602c, 0xdced682d, 0x1509702e, 0x4d25782f,
    0x85418030, 0xbd5d8831, 0xf5799032, 0x2d959833, 0x65b1a034, 0x9dcda835,
    0xd5e9b036, 0x0e05b837, 0x4621c038, 0x7e3dc839, 0xb659d03a, 0xee75d83b,
    0x2691e03c, 0x5eade83d, 0x96c9f03e, 0xcee5f83f, 0x07020040, 0x3f1e0841,
    0x773a1042, 0xaf561843, 0xe7722044, 0x1f8e2845, 0x57aa3046, 0x8fc63847,
    0xc7e24048, 0xfffe4849, 0x381a504a, 0x7036584b, 0xa852604c, 0xe06e684d,
    0x188a704e, 0x50a6784f, 0x88c28050, 0xc0de8851, 0xf8fa9052, 0x31169853,
    0x6932a054, 0xa14ea855, 0xd96ab056, 0x1186b857, 0x49a2c058, 0x81bec859,
    0xb9dad05a, 0xf1f6d85b, 0x2a12e05c, 0x622ee85d, 0x9a4af05e, 0xd266f85f,
    0x0a830060, 0x429f0861, 0x7abb1062, 0xb2d71863, 0xeaf32064, 0x230f2865,
    0x5b2b3066, 0x93473867, 0xcb634068, 0x037f4869, 0x3b9b506a, 0x73b7586b,
    0xabd3606c, 0xe3ef686d, 0x1c0b706e, 0x5427786f, 0x8c438070, 0xc45f8871,
    0xfc7b9072, 0x34979873, 0x6cb3a074, 0xa4cfa875, 0xdcebb076, 0x1507b877,
    0x4d23c078, 0x853fc879, 0xbd5bd07a, 0xf577d87b, 0x2d93e07c, 0x65afe87d,
    0x9dcbf07e, 0xd5e7f87f, 0x0e040080, 0x46200881, 0x7e3c1082, 0xb6581883,
    0xee742084, 0x26902885, 0x5eac3086, 0x96c83887, 0xcee44088, 0x07004889,
    0x3f1c508a, 0x7738588b, 0xaf54608c, 0xe770688d, 0x1f8c708e, 0x57a8788f,
    0x8fc48090, 0xc7e08891, 0xfffc9092, 0x38189893, 0x7034a094, 0xa850a895,
    0xe06cb096, 0x1888b897, 0x50a4c098, 0x88c0c899, 0xc0dcd09a, 0xf8f8d89b,
    0x3114e09c, 0x6930e89d, 0xa14cf09e, 0xd968f89f, 0x118500a0, 0x49a108a1,
    0x81bd10a2, 0xb9d918a3, 0xf1f520a4, 0x2a1128a5, 0x622d30a6, 0x9a4938a7,
    0xd26540a8, 0x0a8148a9, 0x429d50aa, 0x7ab958ab, 0xb2d560ac, 0xeaf168ad,
    0x230d70ae, 0x5b2978af, 0x934580b0, 0xcb6188b1, 0x037d90b2, 0x3b9998b3,
    0x73b5a0b4, 0xabd1a8b5, 0xe3edb0b6, 0x1c09b8b7, 0x5425c0b8, 0x8c41c8b9,
    0xc45dd0ba, 0xfc79d8bb, 0x3495e0bc, 0x6cb1e8bd, 0xa4cdf0be, 0xdce9f8bf,
    0x150600c0, 0x4d2208c1, 0x853e10c2, 0xbd5a18c3, 0xf57620c4, 0x2d9228c5,
    0x65ae30c6, 0x9dca38c7, 0xd5e640c8, 0x0e0248c9, 0x461e50ca, 0x7e3a58cb,
    0xb65660cc, 0xee7268cd, 0x268e70ce, 0x5eaa78cf, 0x96c680d0, 0xcee288d1,
    0x06fe90d2, 0x3f1a98d3, 0x7736a0d4, 0xaf52a8d5, 0xe76eb0d6, 0x1f8ab8d7,
    0x57a6c0d8, 0x8fc2c8d9, 0xc7ded0da, 0xfffad8db, 0x3816e0dc, 0x7032e8dd,
    0xa84ef0de, 0xe06af8df, 0x188700e0, 0x50a308e1, 0x88bf10e2, 0xc0db18e3,
    0xf8f720e4, 0x311328e5, 0x692f30e6, 0xa14b38e7, 0xd96740e8, 0x118348e9,
    0x499f50ea, 0x81bb58eb, 0xb9d760ec, 0xf1f368ed, 0x2a0f70ee, 0x622b78ef,
    0x9a4780f0, 0xd26388f1, 0x0a7f90f2, 0x429b98f3, 0x7ab7a0f4, 0xb2d3a8f5,
    0xeaefb0f6, 0x230bb8f7, 0x5b27c0f8, 0x9343c8f9, 0xcb5fd0fa, 0x037bd8fb,
    0x3b97e0fc, 0x73b3e8fd, 0xabcff0fe, 0xe3ebf8ff,
};

int MAX_SEGLEN = 512;
int fp_scan_mode = 0;
int FP_WINDOWSZ = 8;

static u_int32_t
fp_scan_mode0(u_int8_t* in, u_int8_t* out, bool* cutpoint_found, uint64_t* outfp)
{

    //If our maximum segment length is 512 bytes and we have 512 consecutive
    //bytes we can unroll the scan completely. This improves speed slightly
    //because (1) the threshold constants can be compiled directly into the
    //comparison instructions, instead of being looked-up from the table at
    //runtime, (2) we can read and write 8 bytes at a time and incrementally
    //maintain 16 bytes of input text in two registers, (3) we have
    //compile-time knowledge of which of those 16 bytes is entering the 8-byte
    //fingerprint window and which is leaving, so the compiler can keep each
    //entering byte in a register until it needs to be removed, and (4) we have
    //compile-time knowledge of the cutpoint offset so we don't need to use a
    //register to keep track of our current offset, preventing all spills to
    //the stack.

    //Downsides are lack of flexibility, lack of scalability, huge code size
    //(~28 KiB), and use of macros that iterferes with debugging. The large
    //code of this implementation may make alternative implementations faster
    //even if those implementations look slower in stand-alone benchmarks
    //because of poor instruction caching that might only be an issue outside
    //small benchmarks. We look forward to removing this as soon as we have a
    //better approach.

    //COMPILE_TIME_ASSERT(FP_WINDOWSZ == 8);
    //ASSERT(MAX_SEGLEN == 512);
    //ASSERT(fp_scan_mode == 0);

    //Start the scan by fingerprinting the first 8 bytes.

    uint64_t fp = fingerprint(in, FP_WINDOWSZ);

    //We keep 16 bytes of input text in two 8-byte registers, older and newer.
    //The first 8 bytes, that were used to initialize fp above, are read into
    //newer and written to out. In the first stage below, STAGE(8), we will
    //copy newer to older and load another 8 bytes into newer.

    u_int64_t older;
    u_int64_t newer = *(u_int64_t*)in;
    *(u_int64_t*)out = newer;

    u_int32_t bytes;

    //There is one STAGE for each byte of input text, starting at the 9th byte
    //(i.e., byte 8). Before processing byte N, we check to see if bytes N-8,
    //..., N-1 form a cutpoint. If so the segment length is N and we jump to
    //found. The use of UNLIKELY is important here because doing so prevents
    //gcc from keeping the "bytes" variable in a register. Freeing up a
    //register prevents all spills to the stack.

    //Otherwise we have not yet found a cutpoint. If N is a multiple of 8 then
    //we are about to process the first byte of a new 8-byte section of the
    //input text. So we need to copy the last 8 bytes from newer into older,
    //and load the next 8 bytes into newer. We write the newly-loaded 8-bytes
    //to out immediately.

    //Now the fingerprint hash is updated to cover byte N (entering), and byte
    //N-8 (leaving) is factored out. So once STAGE(N) finishes, fp covers bytes
    //N-7, ..., N. We use two constant distance shifts to isolate byte N and
    //byte N-8, but gcc is able to keep track of the entering byte until it
    //becomes the leaving byte at some later stage.

    //We explicitly use shift and add to multiply by 257 to prevent gcc from
    //using imul, which seems to be slower.

#define STAGE(N) { \
    COMPILE_TIME_ASSERT(FP_WINDOWSZ <= N); \
    COMPILE_TIME_ASSERT(N < 512); \
    if (UNLIKELY(fp > fp_scan_thresh_orig[N])) { \
        bytes = N; \
        goto found; \
    } \
    if (N%8 == 0) { \
        older = newer; \
        newer = *(u_int64_t*)(in+N); \
        *(u_int64_t*)(out+N) = newer; \
    } \
    u_int8_t leaving = (u_int8_t)(older>>N%8*8); \
    u_int8_t entering = (u_int8_t)(newer>>N%8*8); \
    fp += fp<<8; \
    fp += entering-fp_tab8[leaving]; \
}

    STAGE(8); STAGE(9); STAGE(10); STAGE(11); STAGE(12); STAGE(13); STAGE(14); STAGE(15);
    STAGE(16); STAGE(17); STAGE(18); STAGE(19); STAGE(20); STAGE(21); STAGE(22); STAGE(23);
    STAGE(24); STAGE(25); STAGE(26); STAGE(27); STAGE(28); STAGE(29); STAGE(30); STAGE(31);
    STAGE(32); STAGE(33); STAGE(34); STAGE(35); STAGE(36); STAGE(37); STAGE(38); STAGE(39);
    STAGE(40); STAGE(41); STAGE(42); STAGE(43); STAGE(44); STAGE(45); STAGE(46); STAGE(47);
    STAGE(48); STAGE(49); STAGE(50); STAGE(51); STAGE(52); STAGE(53); STAGE(54); STAGE(55);
    STAGE(56); STAGE(57); STAGE(58); STAGE(59); STAGE(60); STAGE(61); STAGE(62); STAGE(63);
    STAGE(64); STAGE(65); STAGE(66); STAGE(67); STAGE(68); STAGE(69); STAGE(70); STAGE(71);
    STAGE(72); STAGE(73); STAGE(74); STAGE(75); STAGE(76); STAGE(77); STAGE(78); STAGE(79);
    STAGE(80); STAGE(81); STAGE(82); STAGE(83); STAGE(84); STAGE(85); STAGE(86); STAGE(87);
    STAGE(88); STAGE(89); STAGE(90); STAGE(91); STAGE(92); STAGE(93); STAGE(94); STAGE(95);
    STAGE(96); STAGE(97); STAGE(98); STAGE(99); STAGE(100); STAGE(101); STAGE(102); STAGE(103);
    STAGE(104); STAGE(105); STAGE(106); STAGE(107); STAGE(108); STAGE(109); STAGE(110); STAGE(111);
    STAGE(112); STAGE(113); STAGE(114); STAGE(115); STAGE(116); STAGE(117); STAGE(118); STAGE(119);
    STAGE(120); STAGE(121); STAGE(122); STAGE(123); STAGE(124); STAGE(125); STAGE(126); STAGE(127);
    STAGE(128); STAGE(129); STAGE(130); STAGE(131); STAGE(132); STAGE(133); STAGE(134); STAGE(135);
    STAGE(136); STAGE(137); STAGE(138); STAGE(139); STAGE(140); STAGE(141); STAGE(142); STAGE(143);
    STAGE(144); STAGE(145); STAGE(146); STAGE(147); STAGE(148); STAGE(149); STAGE(150); STAGE(151);
    STAGE(152); STAGE(153); STAGE(154); STAGE(155); STAGE(156); STAGE(157); STAGE(158); STAGE(159);
    STAGE(160); STAGE(161); STAGE(162); STAGE(163); STAGE(164); STAGE(165); STAGE(166); STAGE(167);
    STAGE(168); STAGE(169); STAGE(170); STAGE(171); STAGE(172); STAGE(173); STAGE(174); STAGE(175);
    STAGE(176); STAGE(177); STAGE(178); STAGE(179); STAGE(180); STAGE(181); STAGE(182); STAGE(183);
    STAGE(184); STAGE(185); STAGE(186); STAGE(187); STAGE(188); STAGE(189); STAGE(190); STAGE(191);
    STAGE(192); STAGE(193); STAGE(194); STAGE(195); STAGE(196); STAGE(197); STAGE(198); STAGE(199);
    STAGE(200); STAGE(201); STAGE(202); STAGE(203); STAGE(204); STAGE(205); STAGE(206); STAGE(207);
    STAGE(208); STAGE(209); STAGE(210); STAGE(211); STAGE(212); STAGE(213); STAGE(214); STAGE(215);
    STAGE(216); STAGE(217); STAGE(218); STAGE(219); STAGE(220); STAGE(221); STAGE(222); STAGE(223);
    STAGE(224); STAGE(225); STAGE(226); STAGE(227); STAGE(228); STAGE(229); STAGE(230); STAGE(231);
    STAGE(232); STAGE(233); STAGE(234); STAGE(235); STAGE(236); STAGE(237); STAGE(238); STAGE(239);
    STAGE(240); STAGE(241); STAGE(242); STAGE(243); STAGE(244); STAGE(245); STAGE(246); STAGE(247);
    STAGE(248); STAGE(249); STAGE(250); STAGE(251); STAGE(252); STAGE(253); STAGE(254); STAGE(255);
    STAGE(256); STAGE(257); STAGE(258); STAGE(259); STAGE(260); STAGE(261); STAGE(262); STAGE(263);
    STAGE(264); STAGE(265); STAGE(266); STAGE(267); STAGE(268); STAGE(269); STAGE(270); STAGE(271);
    STAGE(272); STAGE(273); STAGE(274); STAGE(275); STAGE(276); STAGE(277); STAGE(278); STAGE(279);
    STAGE(280); STAGE(281); STAGE(282); STAGE(283); STAGE(284); STAGE(285); STAGE(286); STAGE(287);
    STAGE(288); STAGE(289); STAGE(290); STAGE(291); STAGE(292); STAGE(293); STAGE(294); STAGE(295);
    STAGE(296); STAGE(297); STAGE(298); STAGE(299); STAGE(300); STAGE(301); STAGE(302); STAGE(303);
    STAGE(304); STAGE(305); STAGE(306); STAGE(307); STAGE(308); STAGE(309); STAGE(310); STAGE(311);
    STAGE(312); STAGE(313); STAGE(314); STAGE(315); STAGE(316); STAGE(317); STAGE(318); STAGE(319);
    STAGE(320); STAGE(321); STAGE(322); STAGE(323); STAGE(324); STAGE(325); STAGE(326); STAGE(327);
    STAGE(328); STAGE(329); STAGE(330); STAGE(331); STAGE(332); STAGE(333); STAGE(334); STAGE(335);
    STAGE(336); STAGE(337); STAGE(338); STAGE(339); STAGE(340); STAGE(341); STAGE(342); STAGE(343);
    STAGE(344); STAGE(345); STAGE(346); STAGE(347); STAGE(348); STAGE(349); STAGE(350); STAGE(351);
    STAGE(352); STAGE(353); STAGE(354); STAGE(355); STAGE(356); STAGE(357); STAGE(358); STAGE(359);
    STAGE(360); STAGE(361); STAGE(362); STAGE(363); STAGE(364); STAGE(365); STAGE(366); STAGE(367);
    STAGE(368); STAGE(369); STAGE(370); STAGE(371); STAGE(372); STAGE(373); STAGE(374); STAGE(375);
    STAGE(376); STAGE(377); STAGE(378); STAGE(379); STAGE(380); STAGE(381); STAGE(382); STAGE(383);
    STAGE(384); STAGE(385); STAGE(386); STAGE(387); STAGE(388); STAGE(389); STAGE(390); STAGE(391);
    STAGE(392); STAGE(393); STAGE(394); STAGE(395); STAGE(396); STAGE(397); STAGE(398); STAGE(399);
    STAGE(400); STAGE(401); STAGE(402); STAGE(403); STAGE(404); STAGE(405); STAGE(406); STAGE(407);
    STAGE(408); STAGE(409); STAGE(410); STAGE(411); STAGE(412); STAGE(413); STAGE(414); STAGE(415);
    STAGE(416); STAGE(417); STAGE(418); STAGE(419); STAGE(420); STAGE(421); STAGE(422); STAGE(423);
    STAGE(424); STAGE(425); STAGE(426); STAGE(427); STAGE(428); STAGE(429); STAGE(430); STAGE(431);
    STAGE(432); STAGE(433); STAGE(434); STAGE(435); STAGE(436); STAGE(437); STAGE(438); STAGE(439);
    STAGE(440); STAGE(441); STAGE(442); STAGE(443); STAGE(444); STAGE(445); STAGE(446); STAGE(447);
    STAGE(448); STAGE(449); STAGE(450); STAGE(451); STAGE(452); STAGE(453); STAGE(454); STAGE(455);
    STAGE(456); STAGE(457); STAGE(458); STAGE(459); STAGE(460); STAGE(461); STAGE(462); STAGE(463);
    STAGE(464); STAGE(465); STAGE(466); STAGE(467); STAGE(468); STAGE(469); STAGE(470); STAGE(471);
    STAGE(472); STAGE(473); STAGE(474); STAGE(475); STAGE(476); STAGE(477); STAGE(478); STAGE(479);
    STAGE(480); STAGE(481); STAGE(482); STAGE(483); STAGE(484); STAGE(485); STAGE(486); STAGE(487);
    STAGE(488); STAGE(489); STAGE(490); STAGE(491); STAGE(492); STAGE(493); STAGE(494); STAGE(495);
    STAGE(496); STAGE(497); STAGE(498); STAGE(499); STAGE(500); STAGE(501); STAGE(502); STAGE(503);
    STAGE(504); STAGE(505); STAGE(506); STAGE(507); STAGE(508); STAGE(509); STAGE(510); STAGE(511);

#undef STAGE

    //If we reach this point, we have scanned bytes 0 through 511, inclusive.
    //The fingerprint now covers bytes 504, ..., 511. We have processed all 512
    //bytes and found no cutpoint before the byte 511, so we force a cutpoint
    //at byte 511.

    bytes = 512;

found:
    *cutpoint_found = true;
    *outfp = fp;
    return bytes;
}

static u_int32_t
fp_scan_mode1(u_int8_t* in, u_int8_t* out, bool* cutpoint_found, uint64_t* outfp)
{

    //If our maximum segment length is 512 bytes and we have 512 consecutive
    //bytes we can unroll the scan completely. This improves speed slightly
    //because (1) the threshold constants can be compiled directly into the
    //comparison instructions, instead of being looked-up from the table at
    //runtime, (2) we can read and write 8 bytes at a time and incrementally
    //maintain 16 bytes of input text in two registers, (3) we have
    //compile-time knowledge of which of those 16 bytes is entering the 8-byte
    //fingerprint window and which is leaving, so the compiler can keep each
    //entering byte in a register until it needs to be removed, and (4) we have
    //compile-time knowledge of the cutpoint offset so we don't need to use a
    //register to keep track of our current offset, preventing all spills to
    //the stack.

    //Downsides are lack of flexibility, lack of scalability, huge code size
    //(~28 KiB), and use of macros that iterferes with debugging. The large
    //code of this implementation may make alternative implementations faster
    //even if those implementations look slower in stand-alone benchmarks
    //because of poor instruction caching that might only be an issue outside
    //small benchmarks. We look forward to removing this as soon as we have a
    //better approach.

    //COMPILE_TIME_ASSERT(FP_WINDOWSZ == 8);
    //ASSERT(MAX_SEGLEN == 512);
    //ASSERT(fp_scan_mode == 0);

    //Start the scan by fingerprinting the first 8 bytes.

    uint64_t fp = fingerprint(in, FP_WINDOWSZ);

    //We keep 16 bytes of input text in two 8-byte registers, older and newer.
    //The first 8 bytes, that were used to initialize fp above, are read into
    //newer and written to out. In the first stage below, STAGE(8), we will
    //copy newer to older and load another 8 bytes into newer.

    u_int64_t older;
    u_int64_t newer = *(u_int64_t*)in;
    *(u_int64_t*)out = newer;

    u_int32_t bytes;

    //There is one STAGE for each byte of input text, starting at the 9th byte
    //(i.e., byte 8). Before processing byte N, we check to see if bytes N-8,
    //..., N-1 form a cutpoint. If so the segment length is N and we jump to
    //found. The use of UNLIKELY is important here because doing so prevents
    //gcc from keeping the "bytes" variable in a register. Freeing up a
    //register prevents all spills to the stack.

    //Otherwise we have not yet found a cutpoint. If N is a multiple of 8 then
    //we are about to process the first byte of a new 8-byte section of the
    //input text. So we need to copy the last 8 bytes from newer into older,
    //and load the next 8 bytes into newer. We write the newly-loaded 8-bytes
    //to out immediately.

    //Now the fingerprint hash is updated to cover byte N (entering), and byte
    //N-8 (leaving) is factored out. So once STAGE(N) finishes, fp covers bytes
    //N-7, ..., N. We use two constant distance shifts to isolate byte N and
    //byte N-8, but gcc is able to keep track of the entering byte until it
    //becomes the leaving byte at some later stage.

    //We explicitly use shift and add to multiply by 257 to prevent gcc from
    //using imul, which seems to be slower.

#define _STAGE(N) { \
    COMPILE_TIME_ASSERT(FP_WINDOWSZ <= N); \
    COMPILE_TIME_ASSERT(N < 512); \
    if (UNLIKELY(fp > fp_scan_thresh_orig[N])) { \
        bytes = N; \
        goto found; \
    } \
    if (N%8 == 0) { \
        older = newer; \
        newer = *(u_int64_t*)(in+N); \
        *(u_int64_t*)(out+N) = newer; \
    } \
    u_int8_t leaving = (u_int8_t)(older>>N%8*8); \
    u_int8_t entering = (u_int8_t)(newer>>N%8*8); \
    fp += fp<<8; \
    fp += entering-fp_tab8[leaving]; \
}

#define STAGE(N) _STAGE((N))

    for (int i = 0; i <= 511 - 15; i = i+8) {
    		STAGE(i+8);
    		STAGE(i+9);
    		STAGE(i+10);
    		STAGE(i+11);
    		STAGE(i+12);
    		STAGE(i+13);
    		STAGE(i+14);
    		STAGE(i+15);
    }
   /* STAGE(8); STAGE(9); STAGE(10); STAGE(11); STAGE(12); STAGE(13); STAGE(14); STAGE(15);
    STAGE(16); STAGE(17); STAGE(18); STAGE(19); STAGE(20); STAGE(21); STAGE(22); STAGE(23);
    STAGE(24); STAGE(25); STAGE(26); STAGE(27); STAGE(28); STAGE(29); STAGE(30); STAGE(31);
    STAGE(32); STAGE(33); STAGE(34); STAGE(35); STAGE(36); STAGE(37); STAGE(38); STAGE(39);
    STAGE(40); STAGE(41); STAGE(42); STAGE(43); STAGE(44); STAGE(45); STAGE(46); STAGE(47);
    STAGE(48); STAGE(49); STAGE(50); STAGE(51); STAGE(52); STAGE(53); STAGE(54); STAGE(55);
    STAGE(56); STAGE(57); STAGE(58); STAGE(59); STAGE(60); STAGE(61); STAGE(62); STAGE(63);
    STAGE(64); STAGE(65); STAGE(66); STAGE(67); STAGE(68); STAGE(69); STAGE(70); STAGE(71);
    STAGE(72); STAGE(73); STAGE(74); STAGE(75); STAGE(76); STAGE(77); STAGE(78); STAGE(79);
    STAGE(80); STAGE(81); STAGE(82); STAGE(83); STAGE(84); STAGE(85); STAGE(86); STAGE(87);
    STAGE(88); STAGE(89); STAGE(90); STAGE(91); STAGE(92); STAGE(93); STAGE(94); STAGE(95);
    STAGE(96); STAGE(97); STAGE(98); STAGE(99); STAGE(100); STAGE(101); STAGE(102); STAGE(103);
    STAGE(104); STAGE(105); STAGE(106); STAGE(107); STAGE(108); STAGE(109); STAGE(110); STAGE(111);
    STAGE(112); STAGE(113); STAGE(114); STAGE(115); STAGE(116); STAGE(117); STAGE(118); STAGE(119);
    STAGE(120); STAGE(121); STAGE(122); STAGE(123); STAGE(124); STAGE(125); STAGE(126); STAGE(127);
    STAGE(128); STAGE(129); STAGE(130); STAGE(131); STAGE(132); STAGE(133); STAGE(134); STAGE(135);
    STAGE(136); STAGE(137); STAGE(138); STAGE(139); STAGE(140); STAGE(141); STAGE(142); STAGE(143);
    STAGE(144); STAGE(145); STAGE(146); STAGE(147); STAGE(148); STAGE(149); STAGE(150); STAGE(151);
    STAGE(152); STAGE(153); STAGE(154); STAGE(155); STAGE(156); STAGE(157); STAGE(158); STAGE(159);
    STAGE(160); STAGE(161); STAGE(162); STAGE(163); STAGE(164); STAGE(165); STAGE(166); STAGE(167);
    STAGE(168); STAGE(169); STAGE(170); STAGE(171); STAGE(172); STAGE(173); STAGE(174); STAGE(175);
    STAGE(176); STAGE(177); STAGE(178); STAGE(179); STAGE(180); STAGE(181); STAGE(182); STAGE(183);
    STAGE(184); STAGE(185); STAGE(186); STAGE(187); STAGE(188); STAGE(189); STAGE(190); STAGE(191);
    STAGE(192); STAGE(193); STAGE(194); STAGE(195); STAGE(196); STAGE(197); STAGE(198); STAGE(199);
    STAGE(200); STAGE(201); STAGE(202); STAGE(203); STAGE(204); STAGE(205); STAGE(206); STAGE(207);
    STAGE(208); STAGE(209); STAGE(210); STAGE(211); STAGE(212); STAGE(213); STAGE(214); STAGE(215);
    STAGE(216); STAGE(217); STAGE(218); STAGE(219); STAGE(220); STAGE(221); STAGE(222); STAGE(223);
    STAGE(224); STAGE(225); STAGE(226); STAGE(227); STAGE(228); STAGE(229); STAGE(230); STAGE(231);
    STAGE(232); STAGE(233); STAGE(234); STAGE(235); STAGE(236); STAGE(237); STAGE(238); STAGE(239);
    STAGE(240); STAGE(241); STAGE(242); STAGE(243); STAGE(244); STAGE(245); STAGE(246); STAGE(247);
    STAGE(248); STAGE(249); STAGE(250); STAGE(251); STAGE(252); STAGE(253); STAGE(254); STAGE(255);
    STAGE(256); STAGE(257); STAGE(258); STAGE(259); STAGE(260); STAGE(261); STAGE(262); STAGE(263);
    STAGE(264); STAGE(265); STAGE(266); STAGE(267); STAGE(268); STAGE(269); STAGE(270); STAGE(271);
    STAGE(272); STAGE(273); STAGE(274); STAGE(275); STAGE(276); STAGE(277); STAGE(278); STAGE(279);
    STAGE(280); STAGE(281); STAGE(282); STAGE(283); STAGE(284); STAGE(285); STAGE(286); STAGE(287);
    STAGE(288); STAGE(289); STAGE(290); STAGE(291); STAGE(292); STAGE(293); STAGE(294); STAGE(295);
    STAGE(296); STAGE(297); STAGE(298); STAGE(299); STAGE(300); STAGE(301); STAGE(302); STAGE(303);
    STAGE(304); STAGE(305); STAGE(306); STAGE(307); STAGE(308); STAGE(309); STAGE(310); STAGE(311);
    STAGE(312); STAGE(313); STAGE(314); STAGE(315); STAGE(316); STAGE(317); STAGE(318); STAGE(319);
    STAGE(320); STAGE(321); STAGE(322); STAGE(323); STAGE(324); STAGE(325); STAGE(326); STAGE(327);
    STAGE(328); STAGE(329); STAGE(330); STAGE(331); STAGE(332); STAGE(333); STAGE(334); STAGE(335);
    STAGE(336); STAGE(337); STAGE(338); STAGE(339); STAGE(340); STAGE(341); STAGE(342); STAGE(343);
    STAGE(344); STAGE(345); STAGE(346); STAGE(347); STAGE(348); STAGE(349); STAGE(350); STAGE(351);
    STAGE(352); STAGE(353); STAGE(354); STAGE(355); STAGE(356); STAGE(357); STAGE(358); STAGE(359);
    STAGE(360); STAGE(361); STAGE(362); STAGE(363); STAGE(364); STAGE(365); STAGE(366); STAGE(367);
    STAGE(368); STAGE(369); STAGE(370); STAGE(371); STAGE(372); STAGE(373); STAGE(374); STAGE(375);
    STAGE(376); STAGE(377); STAGE(378); STAGE(379); STAGE(380); STAGE(381); STAGE(382); STAGE(383);
    STAGE(384); STAGE(385); STAGE(386); STAGE(387); STAGE(388); STAGE(389); STAGE(390); STAGE(391);
    STAGE(392); STAGE(393); STAGE(394); STAGE(395); STAGE(396); STAGE(397); STAGE(398); STAGE(399);
    STAGE(400); STAGE(401); STAGE(402); STAGE(403); STAGE(404); STAGE(405); STAGE(406); STAGE(407);
    STAGE(408); STAGE(409); STAGE(410); STAGE(411); STAGE(412); STAGE(413); STAGE(414); STAGE(415);
    STAGE(416); STAGE(417); STAGE(418); STAGE(419); STAGE(420); STAGE(421); STAGE(422); STAGE(423);
    STAGE(424); STAGE(425); STAGE(426); STAGE(427); STAGE(428); STAGE(429); STAGE(430); STAGE(431);
    STAGE(432); STAGE(433); STAGE(434); STAGE(435); STAGE(436); STAGE(437); STAGE(438); STAGE(439);
    STAGE(440); STAGE(441); STAGE(442); STAGE(443); STAGE(444); STAGE(445); STAGE(446); STAGE(447);
    STAGE(448); STAGE(449); STAGE(450); STAGE(451); STAGE(452); STAGE(453); STAGE(454); STAGE(455);
    STAGE(456); STAGE(457); STAGE(458); STAGE(459); STAGE(460); STAGE(461); STAGE(462); STAGE(463);
    STAGE(464); STAGE(465); STAGE(466); STAGE(467); STAGE(468); STAGE(469); STAGE(470); STAGE(471);
    STAGE(472); STAGE(473); STAGE(474); STAGE(475); STAGE(476); STAGE(477); STAGE(478); STAGE(479);
    STAGE(480); STAGE(481); STAGE(482); STAGE(483); STAGE(484); STAGE(485); STAGE(486); STAGE(487);
    STAGE(488); STAGE(489); STAGE(490); STAGE(491); STAGE(492); STAGE(493); STAGE(494); STAGE(495);
    STAGE(496); STAGE(497); STAGE(498); STAGE(499); STAGE(500); STAGE(501); STAGE(502); STAGE(503);
    STAGE(504); STAGE(505); STAGE(506); STAGE(507); STAGE(508); STAGE(509); STAGE(510); STAGE(511);*/

#undef STAGE

    //If we reach this point, we have scanned bytes 0 through 511, inclusive.
    //The fingerprint now covers bytes 504, ..., 511. We have processed all 512
    //bytes and found no cutpoint before the byte 511, so we force a cutpoint
    //at byte 511.

    bytes = 512;

found:
    *cutpoint_found = true;
    *outfp = fp;
    return bytes;
}

typedef unsigned long long ticks;

static __inline__ ticks getticks(void)
{
     unsigned a, d;
     asm("cpuid");
     asm volatile("rdtsc" : "=a" (a), "=d" (d));

     return (((ticks)a) | (((ticks)d) << 32));
}


int main()
{
	int num_repeats = 10;
	int *p = nullptr;
	bool b = {p};
	u_int8_t *in = new u_int8_t[515];
	u_int8_t *out = new u_int8_t[515];
	memset(in, 0, 515);
	//memset(out, 0, 515);
	bool result;
	u_int64_t fp;
	//auto t0 = high_resolution_clock::now();
	auto t0 = getticks();
	for(int i =0; i < num_repeats; i++) {
		auto x = fp_scan_mode0(in, out, &result, &fp);
		if (x != 512)
			cout<<"failed\n";
	}
	//auto t1 = high_resolution_clock::now();
	auto t1 = getticks();
	//cout<<(t1-t0)/num_repeats<<",result="<<endl;
	t0 = getticks();
	for(int i =0; i < num_repeats; i++) {
		auto x = fp_scan_mode1(in, out, &result, &fp);
		if (x != 512)
			cout<<"failed\n";
	}
	//auto t1 = high_resolution_clock::now();
	t1 = getticks();
	//cout<<(t1-t0)/num_repeats<<",result="<<endl;
	//cout<<(t1-t0).count()<<endl;

}
