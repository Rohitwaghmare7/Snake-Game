#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;;
int x,y,fx,fy,score;
enum direction{STOP = 0,LEFT,RIGHT,UP,DOWN};
direction dri;
void setup()
{
    gameover = false;
    dri = STOP;

    x = width/2;
    y = height/2;

    fx = rand()%width;
    fy =rand()%height;

    score = 0;
}
void draw()
{
    system("cls");
    for(int i=0;i<width+2;i++)
    {
        cout <<"#";
    }
    cout<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if (j == 0)
            {
              cout<<"#";
            }
            if(i == y && j == x)
            {
                cout<<"O";
            }
            else if(i == fy && j == fx)
            {
                cout<<"F";
            }
            else 
            {
                cout<<" ";
            }
            if(j == width - 1)
            {
                cout<<"#";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++)
    {
      cout<<"#";
    }
    cout<<endl;
    cout<<"score"<<score<<endl;

}
void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
            dri = LEFT;
            break;

            case 'd':
            dri = RIGHT;
            break;

            case 's':
            dri = DOWN;
            break;

            case 'w':
            dri = UP;
            break;

            case 'x':
            gameover = true;
            break; 

        }
    }

}
void logic()
{
    switch(dri)
    {
        case LEFT:
        x--;
        break;

        case RIGHT:
        x++;
        break;

        case UP:
        y--;
        break;

        case DOWN:
        y++;
        break;

        default:
        break;

    }
    // if(x < 0 || x > width || y < 0 || y > height)
    // {
        // gameover = true;
    // }
    if(x>=width)
    {
        x=0;
    }
    else if(x<0)
    {
        x=width-1;
    }
    if(y>=height)
    {
        y=0;
    }
    else if(y<0)
    {
        y=height-1;
    }
    if(x == fx && y == fy)
    {
        score += 10;
        fx = rand()%width;
        fy =rand()%height;

    }

}
int main()
{
    setup();
       while(!gameover)
        {
            draw();
            input();
            logic();
            Sleep(100);
        }
    return 0;
}