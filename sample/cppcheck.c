#include "controls.h"
#include "cppcheck.h"
#include "stdafx.h"

void convertStrToBcd(u8 *src, int len, u8 *dest, int RL)
{
    int i = 0;//,strLen = strlen((char *)src);
    //strLen = strLen>len*2?len*2:strLen;
    memset(dest, 0, len / 2);
    if(RL == 1)
    {
        for(i = 0; i < len; i++)
        {
            //*(dest+(i/2)) = i%2!=0 ? ((*((u8 *)(src+i)) - 0x30) & 0x0F)|(*(dest+(i/2))) : (((*((u8 *)(src+i)) - 0x30) & 0x0F)<<4);
            if(i % 2 != 0)
            {
                if(*(u8 *)(src + i) > (u8)0x40)
                {
                    *(dest + (i / 2)) = ((*((u8 *)(src + i)) - 0x40 + 9) & 0x0F) | (*(dest + (i / 2)));
                }
                else
                {
                    *(dest + (i / 2)) = ((*((u8 *)(src + i)) - 0x30) & 0x0F) | (*(dest + (i / 2)));
                }
            }
            else
            {
                if(*(u8 *)(src + i) > (u8)0x40)
                {
                    *(dest + (i / 2)) = (((*((u8 *)(src + i)) - 0x40 + 9) & 0x0F) << 4);
                }
                else
                {
                    *(dest + (i / 2)) = (((*((u8 *)(src + i)) - 0x30) & 0x0F) << 4);
                }
            }
        }
    }
    else if(RL == 0)
    {
        len --;
        for(i = 1; i <= len; i++)
        {
            *(dest + (len)) = i % 2 != 0 ? ((*((u8 *)(src + (len - i))) - 0x30) & 0x0F) : (((*((u8 *)(src + (len - i))) - 0x30) & 0x0F) << 4) | (*(dest + (len--)));
        }
    }
}