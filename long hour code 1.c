#include<stdio.h>
main()
{
int i,t,x,u,f,sum=0;
int a[4];

scanf("%d",&u);

for(t=1;t<=u;t++)
{

sum=0;
scanf("%d %d",&x,&f);

int c[x];
int b[x];



  for(i=0;i<x;i++)
 {

 scanf("%d",&b[i]);


 }
 // printf("\n");
   for(i=0;i<x;i++)
 {

scanf("%d",&c[i]);

 }

  for(i=0;i<x;i++)
  {
      if(b[i]>=f)
      {
          sum=sum+c[i];
      }
      a[t]=sum;
  }

}
 printf("\n");
for(t=1;t<=u;t++)
{
    printf("%d\n",a[t]);
}

}
