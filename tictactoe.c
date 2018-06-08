/**************************Introduction to this program*********************************

This program is a game named Tic tac toe;
Made/cloned by Md.Masud karim;
E-mail: msmasud578@gmail.com;
Mobile: 01638-901140;
Time and date of making this program: Time: 5:52 AM Date: 26-05-2018

***************************Program should start from here******************************/
#include<stdio.h>
/*array to hold the cell status*/

char gameboard[3][3];
/*function prototypes*/
void drawboard();
int showresult (char ch);
int validateinput(int cell);
void turnplayer0(int* pCell);
void turnplayerx (int* pCell);
void getrowcol (int cell, int* px, int* py);

int main()
{
int x=0,
y=0,
row=0,
col=0,
selectedcell=0,
availablecell=9;
char startchar='1';
/*make all the cell numbered from 1 to 9*/

for(row=0;row<3; col++)

    for(col=0;col<3;col++)
        gameboard[row][col]=startchar++;
        /*now draw board with current*/
    drawboard();
    /*loop untill we've played all the cell*/
    while(availablecell>=0)
    {
        /*assume player one is x*/
        turnplayerx(&selectedcell);
        /*get row and column form the selected cell*/
        getrowcol(selectedcell,&x,&y);
        /*update gameboard array*/
        gameboard[x][y]='x';
        /*decrease available cell*/
        availablecell -=1;
        /*redraw game board with current
        data in game board[][] array*/
        drawboard();
        /*check whether player one is winner or not*/
        if(showresult('x')==1)
        {
            break;
        }
        else if(availablecell==0)
        {
            printf("\n Game Drawn");
            break;
        }
        /*assume player two is 0*/
        turnplayer0(&selectedcell);
        /*get row and column from the  selected cell*/
        getrowcol(selectedcell,&x,&y);
        /*update gameboard array*/
        gameboard[x][y]='O';
        /*decrease available cell*/
        availablecell -=1;
        /*redraw game board with current
        data in gameboard [][] array*/
        drawboard();
        /*check whether player two is winner or not*/
        if(showresult('O')==1)
        {
        break;
        }
        else if(availablecell==0)
        {
            printf("\n Game drawn");
            break;
        }
    }
return 0;
}
/*function to draw board with current
data in gameboard [][] array*/
void drawboard()
{
int i,j;
printf("\n TIC TAC TOE");
printf("\n Digits (1-9) indicates VALID cell number\n");

printf("\n %c | %c | %c",gameboard[0][0],
                        gameboard[0][1],
                        gameboard[0][2]);
                        printf("\n ---|---|---");
                        printf("\n %c | %c| %c",gameboard[1][0],
                                                gameboard[1][1],
                                                gameboard[1][2]);
                        printf("\n ---|---|---");
                        printf("\n %c | %c| %c\n",gameboard[2][0],
                                                  gameboard[2][1],
                                                  gameboard[2][2]);
}
/*function to make player o's move*/
void turnplayer0(int* pCell)
{
    int cell;
    /*loop until player select a valid cell
    NOTE: cells with digit are VALID cells*/
    do
    {
        printf("\nPlayer O,\n Select VALID cell number: ");
        scanf("%d",&cell);
    }while(0 == validateinput(cell));
    *pCell =cell;
}
/*function to make plaer x's move*/
void turnplayerx(int* pCell)
{
    int cell;
    do
    {
        printf("\nPlayer x,\n select VALID cell number: ");
        scanf("%d", &cell);
    } while(0== validateinput(cell));
    *pCell = cell;
}
/*function to calculate row and column
number from selected cell*/
void getrowcol(int cell,int* px, int*py)
{
    *px =(cell-1) /3;
    *py =(cell -1) %3;
}
/*function to check whether selecte cell is VALID
or not. If selected cell is already O or X,
or if it is not in 1-9, then return 0
to indicate INVALID selection*/
int validateinput(int cell)
{
    int row,col;
    /*if cell is less than 1 or
    greater than 9, then return false=0;*/
    if((cell<1)||(cell>9))
        return 0;
    /*if selected cell is already occupied
    then return false=0;*/
    getrowcol(cell,&row,&col);
    if(('O'== gameboard[row][col])||
        ('x'== gameboard[row][col]))

        {
            return 0;
        }
        return 1;
}
/*function to show the winner*/
int showresult(char ch)
{
    int status=0;
    /*check diagonal \*/
    if(gameboard[0][0]==ch &&
       gameboard[1][1] ==ch &&
       gameboard[2][2]==ch)
    {
        printf("\nPlayer %c is winner", ch);
    }
    /*check dianoal /*/
    else if (gameboard[0][2]==ch &&
             gameboard[1][1]==ch &&
             gameboard[2][0]==ch)
    {
        printf("\n player %c is winner",ch);
        status = 1;
    }
    /*check first row*/
    else if (gameboard[0][0]==ch &&
             gameboard[1][0]==ch&&
             gameboard[2][0]==ch)
    {
        printf("\nPlayer %c is winner",ch);
        status =1;
    }
    /*check second row*/
    else if (gameboard[1][0]==ch&&
             gameboard[1][1]==ch &&
             gameboard[1][2]==ch)
    {
        printf("\nPlayer %c is winner", ch);
        status=1;
    }
    /*check third row*/
    else if (gameboard[2][0]== ch &&
             gameboard[2][1]==ch &&
             gameboard[2][2]==ch)
    {
        printf("\nPlayer %c is winner",ch);
        status =1;
    }
    /*check first column*/
    else if (gameboard[0][0]==ch&&
             gameboard[0][1]==ch &&
             gameboard[0][2]==ch)
    {
        printf("\nPlayer %c is winner",ch);
        status =1;
    }
    /*check second column*/
    else if (gameboard[0][1]==ch&&
             gameboard[1][1]==ch&&
             gameboard[2][1]==ch)
    {
        printf("\nPlayer %c is winner",ch);
        status =1;
    }
    /*check third column*/
    else if (gameboard[0][2]==ch&&
             gameboard[1][2]==ch&&
             gameboard[2][2]==ch)
    {
        printf("\nPlayer %c is winner",ch);
        status=1;
    }
    return status;
}
