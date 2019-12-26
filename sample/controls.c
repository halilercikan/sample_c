#include "controls.h"

char isLower (char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch;
	return 0;
}

char isAlphabetic (char ch)
{
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		return ch;
	return 0;
}

char isDigit (char ch)
{
	return ch >= '0' && ch <= '9';
}

char isAlphaNumeric (char ch)
{
	return isAlphabetic(ch) || isDigit(ch);
}

char isHexDigit (char ch)
{
	return ch >= '0' && ch <= '9' || 
		ch >= 'a' && ch <= 'f' || 
		ch >= 'A' && ch <= 'F';
}

char toLower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 'a';
	return ch;
}

char toUpper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - 'a' + 'A';
	return ch;
}

void capitalize(char *sentence)
{
	int i = 0;
	char ch = 0;

	sentence[i++] = toUpper(sentence[i]);	
	do
	{						
		if (sentence[i-1] == 0x20) // space character
			sentence[i++] = toUpper(sentence[i]);
		else
			sentence[i++] = toLower(sentence[i]);		
	} while (sentence[i] != 0);	// end character
}

char toDecimal(char ch)
{
	ch = toUpper(ch);
	if (isDigit(ch))
		return ch - '0';
	if (ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 10;
	return -1;
}

char toHex(char number)
{
	if (number >= 0 && number <= 9)
		return ('0' + number);
	if (number >= 10 && number <= 15)
		return ('A' + number - 10);
	return -1;
}

unsigned long long UTL_pow(unsigned short x, unsigned short y)
{
    unsigned long long t = 1;
	unsigned short i = 0;

    if (0 != y)
    {		
		for (i = 0; i < y; i++)
		{
			t = (t * x);
		}
    }

    return t;
}

u64 UTL_Bcd2Lng(u8 *in, u8 inLength)
{
    u64 Lng;
    u32 i, j;
    u8 FrstNibble;
    u8 ScndNibble;

    if (inLength > 10)
		return (u64) - 1;
    if (inLength == 10) {
        if (in[0] > 0x17)
            return (u64) - 1;
    }
    Lng = 0;
	for (i = inLength; i > 0; i--) {
        
		FrstNibble = in[i-1] & 0x0F;
        ScndNibble = in[i-1] >> 4;
		Lng += (FrstNibble) * UTL_pow(10, 2 * (inLength - i));
        Lng += (ScndNibble) * UTL_pow(10, (2 * (inLength - i)) + 1);
    }
    return Lng;
}

u64 UTL_Bcd2Int(u8 *in, u8 inLength)
{
    u64 ret = 0;

    if (inLength > 10)
		return (u64) - 1;
    if (inLength == 10) {
        if (in[0] > 0x17)
            return (u64) - 1;
    }

    while(inLength--)
    {
        ret = (ret * 100) + (((*in >> 4) & 0x0F) * 10) + (*in & 0x0F);
        in++;
    }

    return ret;
}

u8 UTL_Byte2Bcd(u8 b)
{
    return ((b / 10) << 4) | (b % 10);
}