#ifndef _CONTROLS_H
#define _CONTROLS_H

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

char isLower (char ch);
char isAlphabetic (char ch);
char isDigit (char ch);
char isAlphaNumeric (char ch);
char isHexDigit (char ch);
char toLower(char ch);
char toUpper(char ch);
void capitalize(char *sentence);
char toDecimal(char ch);
char toHex(char number);

unsigned long long UTL_pow(unsigned short x, unsigned short y);
u64 UTL_Bcd2Lng(u8 *in, u8 inLength);
u64 UTL_Bcd2Int(u8 *in, u8 inLength);
u8 UTL_Byte2Bcd(u8 b);

#endif // _CONTROLS_H