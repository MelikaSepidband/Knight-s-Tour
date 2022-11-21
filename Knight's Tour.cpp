#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void arzesh(int a[8][8])
{
	a[0][0]=a[0][7]=a[7][0]=a[7][7]=2;
    a[1][0]=a[0][1]=a[0][6]=a[1][7]=a[6][7]=a[7][6]=a[7][1]=a[6][0]=3;
    a[2][0]=a[3][0]=a[4][0]=a[5][0]=a[6][1]=a[7][2]=a[7][3]=a[7][4]=a[7][5]=a[6][6]=a[5][7]=a[4][7]=a[3][7]=a[2][7]=a[1][6]=a[0][5]=a[0][5]=a[0][4]=a[0][3]=a[0][2]=a[1][1]=4;
    a[1][2]=a[1][3]=a[1][4]=a[1][5]=a[2][1]=a[2][6]=a[3][1]=a[3][6]=a[4][1]=a[4][6]=a[5][1]=a[5][6]=a[6][2]=a[6][3]=a[6][4]=a[6][5]=6;
    a[2][2]=a[2][3]=a[2][4]=a[2][5]=a[3][2]=a[3][3]=a[3][4]=a[3][5]=a[4][2]=a[4][3]=a[4][4]=a[4][5]=a[5][2]=a[5][3]=a[5][4]=a[5][5]=8;
}
 int check(int a[8][8],int row,int column)
 {
 int randbox[8];
 int ofoghi[8]={2,1,-1,-2,-2,-1,1,2};
 int amoodi[8]={-1,-2,-2,-1,1,2,2,1};
 int action[8];
 int i;
 for(i=0;i<8;i++)
 {
     if(row+amoodi[i]>=0 && row+amoodi[i]<=7 && column+ofoghi[i]>=0 && column+ofoghi[i]<=7 && a[row+amoodi[i]][column+ofoghi[i]]!=0)
     {
          action[i]=a[row+amoodi[i]][column+ofoghi[i]];
     }
     else
     {
         action[i]=9;
     }
 }
 
     int min=10;
     int count=0;
     for(i=0;i<8;i++)
     {
         if(min>=action[i])
         {
             min=action[i];
         }
     }
     if(min==9)
     {
         return -1;
     }
     int j=0;
      for(i=0;i<8;i++)
     {
         if(min==action[i])
         {
             randbox[j]=i;
             j++;
             count++;
         }
     }
 
     int r=rand()%count;
     return (randbox[r]);
 
 }
int fill(int a[8][8],int b[64],int c[64],int row,int column)
{
 int m=1;
 a[row][column]=0;
 b[0]=row;
 c[0]=column;
 int ofoghi[8]={2,1,-1,-2,-2,-1,1,2};
 int amoodi[8]={-1,-2,-2,-1,1,2,2,1};
 for(int k=0;k<64;k++)
 {
 if(k==63)
 {
     return 0;
 }
 
 int i=check(a,row,column);
 if(i!=-1)
 {
 
     column+=ofoghi[i];
     row+=amoodi[i];
     a[row][column]=0;
     b[m]=row;
     c[m]=column;
     m++;
 }
 else
 {
    return 1;
 }
}
return 0;
}
void print(int a[8][8])
{
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                printf("%d\t ",a[i][j]);
            }
            printf("\n");
        }
}
int main()
{
  int n;
  int a[8][8];
  int b[64]={0};
  int c[64]={0};
  srand(time(NULL));
  arzesh(a);
  int row,column;
  printf("Inter row number that knight is in it");
  scanf("%d",&row);
  printf("Inter column number that knight is in it");
  scanf("%d",&column);
  printf("\n");
     do
     {
                arzesh(a);
                n=fill(a,b,c,row,column);
     }
     while(n==1);
 
  for(int i=0;i<=63;i++)
  {
    a[b[i]][c[i]]=i;
  }
print(a);
return 0;
}
