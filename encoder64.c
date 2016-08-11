#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char b[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";



void format( unsigned char in[], char encoded[], int len ) {
    unsigned char out[5];
    out[0] = b[ in[0] >> 2 ];
    out[1] = b[ ((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4) ];
    out[2] = (unsigned char) (len > 1 ? b[ ((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6) ] : '=');
    out[3] = (unsigned char) (len > 2 ? b[ in[2] & 0x3f ] : '=');
    out[4] = '\0';
    strncat(encoded, out, sizeof(out));

}


void encoder(char *str,char *encoded)
{
    unsigned char in[3];
    int j=0,i,len=0;
    encoded[0]='\0';
    while(str[j])
    {
         len=0;
        for( i=0;i<3;i++)
        {
            in[i]=(unsigned char)str[j];
            if(str[j])
            {j++;len++;}
            else in[i]=0;
        }
        if(len)
        { format(in,encoded,len);}
            
    }
}





int main() {

    //unsigned char in[3];
    char st1[10];
    gets(st1);
    char encoded[1024]="";
    //scanf("%s",st1);
    encoder(st1,encoded);
     printf("The string\n[%s]\nencodes into base64 as:\n[%s]\n", st1, encoded);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

