#ifndef GAME
#define GAME

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace std;

Game::Game(vector<HotelRoom *> roomList, vector<string> roomTypesList) {
  this->roomTypes = roomTypesList;
  this->activeRoomType = roomTypesList[0];
  this->hotelRoomList = roomList;
  filterAvailibleRooms();
};

void Game::listener(sf::RenderWindow &window) {
  sf::Event event;

  while (window.pollEvent(event)) {

    if (event.type == sf::Event::Closed)
      window.close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      changeActiveRoomType(Direction::DOWN);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      changeActiveRoomType(Direction::UP);
    }
  }
}
void Game::changeActiveRoomType(Direction direction) {
  int idx = findActiveIdx();
  if (direction == Direction::DOWN && idx != -1) {
    if (idx + 1 < roomTypes.size()) {
      activeRoomType = roomTypes[idx + 1];

      return filterAvailibleRooms();
    }
  } else {
    if (idx - 1 >= 0) {
      activeRoomType = roomTypes[idx - 1];
      return filterAvailibleRooms();
    }
  }
}
void Game::filterAvailibleRooms() {
  vector<HotelRoom *> filteredRooms;

  for (int i = 0; i < hotelRoomList.size(); i++) {
    if (hotelRoomList[i]->type == activeRoomType &&
        hotelRoomList[i]->isAvailible) {
      filteredRooms.push_back(hotelRoomList[i]);
    }
  }
  availibleRooms = filteredRooms;
}
int Game::findActiveIdx() {
  int idx = -1;
  for (int i = 0; i < roomTypes.size(); i++) {
    if (roomTypes[i] == activeRoomType) {
      return i;
    }
  }
  return idx;
}
void Game::render(sf::RenderWindow &window) { listener(window); }
#endif
