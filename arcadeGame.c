#include<stdio.h>
#include<conio.h>
#include<time.h>
// #include<windows.h>

unsigned char i=1;
char option,head,legs;
void choosecharacter()
{
    choose:
    system("clear");
    printf("\t\t\t\t\t\t\t\t\tEnter full screen\n");
    printf("\t\t\t\t\t\t\t\t\tChoose your character-\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\tPress 1 for %c\n\t\t\t\t\t\t\t\t\t\t    %c\n\n\n",206,204);
    printf("\t\t\t\t\t\t\t\t\tPress 2 for %c\n\t\t\t\t\t\t\t\t\t\t    %c\n\n\n",178,178);
    printf("\t\t\t\t\t\t\t\t\tPress 3 for %c\n\t\t\t\t\t\t\t\t\t\t    %c\n\n\n",197,195);
    printf("\t\t\t\t\t\t\t\t\tPress 4 for custom character.\n");
    option=getch();
    switch(option)
    {
        case '1':
        head=206;
        legs=204;
        break;

        case '2':
        head=178;
        legs=178;
        break;

        case '3':
        head=197;
        legs=195;
        break;

        case '4':
        system("cls");
        printf("\t\t\t\t\t\t\t\t\tPress key for head: ");
        head=getch();
        printf("\n\t\t\t\t\t\t\t\t\tPress key for legs: ");
        legs=getch();
        break;

        default:
        printf("\t\t\t\t\t\t\t\t\tInvalid input...\n");
        printf("\t\t\t\t\t\t\t\t\tPress Space to choose again or any other key to exit: ");
        option=getch();
        if(option==32)
        {
            goto choose;
        }
        else
        {
            exit(0);
        }
    }
}
unsigned char random(unsigned char a,unsigned char b)
{
    unsigned char randomnum;
    srand(time(0));
    randomnum=(rand()%b)+1;
    while(randomnum<a)
    {
        randomnum=(rand()%b)+1;
    }
    return randomnum;
}
void ground()
{
    unsigned char j;
    switch(i)
    {
        case(0):
        for(unsigned char j=0;j<50;j++)
        {
            printf("%c%c%c",194,196,205);
        }
        break;
        case(1):
        for(unsigned char j=0;j<50;j++)
        {
            printf("%c%c%c",196,205,194);
        }
        break;
        case(2):
        for(unsigned char j=0;j<50;j++)
        {
            printf("%c%c%c",205,194,196);
        }
        break;
        default:
        for(unsigned char j=0;j<50;j++)
        {
            printf("%c%c%c",205,194,196);
        }
    }
    i++;
    if(i>2)
    {
        i=0;
    }
}
void start()
{
    system("cls");
    printf("\n\n\n\n");
    printf("Press any key to start...");
    getch();
    system("cls");
    printf("\n\n\n\n\n\t3");
    Sleep(1000);
    printf("%c",8);
    printf("2");
    Sleep(1000);
    printf("%c",8);
    printf("1");
    Sleep(1000);
}

int main()
{
unsigned int score=0;
char keyboard=0;
short heat=0;
unsigned short star[3],j,k=0;//star means enemy
choosecharacter();

start:
start();
while(1)
{
    star[k]=random(50,100);
    while(star[k]>0 || heat<10)
    {
        system("cls");
        printf("\n\n\n\n\nPress Space key to jump\t\t\t\t\t\t\tScore=%d\n\n\n\n\n",score);

        if(kbhit())
        {
            keyboard=getch();
            fflush(stdin);
        }
        if(heat>=10)
        {
            //yes air and no control
            if(star[k]==1)
            {
                printf("\t%c\n\t%c\n\t%c\n\t%c",head,legs,176,177);
            }
            else
            {
                printf("\t%c\n\t%c\n\t \n\t ",head,legs);
            }
        }
        else if(heat<10)
        {
            //no air and no control
            printf("\t \n\t \n\t%c\n\t%c",head,legs);
        }
        if(heat==0)
        {
            //no air and yes control
            if(keyboard==32)
            {
                heat=20;
            }
        }

        for(unsigned short int j=star[k];j>1;j--)
        {
            printf(" ");
        }
        printf("*\n");
        ground();
        Sleep(20);
        if(star[k]==0 && heat<10)//You died
        {
            FILE *scores=fopen("arcadeGame.txt","a");
            fprintf(scores,"%d",score);
            fputs("\n",scores);
            fclose(scores);
            printf("\n\n\n\t\t\t\t\t\t\t\t\tYou died!\nPress Space to restart or any other key to exit: ");
            option=getch();
            switch(option)
            {
                case 32:
                goto start;
                break;
                default:
                exit(0);
            }
        }
        keyboard=0;
        heat--;
        score++;
        star[k]--;
        if(heat<0)
        {
            heat=0;
        }
    }
    k++;
    if(k>2)
    {
        k=0;
    }
}
return 0;
}