//#include<SFML/Graphics.hpp>
//#include<iostream>
//#include "Game.h"
//#include<vector>
//using namespace sf;
//using namespace std;
//int main()
//{
//    srand(time(NULL));
//    Game game1;
//    while (game1.GAMERUNNING())
//    {
//        game1.update();
//        game1.render();
//    }
//return 0;
//}

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;
vector<RectangleShape> fillthemonters()
{
    /*
    The function that's responsible for making the monsters
    *to be edited later
    * also, we can change the shape later,to chicken or smth 
    */
    vector<Color>random_colors = { Color::Black,Color::Blue,Color::Green,Color::Yellow,Color::Cyan };
    vector<RectangleShape>answer;
    for (int y = 50; y <= 210; y += 80)
    {
        for (int x = 30; x <= 1020; x += 99)
        {
            RectangleShape ract;
            ract.setPosition(Vector2f(x, y));
            ract.setSize(Vector2f(50, 50));
            ract.setFillColor(random_colors[rand() % random_colors.size()]);
            answer.push_back(ract);
        }
    }
    return answer;
}
void updateenemies(RenderWindow &appWindow,Vector2i MousePosWindow, Vector2f MousePosView,vector<RectangleShape>v) {
    MousePosWindow = Mouse::getPosition(appWindow);
    MousePosView = appWindow.mapPixelToCoords(MousePosWindow);
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i].getGlobalBounds().contains(MousePosView)) {
                v.erase(v.begin() + i);

            }
        }
    }
}
int main() {
    RenderWindow appWindow(VideoMode(800, 600), "Bubble Sort");//shooting game
    vector<RectangleShape>v;
    v = fillthemonters();
    Vector2i MousePosWindow;// Vector2i because it holds 2 integer , if it should hold 2 floats , make it 2f
    Vector2f MousePosView;
    bool mouseheld = false;
    bool deleted = true;
    Event eve;

    while (appWindow.isOpen()) {
        while (appWindow.pollEvent(eve)) {
            if (eve.type == Event::Closed) appWindow.close();
        }
        appWindow.clear(Color::White);
        for (int i = 0; i < v.size(); i++)
        {
            appWindow.draw(v[i]);
        }
        updateenemies(appWindow, MousePosWindow, MousePosView, v);
        appWindow.display();
    }

}
