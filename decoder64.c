#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char b[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char decoded[1024]="";

void format( unsigned char in[], char decoded[] ) {
    unsigned char out[4];
    out[0] =in[0] <<2  | in[1] >>4;
    out[1] =  in[1]<<4 | in[2]>>2 ;
    out[2] =   in[2]<<6 | in[3]>>0 ;
    out[3] = '\0';
    strncat(decoded, out, sizeof(out));

}


char *decoder(char *str)
{
   
    unsigned char in[4];
    int j=0,i,len=0;
    decoded[0]='\0';
    int c,phase=0;
    char *p;
    while(str[j])
    {
         c=(int)(str[j]);
        if(c=='=')
        { format(in,decoded);break;}
        p=strchr(b,c);
        if(p) 
        {
          in[phase]=p-b;
          phase=(phase+1)%4;
         if(phase==0)
         { format(in,decoded);in[0]=in[1]=in[2]=in[3]=0;}
        }
     j++;
         
            
    }
  return decoded;
}





int main() {

    //unsigned char in[3];
    char *st1="dG9wY29kZXI=";
  char *st2;
  st2=malloc(1024);
   // gets(st1);
    //char decoded[1024]="";
    //scanf("%s",st1);
    st2=decoder(st1);
     printf("The string\n[%s]\ndecodes  as:\n[%s]\n", st1, st2);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

