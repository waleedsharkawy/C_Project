/********************************WaleedSharawy************************************
*****************************Typedef Defination***********************************
**********************************************************************************/
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;


typedef float f32;
typedef double f64;
typedef long double f128;



typedef struct
{
	u8 Age;
	u8 Account_Status;
	u16 Password;
	s32 Balance;
	u32 Bank_Account_ID;
	u8 National_ID[15];
	u8 Guardian_National_ID[15];
	u8 Name[60];
	u8 Address[80];
}Account_S;

