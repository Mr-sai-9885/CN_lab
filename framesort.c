#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct frame
{
    int fno;
    int finfo[30];
}f[30];
int n;
int main()
{
    int i,j;
    printf("enter the no of frames : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        f[i].fno=rand() % 50;
        printf("enter the frame sequance %d : ",f[i].fno);
        scanf("%d",&f[i].finfo);

    }
    sort();
    printf("frames \t sequance :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d",f[i].fno,f[i].finfo);
    }
    return 0;
}
void sort()
{
    int i,j;
    struct frame temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(f[j].fno > f[j+1].fno)
            {
                temp = f[j];
                f[j]= f[j+1];
                f[j+1]=temp;
            }
        }
    }
}
