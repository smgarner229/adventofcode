#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int prio(char * found)
{
    if(*found > 'a')
        return (int)(*found-'a'+1);
    return(int)(*found-'A'+27);
}

// l points to the start of the string,
// r points to the first element halfwya through
int get_score(const char * l, const char * r)
{
    char * found = NULL;
    for(;!found;found=index(r,(int)*l++)){}
    return prio(found);
}

int get_group(const char * a, const char * b, const char * c)
{
    char* found = NULL;
    // Common character between a and b
    for(found=index(b,(int)*a++);;found=index(b,(int)*a++))
    {
        if(found)
            // Check if it's in C, if so return
            if(found=index(c,(int)*found))
                return prio(found);
    }
    return 0;
}

int answer()
{
    char *sack = NULL;
    FILE*fp = fopen("input.txt","r");
    int total = 0;
    size_t zero = 0;
    while(getline(&sack,&zero,fp)!=EOF)
        total+=get_score(sack,sack+(strlen(sack))/2);
    free(sack);
    fclose(fp);
    return total;
}

int groups()
{
    char e1[MAX_LEN];
    char e2[MAX_LEN];
    char e3[MAX_LEN];
    FILE*fp = fopen("input.txt","r");
    int total = 0;
    while(fscanf(fp,"%s%s%s",e1,e2,e3)!=EOF)
        total+=get_group(e1,e2,e3);
    return total;

}

int main(int argc, char ** argv)
{
    printf("%d\n",answer());
    printf("%d\n",groups());
    return 0;
}
