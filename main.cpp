#include "Game.cpp"
#include "Typography.cpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace std;

int main() {
  sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");

  vector<string> roomTypes{"Luxury", "Bussines", "Bomj"};
  vector<HotelRoom *> roomList{
      new HotelRoom(23, 2, "Luxury"),   new HotelRoom(19, 1, "Bomj"),
      new HotelRoom(36, 3, "Bussines"), new HotelRoom(56, 4, "Bussines"),
      new HotelRoom(59, 4, "Bussines"), new HotelRoom(59, 4, "Luxury"),
      new HotelRoom(76, 5, "Luxury"),   new HotelRoom(79, 5, "Luxury")};
  string title = "Nikitka Hotel House";
  Game game(roomList, roomTypes);
  Typography gameTypography(title);

  while (window.isOpen()) {
    window.clear();
    game.render(window);

    gameTypography.setCurrentRoomType(game.activeRoomType);
    gameTypography.setRoomTypeList(game.roomTypes);
    gameTypography.setFilteredRooms(game.availibleRooms);

    gameTypography.render(window);

    window.display();
  }

  return 0;
}
