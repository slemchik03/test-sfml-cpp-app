#ifndef TYPOGRAPHY
#define TYPOGRAPHY

#include "Game.h"
#include "Typography.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

using namespace std;

Typography::Typography(string &title)
{

    mainFont.loadFromFile("fonts/MonumentExtended-Regular.otf");

    // setup mainTitle text
    mainTitle.setString(title);
    mainTitle.setFillColor(sf::Color::White);
    mainTitle.setFont(mainFont);
    mainTitle.setPosition(sf::Vector2f(250, 40));

    separateBorder.setFillColor(sf::Color::White);
    separateBorder.setSize(sf::Vector2f(5, 500));
    separateBorder.setPosition(sf::Vector2f(500, 200));
    separateBorder.setFillColor(sf::Color::Green);

    roomTypesTitle.setFillColor(sf::Color::White);
    roomTypesTitle.setFont(mainFont);
    roomTypesTitle.setScale(sf::Vector2f(0.8, 0.8));
    roomTypesTitle.setString("Types of our numbers: ");
    roomTypesTitle.setPosition(sf::Vector2f(40, 200));

    availibleRoomsTitle.setFillColor(sf::Color::White);
    availibleRoomsTitle.setFont(mainFont);
    availibleRoomsTitle.setScale(sf::Vector2f(0.8, 0.8));
    availibleRoomsTitle.setString("Availible numbers: ");
    availibleRoomsTitle.setPosition(sf::Vector2f(520, 200));

    availibleRoomsCount.setFillColor(sf::Color::White);
    availibleRoomsCount.setFont(mainFont);
    availibleRoomsCount.setScale(sf::Vector2f(0.8, 0.8));
}

void Typography::setRoomTypeList(vector<string> items)
{
    vector<sf::Text *> currentRoomTypeList;
    for (int i = 0; i < items.size(); i++)
    {
        sf::Text *tempText = new sf::Text();
        tempText->setString(items[i]);
        tempText->setFont(mainFont);
        tempText->setPosition(40, 260 + i * 40);

        currentRoomTypeList.push_back(tempText);
    }

    roomTypeList = currentRoomTypeList;
}

void Typography::setCurrentRoomType(string type)
{
    currentRoomType.setString(type);
}
void Typography::setFilteredRooms(vector<HotelRoom *> rooms)
{
    filteredRoomList = rooms;
}
void Typography::render(sf::RenderWindow &window)
{
    // draw title
    window.draw(mainTitle);

    // render list of categories
    for (int i = 0; i < roomTypeList.size(); i++)
    {
        sf::Text *roomTypeItem = roomTypeList[i];
        if (roomTypeItem->getString() == currentRoomType.getString())
        {
            roomTypeItem->setFillColor(sf::Color::Green);
        }
        else
        {
            roomTypeItem->setFillColor(sf::Color::White);
        }
        window.draw(*roomTypeItem);
    }

    // render border
    window.draw(separateBorder);

    // render items list
    for (int i = 0; i < filteredRoomList.size(); i++)
    {
        HotelRoom *room = filteredRoomList[i];
        sf::Text *tempText = new sf::Text;

        tempText->setFont(this->mainFont);
        tempText->setScale(sf::Vector2f(0.6, 0.6));
        tempText->setString(to_string(i + 1) + ". " + to_string(room->number) + "-n, " + to_string(room->floor) + " floor, type - " + room->type);
        tempText->setPosition(sf::Vector2f(520, 260 + i * 40));

        window.draw(*tempText);
    }
    availibleRoomsCount.setPosition(sf::Vector2f(520, 260 + filteredRoomList.size() * 40 + 100));
    availibleRoomsCount.setString("Availible rooms - " + to_string(filteredRoomList.size()));
    
    window.draw(availibleRoomsCount);
    window.draw(roomTypesTitle);
    window.draw(availibleRoomsTitle);
}

#endif