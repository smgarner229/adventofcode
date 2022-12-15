#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc_score(char opp, char my)
{
    int score = 0;
    // Get points for what I played
    switch(my)
    {
        case 'X':
        score+=1;
        break;
        
        case 'Y':
        score+=2;
        break;

        case 'Z':
        score+=3;
        break;

        default:
        break;
    }
    my-='X';
    opp-='A';
    int result = my-opp;
    switch(result)
    {
        case 0: // Draw
        return score+3;
        case 1: // Win (3-2) or (2-1)
        return score+6;
        case -2:// Win (1-3)
        return score+6;
        default:// Default to loss
        return score;

    }
}

int figure_out_my_input(char opp, char res)
{
    switch(res)
    {
        case 'Y': // Draw
        return calc_score(opp,opp-'A'+'X'); // Same input
        case 'X': // Loss
        if(opp=='A')
            return calc_score(opp,opp-'A'+'X'+2);
        else
            return calc_score(opp,opp-'A'+'X'-1);
        case 'Z': // Win
        if(opp=='C')
            return calc_score(opp,opp-'A'+'X'-2);
        else
            return calc_score(opp,opp-'A'+'X'+1);
    }
}

void play_strategy(int * strat1, int * strat2)
{
    FILE * fp = fopen("input.txt","r");
    char opp,my;
    while(fscanf(fp,"%c %c\n",&opp,&my)!=EOF)
    {
        *strat1+=calc_score(opp,my);
        *strat2+=figure_out_my_input(opp,my);
    }
    fclose(fp);
    return;
}

int main(int argc, char ** argv)
{
    int strat1 = 0;
    int strat2 = 0;
    play_strategy(&strat1,&strat2);
    printf("%d\n",strat1);
    printf("%d\n",strat2);
}
