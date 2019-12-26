// sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "operator.h"
#include "controls.h"
#include "cppcheck.h"


u64 UTL_atoll(u8 *s)
{
    u64 r = 0;

    while(*s)
    {
        r = 10 * r + (*s - '0');
        s++;
    }

    return r;
}
void UTL_Bcdplus(u8 *in1, u8 length1, u8 *in2, u8 length2, u8 *out)
{
    u64 int1 = 0;
    u64 int2 = 0;
    u64 ret;
    u8 i;

    while(length1--)
    {
        int1 = (int1 * 100) + (((*in1 >> 4) & 0x0F) * 10) + (*in1 & 15);
        in1++;
    }

    while(length2--)
    {
        int2 = (int2 * 100) + (((*in2 >> 4) & 0x0F) * 10) + (*in2 & 15);
        in2++;
    }

    ret = int1 + int2;

    for(i = 0; i < sizeof(u64); i++)
    {
        out[sizeof(u64) - i - 1] = (u8)(ret % 10);
        ret /= 10;
        out[sizeof(u64) - i - 1] |= (u8)((ret % 10) << 4);
        ret /= 10;
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
	u32 t = 3;
	u64 i1 = 10, i2 = 20;
	u8 a[6] = {0x97, 0x65, 0x25, 0x11, 0x00, 0x88};
	u8 b[6] = {0x96, 0x64, 0x24, 0x10, 0x10, 0x78};
	u8 c[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	u8 t5f25[3] = {0x16, 0x10, 0x30};
	
	int total = UTL_Bcd2Int(&t5f25[0], 1)*12;
	UTL_Bcdplus(a, 6, b, 6, c);

	printf("%llu - %lld", i1, i2);

	return 0;
}



/*
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long long l = 0;

	l = UTL_pow(2,64);
	printf("%llu\n", l);
	l = l -1 ;
	printf("%llu", l);
	return 0;
}
*/
/*
int _tmain(int argc, _TCHAR* argv[])
{
	char number = 0;

	do
	{
		printf("0-15 arasinda bir sayi giriniz...\n");
		scanf_s("%d", &number);
		
		printf("'%d' = %c\n", number, toHex(number));
	} while (1);

	return 0;
}
*/
/*
int _tmain(int argc, _TCHAR* argv[])
{
	char ch;

	do
	{
		printf("Hex digit gösteren bir karakter giriniz...\n");
		ch = getchar();

		if (ch == 0x0a)
			ch = getchar();
		
		printf("'%c' = %d\n", ch, toDecimal(ch));
	} while (ch != 'X');

	return 0;
}
*/
/*
int _tmain(int argc, _TCHAR* argv[])
{
	char sentence[256] = "belediye YOLLARI kazMıS, ama ben naSıL GELirEm.";
	
	capitalize(sentence);

	return 0;
}
*/
/*
int _tmain(int argc, _TCHAR* argv[])
{
	char sentence[256] = "";
	char ch;
	int i = 0;

	printf("Bir cumle giriniz...\n");
	do
	{						
		ch = getchar();
		sentence[i++] = toLower(ch);
	} while (ch != 0x0a);	
	printf("Girdiginiz cumle: %s", sentence);

	return 0;
}
*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
	char ch;

	do
	{
		printf("Bir karakter giriniz...\n");
		ch = getchar();

		if (ch == 0x0a)
			ch = getchar();

		if (isHexDigit(ch))
			printf("'%c', Hex karakteridir.(%u, 0x%x)\n", ch, ch, ch, ch);
		else
			printf("'%c', Hex karakteri degildir.\n", ch);
	} while (ch != 'X');

	return 0;
}
*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	printf("bir karakter giriniz.\n");
	ch = getchar();

	if (isAlphaNumeric(ch))
		printf("Alfabetik veya numara karakteri");
	else
		printf("Alfabetik veya numara karakteri degil..");

	return 0;
}
*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	printf("bir karakter giriniz.\n");
	ch = getchar();

	if (isDigit(ch))
		printf("rakam karakteri");
	else
		printf("rakam karakteri degil..");

	return 0;
}
*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	printf("bir karakter giriniz.\n");
	ch = getchar();

	if (isAlphabetic(ch))
		printf("alfabetik karakter");
	else
		printf("alfabetik karakter degil..");

	return 0;
}
*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	printf("bir karakter giriniz.\n");
	ch = getchar();

	if (isLower(ch))
		printf("kucuk harf..");
	else
		printf("kucuk harf degil..");

	return 0;
}
*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
int x = signum(-123);
printf("%d\n", x); // -1
x = signum(0);
printf("%d\n", x); // 0
x = signum(123);
printf("%d\n", x); // 1

return 0;
}
*/

