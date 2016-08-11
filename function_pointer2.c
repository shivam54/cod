# include<stdio.h>
void calculate(int(*p)(int,int),int a,int b)
{
  int ans= p(a,b); printf("%d\n",ans);
}
int calc(int(*p)(int,int),int a,int b)
{
  return(p(a,b));
}

int sum(int a,int b)
{  return (a+b);}

int sub(int a,int b)
{  return (a-b);}



int main()
{
  int (*ptr)(int,int);
  ptr=sum;
  calculate(ptr,10,20);

  int (*pt[])(int,int)={sum,sub};    // pointer array containing sum,sub functions
 int as= calc(pt[1],12,10);
 printf("%d\n",as);
}
