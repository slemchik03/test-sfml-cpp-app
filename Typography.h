#ifndef H_TYPOGRAPHY
#define H_TYPOGRAPHY

#include "Game.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Typography
{
   sf::Text mainTitle;
   sf::Text currentRoomType;

   sf::Text roomTypesTitle;
   sf::Text availibleRoomsTitle;
   sf::Text availibleRoomsCount;

   vector<sf::Text *> roomTypeList;

   vector<HotelRoom *> filteredRoomList;

   sf::Font mainFont;

   sf::RectangleShape separateBorder;

public:
   void setCurrentRoomType(string text);
   void setRoomTypeList(vector<string> list);
   void setFilteredRooms(vector<HotelRoom *> items);

   void render(sf::RenderWindow &window);
   Typography(string &title);
};

#endif