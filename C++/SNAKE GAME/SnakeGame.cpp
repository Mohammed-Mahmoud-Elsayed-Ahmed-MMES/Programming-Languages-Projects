#include<graphics.h>
#include<climits>
#include<queue>
#include<sstream>
#include<iostream>
#include <time.h>
#include <cstdlib>

using namespace std;
const int EMPTY = 0;
const int BODY = 1;
const int APPLE = 2;
const int WALL = 3;
const int SCORE = 4;
int currentScore = 0;
int topScore = 0;
//int* currentScore = new int(0);


enum Directions {UP, DOWN, LEFT, RIGHT};
Directions snakeDirection = DOWN;
bool isGameOver = false;
bool isFireStarted ;
Directions fireDirection;

struct Location
{
    int r;
    int c;
};

Location fireLocation;
queue<Location>snakeBody;

int board[36][35] =
{
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
};
void drawName()
{
    //int x = 0;
    //int y = 0;

    //setcolor(WHITE);
    //int maxX = getmaxx();
    //int maxY = getmaxy();

    outtextxy(20, 10," Directed by :_ ");
    outtextxy(20, 30," Eng : \"Mohamed Mahmoud El-Sayed Ahmed\" ");

    outtextxy(200, 200," Press Enter to continue ......");
    while(getch() != '\r')
    {

    }
    /*cleardevice();
    // ME
    setbkcolor(LIGHTGRAY);*/
}
// ME
int y = YELLOW;
// ME
void snakeColors(int r, int c)
{
    /*if(board[r][c]==EMPTY)
    {
        setfillstyle(SOLID_FILL,y);
    }else if(board[r][c]==APPLE)
    {
        setfillstyle(SOLID_FILL,rand() % 255 + 200);
        y = rand() % 255 + 200;
    }*/
    //srand(time(0));
    switch(board[r][c])
    {
    case EMPTY:
    {
        setfillstyle(SOLID_FILL,y);
        break;
    }

    case APPLE:
    {
        y = rand()%256;
        setfillstyle(SOLID_FILL,y);

        /*for(int i=0; i < 255;i++)
        {

        }*/
        break;
    }
    }
}
void drawSnakeBody(int r, int c)
{
    int x = c * 18;
    int y = r * 18;

    // Set the color using the generated RGB values while it is moving
    int red = rand() % 256;
    int green = rand() % 256;
    int blue = rand() % 256;

    //setfillstyle(SOLID_FILL,(red+green+blue));

    // When it eats an apple the color changes
    snakeColors(r,c);
    bar( x +1 , y +1 , x + 17 , y + 17);
}
/* To convert the function above to circle
    sint radius = 9;
    int x0 = x + radius;
    int y0 = y + radius;

    // Draw the circle.
    setfillstyle(SOLID_FILL, y);
    circle(x0, y0, radius);
*/
void eraseSnakeBody(int r, int c)
{
    int x = c * 18;
    int y = r * 18;

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar( x , y , x + 18 , y + 18);
}
// ME
void eraseAllSnakeBody()
{
    for(int i=0; i <= currentScore ; i++)
    {
        Location tail = snakeBody.front();
        snakeBody.pop();
        eraseSnakeBody(tail.r,tail.c);
        board[tail.r][tail.c] = 0;
    }

}

void drawApple(int r,int c)
{
    int x = c * 18;
    int y = r * 18;

    readimagefile("apple.jpg", x+1,y+1, x + 16,y+16);
}
void drawWall(int r, int c)
{
    int x = c * 18;
    int y = r * 18;

    setfillstyle(SOLID_FILL, LIGHTRED);
    bar( x , y , x + 18 , y + 18);

    //setcolor(BLACK); //لملا الفراغات بين الطوب باللون الاسود بدل الابيض
    setlinestyle(SOLID_LINE,1,NORM_WIDTH);
    line(x+0,y+0,x+18,y+0);         // هذة الخطوط لعمل فواصل بين الطوب
    line(x+0,y+9 ,x+18,y+9);
    line(x+0 ,y+18 ,x+18 ,y+18);
    line( x+12 , y+0 ,x+12 ,y+9);
    line(x+6 ,y+9 ,x+6 ,y+18);
}
void drawScore(int r, int c)
//void drawScore()
{
    int x = c * 0;
    int y = r * 0;

    //std::string scour = "Score : ";
    std::stringstream result; //stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin)
    result << "Score : " << currentScore;
    const string tmp = result.str();
    /*std::stringstream topResult;
    result << "Top Score : " << topResult;
    const string topTmp = topResult.str();*/
    setcolor(BLACK);
    outtextxy(x, y,tmp.c_str());
    //outtextxy(x, y,topTmp.c_str() );
}
void drawFire(int r , int c)
{
    int x = c * 18;
    int y = r * 18;

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar( x +2 , y +2 , x + 15 , y + 15);
}
void eraseFire(int r , int c)
{
    int x = c * 18;
    int y = r * 18;

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar( x +2 , y +2 , x + 15 , y + 15);
}
void drawBoard()
{
    for(int r=0; r<36; r++)
    {
        for(int c=0; c<35; c++)
        {
            switch(board[r][c])
            {
            case BODY:
                drawSnakeBody(r,c);
                break;
            case APPLE:
                drawApple(r,c);
                break;
            case WALL:
                drawWall(r,c);
                break;
            case SCORE:
                drawScore(r,c);
                break;
            }

        }

    }

}
void initSnake()
{
    //setfillstyle(SOLID_FILL,YELLOW);
    Location loc;
    loc.r = 2;
    loc.c = 10;
    for(int i=0; i<=4; i++)
    {
        snakeBody.push(loc);
        board[loc.r][loc.c] = 1;
        loc.r +=1;
    }
}
void changeSnakeDirection(char ch)
{
    switch(ch)
    {
    case KEY_UP:
        snakeDirection = UP;
        break;
    case KEY_DOWN:
        snakeDirection = DOWN;
        break;
    case KEY_LEFT:
        snakeDirection = LEFT;
        break;
    case KEY_RIGHT:
        snakeDirection = RIGHT;
        break;
    }
}
Location getNextHead()
{
    Location head = snakeBody.back();
    switch(snakeDirection)
    {
    case UP:
        head.r -= 1;
        break;
    case DOWN:
        head.r += 1;
        break;
    case LEFT:
        head.c -= 1;
        break;
    case RIGHT:
        head.c += 1;
        break;
    }
    return head;
}
void moveSnakeToNextLocation(Location nextHead)
{
    snakeBody.push(nextHead);
    drawSnakeBody(nextHead.r, nextHead.c);
    board[nextHead.r][nextHead.c] = 1;

    Location tail = snakeBody.front();
    snakeBody.pop();
    eraseSnakeBody(tail.r,tail.c);
    board[tail.r][tail.c] = 0;
}

void moveAndGrowSnake(Location nextHead)
{
    int r, c;
    snakeBody.push(nextHead);
    currentScore += 1;
    //drawScore();
    drawScore(r,c);

    drawSnakeBody(nextHead.r, nextHead.c);
    board[nextHead.r][nextHead.c] = 1;
}
std::string to_string(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}
void gameOver()
{
    //setbkcolor(LIGHTRED);
    cleardevice();
    isGameOver = true;
    setcolor(WHITE);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    outtextxy(getmaxx()/2,getmaxy()/2,"Game Over");
    /*std::string scour = "Score : ";
    std::stringstream result;*/
    /*result << scour << currentScore;

    std::string topScore = "Top Score : ";
    std::stringstream topResult;
    if(topScore < currentScore)
    {
        topScore = currentScore;
        topResult << scour << topScore;
    }else
    {
        topResult << scour << topScore;
    }

    std::string tmp = result.str();
    outtextxy(getmaxx()/2,getmaxy()/3, tmp.c_str());
    std::string topTmp = topResult.str();
    outtextxy(getmaxx()/2,getmaxy()/3, topTmp.c_str());*/
    if(topScore < currentScore)
    {
        topScore = currentScore;
    }
    else
    {
        topScore = topScore;
    }
    std::string scoreStr = "Score : " + to_string(currentScore);
    std::string topScoreStr = "Top Score : " + to_string(topScore);

    outtextxy(getmaxx() / 2, getmaxy() / 3, scoreStr.c_str());
    outtextxy(getmaxx() / 2, getmaxy() / 3 * 2, topScoreStr.c_str());
    outtextxy(getmaxx()/2,getmaxy()," Press Enter to Play Again ......");
    /*string soundFile = "game over.wav";
    PlaySound(soundFile.c_str(), NULL, SND_SYNC);*/

    setcolor(BLACK);
    //drawScore();

    while(getch() != '\r')
    {

    }
    cleardevice();
    //drawScore();
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    cleardevice();
    int x = 0;
    int y = 0;

    std::stringstream result;
    result << "Score : " << currentScore;
    const string tmp = result.str();
    setcolor(BLACK);
    outtextxy(x, y,tmp.c_str());
    /*int currentScore = 0;
    drawScore();*/

    /*while(getch() != '\r')
    {

    }
    //cleardevice();
    isGameOver = false;
    initwindow(630, 650," \" Snake Game \" by Eng\\ Mohamed Mahmoud El-Sayed ");
    drawName();
    drawScore();
    initSnake();
    drawBoard();*/


}
void generateNextApple()
{
    int r,c;
    do
    {
        r = rand()%35;
        c = rand()%35;
    }
    while(board[r][c] != EMPTY);
    board[r][c] = APPLE;
    drawApple(r,c);
}
void moveSnake()
{
    Location nextHead = getNextHead();
    switch(board[nextHead.r][nextHead.c])
    {
    case EMPTY:
    {
        moveSnakeToNextLocation(nextHead);
        break;
    }

    case APPLE:
    {
        string sound = "apple_bite.wav";
        PlaySound(sound.c_str(), NULL, SND_ASYNC);
        moveAndGrowSnake(nextHead);
        generateNextApple();
        break;
    }
    case WALL:
    {
        gameOver();
        break;
    }

    case BODY:
    {
        gameOver();
        break;
    }

    }
}
Location getNextFireLocation()
{
    Location nextFireLoc = fireLocation;
    switch(fireDirection)
    {
    case UP:
        nextFireLoc.r -= 1;
        break;
    case DOWN:
        nextFireLoc.r += 1;
        break;
    case LEFT:
        nextFireLoc.c -= 1;
        break;
    case RIGHT:
        nextFireLoc.c += 1;
        break;
    }
    return nextFireLoc;
}
void startFire()
{
    isFireStarted = true;
    fireLocation = getNextHead();
    fireDirection = snakeDirection;
    drawFire(fireLocation.r , fireLocation.c);
    string soundFile = "emo.wav";
    PlaySound(soundFile.c_str(), NULL, SND_SYNC);
}
void stopFire()
{
    isFireStarted = false;
}
void moveFire()
{
    if(isFireStarted)
    {
        Location nextFireLoc = getNextFireLocation();
        if(nextFireLoc.r >35 || nextFireLoc.r <0 || nextFireLoc.c >35 || nextFireLoc.c <0)
        {
            stopFire();
            return;
        }
        drawFire(nextFireLoc.r, nextFireLoc.c);
        eraseFire(fireLocation.r, fireLocation.c);
        fireLocation = nextFireLoc;
    }
}
void checkKeyInput()
{
    char ch;
    if(kbhit())
    {
        ch = getch();
        if(ch == 0)
        {
            ch = getch();
            changeSnakeDirection(ch);
        }
        else if(ch == 32)
        {
            if(!isFireStarted)
                startFire();
        }

    }
}

void gameIntroduction()
{
    initwindow(630, 650," \" Snake Game \" by Eng\\ Mohamed Mahmoud El-Sayed ");
    drawName();
}
void startNewGame()
{
    //delete currentScore;
    currentScore = 0;
    while (!snakeBody.empty())
    {
        eraseAllSnakeBody();
    }
    snakeDirection = DOWN;
int r,c;
    setbkcolor(LIGHTGRAY);
    cleardevice();
    int x = c * 0;
    int y = r * 0;

    std::stringstream result;
    result << "Score : " << currentScore;
    const string tmp = result.str();
    setcolor(BLACK);
    outtextxy(x, y,tmp.c_str());

    drawScore(r,c);
    initSnake();
    drawBoard();
}

// ME
int allOfMain()
{
    isGameOver = false;

    startNewGame();

    int gameTimer = 0;
    while(!isGameOver)
    {
        if(gameTimer == INT_MAX)
            gameTimer = 0;
        if(gameTimer % 500000 == 0)
            moveFire();
        if(gameTimer% 6500000 == 0)
            moveSnake();
        gameTimer++;
        checkKeyInput();
    }
    //while(getch() != '\r')
    //{

    //}

    allOfMain();
    while(! kbhit());
    return 0;
    //return allOfMain();

}
int main()
{
    gameIntroduction();
    allOfMain();
    /*isGameOver = false;
    initwindow(630, 650," \" Snake Game \" by Eng\\ Mohamed Mahmoud El-Sayed ");
    drawName();
    drawScore();
    initSnake();
    drawBoard();


    int gameTimer = 0;
    while(!isGameOver)
    {
        if(gameTimer == INT_MAX)
            gameTimer = 0;
        if(gameTimer % 500000 == 0)
            moveFire();
        if(gameTimer% 5000000 == 0)
            moveSnake();
        gameTimer++;
        checkKeyInput();*/
    /*if(!isGameOver)
    {
        cout << "Game Over!\n";
        cout << "Do you want to try again? (Y/N): ";
        char answer;
        cin >> answer;
        if(answer == 'Y' || answer == 'y')
        {
            isGameOver = false;
            initSnake();
            drawBoard();
            gameTimer = 0;
        }
        else
        {
            break;
        }
    }*/
    //}

    /*if (isGameOver == true)
    {
        isGameOver = true;
        cleardevice();
        outtextxy(getmaxx()/2,getmaxy()," Press Enter to Play Again ......");


        std::string response;
        std::cin >> response;

        if (getch() == '\r')
        {
            allOfMain();
            /*cleardevice();
            isGameOver = false; // Reset the game state
            drawName();
            drawScore();
            initSnake();
            drawBoard();
        }
        else
        {
            break; // Exit the loop and end the program.
        }
    }
    }*/


    /*while(getch() == '\r')
    {
        do
        {
            if(gameTimer == INT_MAX)
                gameTimer = 0;
            if(gameTimer % 500000 == 0)
                moveFire();
            if(gameTimer% 5000000 == 0)
                moveSnake();
            gameTimer++;
            checkKeyInput();
        }
        while(!isGameOver);
    }*/

    while(! kbhit());
    return 0;
}
