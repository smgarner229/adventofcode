#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELVES 10000
int elves[MAX_ELVES];
size_t cur_elves=0;

int comp_ints(const void * a, const void * b)
{
    return *(int*)a-*(int*)b;
}

void load_elves()
{
    FILE * fp = fopen("input.txt","r");
    size_t max_line = 5000;
    char *next_line = NULL;
    int cals = 0;
    while(getline(&next_line,&max_line,fp)!=EOF)
    {
        // New line means store the last elf
        if(!strcmp(next_line,"\n"))
        {
            elves[cur_elves++]=cals;
            cals=0;
        }
        // Otherwise continuing to add to one stack
        else
        {
            cals+=atoi(next_line);
        }
    }
    elves[cur_elves++]=cals;
    free(next_line);
    fclose(fp);
    return;
}

int top_three()
{
    return elves[cur_elves-1]+elves[cur_elves-2]+elves[cur_elves-3];
}

int main(int argc, char ** argv)
{
    load_elves();
    qsort((void*)elves,cur_elves,sizeof(int),comp_ints);
    printf("The elf with the max calories has: %d\n",elves[cur_elves-1]);
    printf("The top three elves have : %d\n",top_three());

    return EXIT_SUCCESS;
}
