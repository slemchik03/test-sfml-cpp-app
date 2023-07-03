#ifndef H_GAME
#define H_GAME
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

enum Direction
{
    UP,
    DOWN
};

struct HotelRoom
{
    int number;
    int floor;
    string type;
    bool isAvailible;
    HotelRoom(int n, int f, string roomType) : number(n), floor(f), type(roomType), isAvailible(true) {}
};

class Game
{
public:
    vector<HotelRoom *> hotelRoomList;
    string activeRoomType;
    vector<string> roomTypes;
    vector<HotelRoom *> availibleRooms;

    int findActiveIdx();
    Game(vector<HotelRoom *> roomList, vector<string> roomTypes);
    void listener(sf::RenderWindow &window);
    void changeActiveRoomType(Direction direction);
    void filterAvailibleRooms();
    void render(sf::RenderWindow &window);
};

#endif