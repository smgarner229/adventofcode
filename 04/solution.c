#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int a,b,c,d;
    FILE *fp = fopen("input.txt","r");
    while(fscanf(fp,"%d-%d,%d-%d\n",&a,&b,&c,&d)!=EOF)
    {
        printf("%d\t%d\t%d\t%d\n",a,b,c,d);
    }
    return 0;
}
