#include<stdio.h>

#include<windows.h>

#include<conio.h>

#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75

#define KEY_RIGHT 77

int arr[3][3];

void gotoxy(int x , int y)
{
    COORD point ;

    point.X = x ;

    point.Y = y ;

    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , point );
}


void putArr( int myX , int myY , int *tempX , int *tempY , int *X , int *Y ){

    int x = myX - *tempX ;

    int y = myY - *tempY ;

    *X = *X + y * 5 ;

    *Y = *Y + x*2 ;

    *tempX = myX;

    *tempY = myY;

    arr[myX][myY] = 0;

    gotoxy(0,0);

    printf("Computer is Thinking.........");

    for(int i=0; i<100000000; i++);

    gotoxy(*X,*Y);

    printf("0");
}



int find(int tempX,int tempY,int *x,int *y){

    if(tempX==0&&tempY==0){

        if(arr[0][0]+arr[0][1]+arr[0][2]==7){

            if(arr[0][1]==5){

                *x=0; *y=1; return 1;
            }

            else{ *x=0; *y=2; return 1;}
        }

        if(arr[0][0]+arr[1][0]+arr[2][0]==7){

            if(arr[1][0]==5){

                *x=1; *y=0; return 1;
            }

            else{ *x=2; *y=0; return 1;}
        }

        if(arr[0][0]+arr[1][1]+arr[2][2]==7){

            if(arr[1][1]==5){

                *x=1; *y=1; return 1;
            }

            else{ *x=2; *y=2; return 1;}
        }
    }

    if(tempX==0&&tempY==2){

        if(arr[0][2]+arr[0][1]+arr[0][0]==7){

            if(arr[0][1]==5){

                *x=0; *y=1; return 1;
            }

            else{ *x=0; *y=0; return 1;}
        }

        if(arr[0][2]+arr[1][2]+arr[2][2]==7){

            if(arr[1][2]==5){

                *x=1; *y=2; return 1;
            }

            else{ *x=2; *y=2; return 1;}
        }

        if(arr[0][2]+arr[1][1]+arr[2][0]==7){

            if(arr[1][1]==5){

                *x=1; *y=1; return 1;
            }

            else{ *x=2; *y=0; return 1;}
        }

    }



    if(tempX==2&&tempY==0){

        if(arr[2][0]+arr[1][0]+arr[0][0]==7){

            if(arr[1][0]==5){

                *x=1; *y=0; return 1;
            }

            else{ *x=0; *y=0; return 1;}
        }

        if(arr[2][0]+arr[2][1]+arr[2][2]==7){

            if(arr[2][1]==5){

                *x=2; *y=1; return 1;
            }

            else{ *x=2; *y=2; return 1;}
        }

        if(arr[2][0]+arr[1][1]+arr[0][2]==7){

            if(arr[1][1]==5){

                *x=1; *y=1; return 1;
            }

            else{ *x=0; *y=2; return 1;}
        }
    }


    if(tempX==2&&tempY==2){

        if( arr[2][2] + arr[1][2] + arr[0][2] == 7 ){

            if(arr[1][2]==5){

                *x=1; *y=2; return 1;
            }

            else{ *x=0; *y=2; return 1;}
        }

        if(arr[2][2]+arr[2][1]+arr[2][0]==7){

            if(arr[2][1]==5){

                *x=2; *y=1; return 1;
            }

            else{ *x=2; *y=0; return 1;}
        }

        if(arr[2][2]+arr[1][1]+arr[0][0]==7){

            if(arr[1][1]==5){

                *x=1; *y=1; return 1;
            }

            else{ *x=0; *y=0; return 1;}
        }
    }



    if(tempX==0&&tempY==1){

        if(arr[0][1]+arr[1][1]+arr[2][1]==7){

            if(arr[1][1]==5){

                *x=1; *y=1; return 1;
            }

            else { *x=2; *y=1; return 1;}
        }

        if(arr[0][1]+arr[0][0]+arr[0][2]==7){

            if(arr[0][0]==5){

                *x=0; *y=0; return 1;
            }

            else{ *x=0; *y=2; return 1;}
        }
    }



    if(tempX==1&&tempY==0){

        if(arr[1][0]+arr[1][1]+arr[1][2]==7){

            if(arr[1][1]==5){

                *x=1; *y=1; return 1;

            }

            else { *x=1; *y=2; return 1;}

        }

        if(arr[1][0]+arr[0][0]+arr[2][0]==7){

            if(arr[0][0]==5){

                *x=0; *y=0; return 1;

            }

            else{ *x=2; *y=0; return 1;}

        }

    }



    if(tempX==1&&tempY==2){

        if(arr[1][2]+arr[1][1]+arr[1][0]==7){

            if(arr[1][1]==5){

                *x=1; *y=1; return 1;
            }

            else { *x=1; *y=0; return 1;}
        }

        if(arr[1][2]+arr[0][2]+arr[2][2]==7){

            if(arr[0][2]==5){

                *x=0; *y=2; return 1;
            }

            else{ *x=2; *y=2; return 1;}
        }
    }



    if(tempX==2&&tempY==1){

        if(arr[2][1]+arr[1][1]+arr[0][1]==7){

            if(arr[1][1]==5){

                *x=1; *y=1; return 1;

            }

            else { *x=0; *y=1; return 1;}

        }

        if(arr[2][1]+arr[2][0]+arr[2][2]==7){

            if(arr[2][0]==5){

                *x=2; *y=0; return 1;

            }

            else{ *x=2; *y=2; return 1;}

        }

    }

    return 0;
}




int findWin(int *x,int *y){

    if(arr[0][0]+arr[0][1]+arr[0][2]==5){

        if(arr[0][0]==5){

            *x=0; *y=0; return 1;

        }
        if(arr[0][1]==5){

            *x=0; *y=1; return 1;

        }

        else{ *x=0; *y=2; return 1;}

    }



    if(arr[1][0]+arr[1][1]+arr[1][2]==5){

        if(arr[1][0]==5){

            *x=1; *y=0; return 1;

        }

        if(arr[1][1]==5){

            *x=1; *y=1; return 1;

        }

        else{ *x=1; *y=2; return 1;}

    }



    if(arr[2][0]+arr[2][1]+arr[2][2]==5){

        if(arr[2][0]==5){

            *x=2; *y=0; return 1;

        }

        if(arr[2][1]==5){

            *x=2; *y=1; return 1;

        }

        else{ *x=2; *y=2; return 1;}

    }



    if(arr[0][0]+arr[1][0]+arr[2][0]==5){

        if(arr[0][0]==5){

            *x=0; *y=0; return 1;

        }

        if(arr[1][0]==5){

            *x=1; *y=0; return 1;

        }

        else{ *x=2; *y=0; return 1;}

    }



    if(arr[0][1]+arr[1][1]+arr[2][1]==5){

        if(arr[0][1]==5){

            *x=0; *y=1; return 1;

        }

        if(arr[1][1]==5){

            *x=1; *y=1; return 1;

        }

        else{ *x=2; *y=1; return 1;}

    }



    if(arr[0][2]+arr[1][2]+arr[2][2]==5){

        if(arr[0][2]==5){

            *x=0; *y=2; return 1;

        }

        if(arr[1][2]==5){

            *x=1; *y=2; return 1;

        }

        else{ *x=2; *y=2; return 1;}

    }



    if(arr[0][0]+arr[1][1]+arr[2][2]==5){

        if(arr[0][0]==5){

            *x=0; *y=0; return 1;

        }

        if(arr[1][1]==5){

            *x=1; *y=1; return 1;

        }

        else{ *x=2; *y=2; return 1;}

    }



    if(arr[0][2]+arr[1][1]+arr[2][0]==5){

        if(arr[0][2]==5){

            *x=0; *y=2; return 1;

        }

        if(arr[1][1]==5){

            *x=1; *y=1; return 1;

        }

        else{ *x=2; *y=0; return 1;}

    }

    else return 0;
}




void putAny(int *tempX,int *tempY,int *x,int *y){

    if(arr[1][1]==5)

        putArr(1,1,tempX,tempY,x,y);

    else if(arr[0][0]==5)

        putArr(0,0,tempX,tempY,x,y);

    else if(arr[0][1]==5)

        putArr(0,1,tempX,tempY,x,y);

    else if(arr[0][2]==5)

        putArr(0,2,tempX,tempY,x,y);

    else if(arr[1][0]==5)

        putArr(1,0,tempX,tempY,x,y);

    else if(arr[1][2]==5)

        putArr(1,2,tempX,tempY,x,y);

    else if(arr[2][0]==5)

        putArr(2,0,tempX,tempY,x,y);

    else if(arr[2][1]==5)

        putArr(2,1,tempX,tempY,x,y);

    else if(arr[2][2]==5)

        putArr(2,2,tempX,tempY,x,y);


}



int find_user_win1(int tempX,int tempY){

    if(tempX==0&&tempY==0){

        if((arr[0][0]+arr[0][1]+arr[0][2]==0)||(arr[0][0]+arr[1][0]+arr[2][0]==0)||(arr[0][0]+arr[1][1]+arr[2][2]==0))

            return 1;

        else return 0;

    }

    if(tempX==0&&tempY==2){

        if((arr[0][2]+arr[0][1]+arr[0][0]==0)||(arr[0][2]+arr[1][2]+arr[2][2]==0)||(arr[0][2]+arr[1][1]+arr[2][0]==0))

            return 1;

        else return 0;
    }

    if(tempX==2&&tempY==0){

        if((arr[2][0]+arr[1][0]+arr[0][0]==0)||(arr[2][0]+arr[2][1]+arr[2][2]==0)||(arr[2][0]+arr[1][1]+arr[0][2]==0))

            return 1;

        else return 0;

    }

    if(tempX==2&&tempY==2){

        if((arr[2][2]+arr[1][2]+arr[0][2]==0)||(arr[2][2]+arr[2][1]+arr[2][0]==0)||(arr[2][2]+arr[1][1]+arr[0][0]==0))

            return 1;

        else return 0;

    }

    if(tempX==0&&tempY==1){

        if((arr[0][1]+arr[1][1]+arr[2][1]==0)||(arr[0][1]+arr[0][0]+arr[0][2]==0))

            return 1;

        else return 0;

    }

    if(tempX==1&&tempY==0){

        if((arr[1][0]+arr[1][1]+arr[1][2]==0)||(arr[1][0]+arr[0][0]+arr[2][0]==0))

            return 1;

        else return 0;

    }

    if(tempX==1&&tempY==2){

        if((arr[1][2]+arr[1][1]+arr[1][0]==0)||(arr[1][2]+arr[0][2]+arr[2][2]==0))

            return 1;

        else return 0;

    }

    if(tempX==2&&tempY==1){

        if((arr[2][1]+arr[1][1]+arr[0][1]==0)||(arr[2][1]+arr[2][0]+arr[2][2]==0))

            return 1;

        else return 0;

    }

    if(tempX==1&&tempY==1){

        if((arr[1][2]+arr[1][1]+arr[1][0]==0)||(arr[0][1]+arr[1][1]+arr[2][1]==0)||(arr[2][2]+arr[1][1]+arr[0][0]==0)||(arr[2][0]+arr[1][1]+arr[0][2]==0))

            return 1;

        else return 0;

    }
}




int find_user_win2(int tempX,int tempY){

    if(tempX==0&&tempY==0){

        if((arr[0][0]+arr[0][1]+arr[0][2]==3)||(arr[0][0]+arr[1][0]+arr[2][0]==3)||(arr[0][0]+arr[1][1]+arr[2][2]==3))

            return 1;

        else return 0;

    }

    if(tempX==0&&tempY==2){

        if((arr[0][2]+arr[0][1]+arr[0][0]==3)||(arr[0][2]+arr[1][2]+arr[2][2]==3)||(arr[0][2]+arr[1][1]+arr[2][0]==3))

            return 1;

        else return 0;

    }

    if(tempX==2&&tempY==0){

        if((arr[2][0]+arr[1][0]+arr[0][0]==3)||(arr[2][0]+arr[2][1]+arr[2][2]==3)||(arr[2][0]+arr[1][1]+arr[0][2]==3))

            return 1;

        else return 0;

    }

    if(tempX==2&&tempY==2){

        if((arr[2][2]+arr[1][2]+arr[0][2]==3)||(arr[2][2]+arr[2][1]+arr[2][0]==3)||(arr[2][2]+arr[1][1]+arr[0][0]==3))

            return 1;

        else return 0;

    }

    if(tempX==0&&tempY==1){

        if((arr[0][1]+arr[1][1]+arr[2][1]==3)||(arr[0][1]+arr[0][0]+arr[0][2]==3))

            return 1;

        else return 0;
    }

    if(tempX==1&&tempY==0){

        if((arr[1][0]+arr[1][1]+arr[1][2]==3)||(arr[1][0]+arr[0][0]+arr[2][0]==3))

            return 1;

        else return 0;

    }

    if(tempX==1&&tempY==2){

        if((arr[1][2]+arr[1][1]+arr[1][0]==3)||(arr[1][2]+arr[0][2]+arr[2][2]==3))

            return 1;

        else return 0;

    }

    if(tempX==2&&tempY==1){

        if((arr[2][1]+arr[1][1]+arr[0][1]==3)||(arr[2][1]+arr[2][0]+arr[2][2]==3))

            return 1;

        else return 0;

    }

    if(tempX==1&&tempY==1){

        if((arr[1][2]+arr[1][1]+arr[1][0]==3)||(arr[0][1]+arr[1][1]+arr[2][1]==3)||(arr[2][2]+arr[1][1]+arr[0][0]==3)||(arr[2][0]+arr[1][1]+arr[0][2]==3))

            return 1;

        else return 0;
    }
}




int haveCom2Way(int *x,int *y){

    if(arr[0][0]==5&&(((arr[0][1]+arr[0][2]==5)&&(arr[1][1]+arr[2][2]==5))||((arr[0][1]+arr[0][2]==5)&&(arr[1][0]+arr[2][0]==5))||((arr[1][0]+arr[2][0]==5)&&(arr[1][1]+arr[2][2]==5)))){

        *x=0; *y=0;

        return 1;

    }

    if(arr[0][2]==5&&(((arr[0][1]+arr[0][0]==5)&&(arr[1][1]+arr[2][0]==5))||((arr[0][1]+arr[0][0]==5)&&(arr[1][2]+arr[2][2]==5))||((arr[1][2]+arr[2][2]==5)&&(arr[1][1]+arr[2][0]==5)))){

         *x=0; *y=2;

         return 1;

    }

    if(arr[2][0]==5&&(((arr[0][0]+arr[1][0]==5)&&(arr[1][1]+arr[0][2]==5))||((arr[2][1]+arr[2][2]==5)&&(arr[1][1]+arr[0][2]==5))||((arr[2][1]+arr[2][2]==5)&&(arr[0][0]+arr[1][0]==5)))){

        *x=2; *y=0;

        return 1;

    }

    if(arr[2][2]==5&&(((arr[1][2]+arr[0][2]==5)&&(arr[0][0]+arr[1][1]==5))||((arr[2][0]+arr[2][1]==5)&&(arr[0][0]+arr[1][1]==5))||((arr[2][0]+arr[2][1]==5)&&(arr[1][2]+arr[0][2]==5)))){

        *x=2; *y=2;

        return 1;

    }

    return 0;

}



int main(){

    printf("%30cWELCOME TO THE WORLD OF TIK TOK TOE\n\n%40cLOADING..........\n%30c",' ',' ',' ');



    for(int i=0; i<35; i++){

        printf("%c",177);

        for(int j=0; j<=10000000; j++);

    }



    for(int i=0; i<=10000000; i++);

    printf("\n\n%30cEnter Any Key To Continue...........",' ');

    getch();

    system("cls");

    printf("\n\n\n%30c1.User Mode\n%30c2.Computer Mode\n\n%30cEnter Your Choice.......",' ',' ',' ');

    char mode,choice;

    while(1){

        mode=getch();

        if(mode=='1'||mode=='2')

            break;

        else printf("\a");

    }



    char name1[20],name2[20];

    if(mode=='1'){

        system("cls");

        printf("\n\n%30cEnter The First User Name And Press Enter: ",' ');

            gets(name1);

        printf("\n%30cEnter The Second User Name And Press Enter: ",' ');

            gets(name2);

    }

    else if(mode=='2'){

        system("cls");

        printf("\n\n%30cEnter Your Name And Press Enter: ",' ');

            gets(name1);

    }

    int com_score=0,you_score=0,u1_score=0,u2_score=0,draw=0;

    while(1){

        system("cls");

        if(mode=='1'){

            printf("%10c1: %s Will Give The First Move\n%10c2: %s will Give The First Move\n\n%10cEnter Your Choice.......",' ',name1,' ',name2,' ');

            while(1){

                choice=getch();

                if(choice=='1'||choice=='2')

                    break;

                else printf("\a");

            }

            system("cls");

            for(int i=0; i<3; i++)

                for(int j=0; j<3; j++)

                    arr[i][j]=5;

            int U1,U2;

            if(choice=='1'){

                printf("%s Give Your Move With 0.....",name1);

                U1=1; U2=0;

            }

            else if(choice=='2'){

                printf("%s Give Your Move With 1.....",name2);

                U1=0; U2=1;

            }

            printf("\n\n          |   |   \n     _____|___|_____   \n          |   |   \n     _____|___|_____   \n          |   |   \n          |   |   ");

            gotoxy(46,4);

            printf(" %s    %s    Draw",name1,name2);

            gotoxy(40,6);

            printf("Score:    %d        %d      %d",u1_score,u2_score,draw);

            int x=7,y=2;

            gotoxy(x,y);

            char c,input;

            int tempX=0,tempY=0;

            int record=-1;

            while(1){

                c=getch();

                if(c=='1'){

                    if(arr[tempX][tempY]==5&&U2==1){

                        printf("%c",c);

                        gotoxy(0,0);

                        printf("%s Give Your Move With 0......",name1);

                        gotoxy(x,y);

                        arr[tempX][tempY]=1;



                        if(find_user_win2(tempX,tempY)){

                            record=2;

                            break;

                        }



                        U1=1; U2=0;

                        if(!(arr[0][0]==5||arr[0][1]==5||arr[0][2]==5||arr[1][0]==5||arr[1][1]==5||arr[1][2]==5||arr[2][0]==5||arr[2][1]==5||arr[2][2]==5))

                            break;
                    }


                    else{

                        printf("\a");

                    }
                }


                else if(c=='0'){

                    if(arr[tempX][tempY]==5&&U1==1){

                        printf("%c",c);

                        gotoxy(0,0);

                        printf("%s Give Your Move With 1......",name2);

                        gotoxy(x,y);

                        arr[tempX][tempY]=0;



                        if(find_user_win1(tempX,tempY)){
                            record=1;

                            break;

                        }



                        U1=0; U2=1;

                        if(!(arr[0][0]==5||arr[0][1]==5||arr[0][2]==5||arr[1][0]==5||arr[1][1]==5||arr[1][2]==5||arr[2][0]==5||arr[2][1]==5||arr[2][2]==5))

                            break;
                    }


                    else{

                        printf("\a");

                    }
                }





                else{

                    switch(c){

                        case KEY_UP:tempX--;

                                    if(tempX>=0){

                                        y=y-2;

                                        gotoxy(x,y);

                                    }

                                    else{

                                        printf("\a");

                                        tempX++;

                                    }

                                    break;


                        case KEY_DOWN:  tempX++;

                                        if(tempX<=2){

                                            y=y+2;

                                            gotoxy(x,y);
                                        }


                                        else{

                                            printf("\a");



                                            tempX--;

                                        }

                                        break;


                        case KEY_LEFT:  tempY--;

                                        if(tempY>=0){

                                            x=x-5;

                                            gotoxy(x,y);

                                        }

                                        else{

                                            printf("\a");

                                            tempY++;

                                        }

                                        break;


                        case KEY_RIGHT: tempY++;

                                        if(tempY<=2){

                                            x=x+5;

                                            gotoxy(x,y);

                                        }

                                        else{

                                            printf("\a");

                                            tempY--;

                                        }

                                        break;
                        }
                }

            }


            printf("\a");

            gotoxy(0,0);

            printf("Game Over.............                 ");

            gotoxy(0,9);

            if(record==1){

                printf("Congratulation %s! You Have Won This Match\nSorry %s! Better Luck Next Time",name1,name2);

                u1_score++;

            }

            else if(record==2){

                printf("Congratulation %s! You Have Won This Match\nSorry %s! Better Luck Next Time",name2,name1);

                u2_score++;

            }

            else { printf("It's a Draw!"); draw++;}

            gotoxy(40,6);

            printf("Score:    %d        %d      %d",u1_score,u2_score,draw);

            gotoxy(50,9);

            printf("1.Continue\n%50c2.Exit\n%50cEnter your choice......",' ',' ');

            while(1){

                choice=getch();

                if(choice=='1')

                    break;

                else if(choice=='2')

                    exit(0);

                else printf("\a");

            }
        }




        else if(mode=='2'){

            repeat:

            printf("%10c1: Beginner\n%10c2: Medium\n%10c3: Hard\n\n%10cEnter Your Choice.......",' ',' ',' ',' ');

            char lavel=getch();

            system("cls");

            if(lavel=='1'){

                printf("%10c1: You Will Give The First Move\n%10c2: Computer will Give The First Move\n\n%10cEnter Your Choice.......",' ',' ',' ');

                while(1){

                    choice=getch();

                    if(choice=='1'||choice=='2')

                        break;

                    else printf("\a");

                }

                system("cls");

                for(int i=0; i<3; i++)

                    for(int j=0; j<3; j++)

                        arr[i][j]=5;

                printf("%s Give Your Move With 1.....",name1);

                printf("\n\n          |   |   \n     _____|___|_____   \n          |   |   \n     _____|___|_____   \n          |   |   \n          |   |   ");

                gotoxy(46,4);

                printf(" Computer    You    Draw");

                gotoxy(40,6);

                printf("Score:    %d        %d      %d",com_score,you_score,draw);

                int x=7,y=2;

                gotoxy(x,y);

                char c,input;

                int tempX=0,tempY=0;

                if(choice=='2'){

                    x=x+5;

                    y=y+2;

                    gotoxy(x,y);

                    printf("0");

                    arr[1][1]=0;

                    tempX=1;

                    tempY=1;

                }

                int uX,uY,record=0;

                while(1){

                    c=getch();

                    if(c=='1'){

                        if(arr[tempX][tempY]==5){

                            printf("%c",c);

                            arr[tempX][tempY]=1;



                            if(arr[2][2]+arr[2][1]+arr[2][0]==3||arr[0][2]+arr[1][1]+arr[2][0]==3){

                                record=2;

                                break;

                            }



                            if(findWin(&uX,&uY)){

                                putArr(uX,uY,&tempX,&tempY,&x,&y);

                                record=1;

                                break;

                            }



                            if(find(tempX,tempY,&uX,&uY))

                                putArr(uX,uY,&tempX,&tempY,&x,&y);


                            else if(haveCom2Way(&uX,&uY))

                                putArr(uX,uY,&tempX,&tempY,&x,&y);


                            else if(arr[1][2]==5&&((arr[0][2]==1&&arr[2][0]==1)||(arr[0][2]==1&&arr[2][1]==1)))

                                putArr(1,2,&tempX,&tempY,&x,&y);


                            /*else if(arr[0][2]==5&&((arr[1][2]==1&&arr[2][0]==1)||(arr[2][2]==1&&arr[1][1]==1)))

                                putArr(0,2,&tempX,&tempY,&x,&y);*/


                            else
                                putAny(&tempX,&tempY,&x,&y);


                            if(!(arr[0][0]==5||arr[0][1]==5||arr[0][2]==5||arr[1][0]==5||arr[1][1]==5||arr[1][2]==5||arr[2][0]==5||arr[2][1]==5||arr[2][2]==5))

                                        break;
                            gotoxy(0,0);


                            printf("%s Give Your Move with 1",name1);

                            gotoxy(x,y);
                        }


                        else{

                            printf("\a");

                        }
                    }


                    else{

                        switch(c){

                            case KEY_UP:tempX--;

                                        if(tempX>=0){

                                            y=y-2;

                                            gotoxy(x,y);

                                        }

                                        else{

                                            printf("\a");

                                            tempX++;

                                        }

                                        break;


                            case KEY_DOWN:  tempX++;

                                            if(tempX<=2){

                                                y=y+2;

                                                gotoxy(x,y);

                                            }

                                            else{

                                                printf("\a");

                                                tempX--;

                                            }

                                            break;


                            case KEY_LEFT:  tempY--;

                                            if(tempY>=0){

                                                x=x-5;

                                                gotoxy(x,y);

                                            }

                                            else{

                                                printf("\a");

                                                tempY++;
                                            }

                                            break;


                            case KEY_RIGHT: tempY++;

                                            if(tempY<=2){

                                                x=x+5;

                                                gotoxy(x,y);

                                            }

                                            else{

                                                printf("\a");

                                                tempY--;

                                            }

                                            break;
                            }

                    }

                }


                printf("\a");

                gotoxy(0,0);

                printf("Game Over.............                   ");

                gotoxy(0,9);

                if(record==2){

                    printf("Congratulation %s! You Have Won The Match",name1);

                    you_score++;

                }

                else if(record==1){

                    printf("Sorry %s! Better Luck Next Time",name1);

                    com_score++;

                }

                else{ printf("It's a Draw!"); draw++;}

                gotoxy(40,6);

                printf("Score:    %d        %d      %d",com_score,you_score,draw);
            }

            else if(lavel=='2'){

                printf("%10c1: You Will Give The First Move\n%10c2: Computer will Give The First Move\n\n%10cEnter Your Choice.......",' ',' ',' ');

                while(1){

                    choice=getch();


                    if(choice=='1'||choice=='2')

                        break;

                    else printf("\a");

                }

                system("cls");

                for(int i=0; i<3; i++)

                    for(int j=0; j<3; j++)

                        arr[i][j]=5;

                printf("%s Give Your Move With 1.....",name1);

                printf("\n\n          |   |   \n     _____|___|_____   \n          |   |   \n     _____|___|_____   \n          |   |   \n          |   |   ");

                gotoxy(46,4);

                printf(" Computer    You    Draw");

                gotoxy(40,6);

                printf("Score:    %d        %d      %d",com_score,you_score,draw);

                int x=7,y=2;

                gotoxy(x,y);

                char c,input;

                int tempX=0,tempY=0;

                if(choice=='2'){

                    x=x+5;

                    y=y+2;

                    gotoxy(x,y);

                    printf("0");

                    arr[1][1]=0;

                    tempX=1;

                    tempY=1;

                }

                int uX,uY,record=0;

                while(1){

                    c=getch();

                    if(c=='1'){

                        if(arr[tempX][tempY]==5){

                            printf("%c",c);

                            arr[tempX][tempY]=1;



                            if(arr[0][2]+arr[1][1]+arr[2][0]==3 || arr[2][0] + arr[2][1]+ arr[2][2] == 3){

                                record=2;

                                break;

                            }



                            if(findWin(&uX,&uY)){

                                putArr(uX,uY,&tempX,&tempY,&x,&y);

                                record=1;

                                break;

                            }



                            if(find(tempX,tempY,&uX,&uY))

                                putArr(uX,uY,&tempX,&tempY,&x,&y);


                            else if(haveCom2Way(&uX,&uY))

                                putArr(uX,uY,&tempX,&tempY,&x,&y);


                            else if(arr[1][2]==5&&((arr[0][2]==1&&arr[2][0]==1)||(arr[0][2]==1&&arr[2][1]==1)))

                                putArr(1,2,&tempX,&tempY,&x,&y);


                            else if(arr[0][2]==5&&((arr[1][2]==1&&arr[2][0]==1)/*||(arr[2][2]==1&&arr[1][1]==1)*/))

                                putArr(0,2,&tempX,&tempY,&x,&y);


                            else
                                putAny(&tempX,&tempY,&x,&y);


                            if(! (arr[0][0]==5||arr[0][1]==5||arr[0][2]==5||arr[1][0]==5||arr[1][1]==5||arr[1][2]==5||arr[2][0]==5||arr[2][1]==5||arr[2][2]==5))

                                        break;

                            gotoxy(0,0);

                            printf("%s Give Your Move with 1",name1);

                            gotoxy(x,y);
                        }


                        else{

                            printf("\a");

                        }
                    }


                    else{

                        switch(c){

                            case KEY_UP:tempX--;

                                        if(tempX>=0){

                                            y=y-2;


                                            gotoxy(x,y);

                                        }

                                        else{

                                            printf("\a");

                                            tempX++;

                                        }

                                        break;


                            case KEY_DOWN:  tempX++;

                                            if(tempX<=2){

                                                y=y+2;

                                                gotoxy(x,y);

                                            }

                                            else{

                                                printf("\a");

                                                tempX--;

                                            }

                                            break;


                            case KEY_LEFT:  tempY--;

                                            if(tempY>=0){

                                                x=x-5;

                                                gotoxy(x,y);

                                            }

                                            else{

                                                printf("\a");

                                                tempY++;

                                            }

                                            break;


                            case KEY_RIGHT: tempY++;

                                            if(tempY<=2){

                                                x=x+5;

                                                gotoxy(x,y);
                                            }

                                            else{

                                                printf("\a");

                                                tempY--;

                                            }

                                            break;
                            }
                      }
                }


                printf("\a");

                gotoxy(0,0);

                printf("Game Over.............                   ");

                gotoxy(0,9);

                if(record==2){

                    printf("Congratulation %s! You Have Won The Match",name1);

                    you_score++;

                }

                else if(record==1){

                    printf("Sorry %s! Better Luck Next Time",name1);

                    com_score++;

                }

                else{ printf("It's a Draw!"); draw++;}

                gotoxy(40,6);

                printf("Score:    %d        %d      %d",com_score,you_score,draw);
            }


            else if(lavel=='3'){

                printf("%10c1: You Will Give The First Move\n%10c2: Computer will Give The First Move\n\n%10cEnter Your Choice.......",' ',' ',' ');

                while(1){

                    choice=getch();

                    if(choice=='1'||choice=='2')

                        break;

                    else printf("\a");

                }

                system("cls");

                for(int i=0; i<3; i++)

                    for(int j=0; j<3; j++)

                        arr[i][j]=5;

                printf("%s Give Your Move With 1.....",name1);

                printf("\n\n          |   |   \n     _____|___|_____   \n          |   |   \n     _____|___|_____   \n          |   |   \n          |   |   ");

                gotoxy(46,4);

                printf(" Computer    You    Draw");

                gotoxy(40,6);

                printf("Score:    %d        %d      %d",com_score,you_score,draw);



                int x=7,y=2;

                gotoxy(x,y);

                char c,input;

                int tempX=0,tempY=0;

                if(choice=='2'){

                    x=x+5;

                    y=y+2;

                    gotoxy(x,y);

                    printf("0");

                    arr[1][1]=0;

                    tempX=1;

                    tempY=1;

                }

                int uX,uY,record=0;

                while(1){

                    c=getch();

                    if(c=='1'){

                        if(arr[tempX][tempY]==5){

                            printf("%c",c);

                            arr[tempX][tempY]=1;





                            /*if(arr[0][2]+arr[1][1]+arr[2][0]==3){

                                record=2;

                                break;

                            }*/

                            if( arr[2][1] == 1 && arr[1][2] == 1 && arr[2][2] == 5 )

                                putArr( 2 , 2 , &tempX , &tempY , &x , &y ) ;



                            else if(findWin(&uX,&uY)){

                                putArr(uX,uY,&tempX,&tempY,&x,&y);

                                record=1;

                                break;
                            }




                            else if(find(tempX,tempY,&uX,&uY))

                                putArr(uX,uY,&tempX,&tempY,&x,&y);


                            else if(haveCom2Way(&uX,&uY))

                                putArr(uX,uY,&tempX,&tempY,&x,&y);


                            else if(arr[1][2]==5&&((arr[0][2]==1&&arr[2][0]==1)||(arr[0][2]==1&&arr[2][1]==1)))

                                putArr(1,2,&tempX,&tempY,&x,&y);


                            else if(arr[0][2]==5&&((arr[1][2]==1&&arr[2][0]==1)||(arr[2][2]==1&&arr[1][1]==1)))

                                putArr(0,2,&tempX,&tempY,&x,&y);



                            else putAny(&tempX,&tempY,&x,&y);


                            if(!(arr[0][0]==5||arr[0][1]==5||arr[0][2]==5||arr[1][0]==5||arr[1][1]==5||arr[1][2]==5||arr[2][0]==5||arr[2][1]==5||arr[2][2]==5))

                                break;

                            gotoxy(0,0);


                            printf("%s Give Your Move with 1",name1);

                            gotoxy(x,y);
                        }


                        else{

                            printf("\a");

                        }
                    }


                    else{

                        switch(c){

                            case KEY_UP:tempX--;

                                        if(tempX>=0){

                                            y=y-2;

                                            gotoxy(x,y);

                                        }

                                        else{

                                            printf("\a");

                                            tempX++;
                                        }

                                        break;


                            case KEY_DOWN:  tempX++;

                                            if(tempX<=2){

                                                y=y+2;

                                                gotoxy(x,y);

                                            }
                                            else{


                                                printf("\a");
                                                tempX--;

                                            }

                                            break;


                            case KEY_LEFT: tempY--;


                                            if(tempY>=0){

                                                x=x-5;

                                                gotoxy(x,y);

                                            }
                                            else{

                                                printf("\a");

                                                tempY++;

                                            }

                                            break;


                            case KEY_RIGHT: tempY++;

                                            if(tempY<=2){

                                                x=x+5;

                                                gotoxy(x,y);

                                            }

                                            else{

                                                printf("\a");

                                                tempY--;

                                            }

                                            break;
                            }
                    }
                }


                printf("\a");

                gotoxy(0,0);

                printf("Game Over.............                   ");

                gotoxy(0,9);



                /*if(record==2){

                    printf("Congratulation %s! You Have Won The Match",name1);

                    you_score++;

                }*/

                if(record==1){

                    printf("Sorry %s! Better Luck Next Time",name1);

                    com_score++;

                }

                else{ printf("It's a Draw!"); draw++;}

                gotoxy(40,6);

                printf("Score:    %d        %d      %d",com_score,you_score,draw);
            }


            else{
                printf("\a");

                goto repeat;

            }

            gotoxy(50,9);

            printf("1.Continue\n%50c2.Exit\n%50cEnter your choice......",' ',' ');

            while(1){

                choice=getch();

                if(choice=='1')

                    break;

                else if(choice=='2')


                    exit(0);


                else
                    printf("\a");
            }

        }

    }

    return 0;
}
