#include <stdio.h>
 
#define LEN 10
int a[LEN]={12,98,43,34,66,3,89,3,6,90};
 
int line_search(int x)
{
        int i=0,location=0;
 
        while(i<LEN && x!=a[i])
                i=i+1;
        if(i<LEN)
                location=i+1;
        else
                location=0;
        printf("Num:%d in a[10] :%d subscript\n",x,location);
}
 
int main(void)
{
        int x=89;
        line_search(x);
        return 0;
}