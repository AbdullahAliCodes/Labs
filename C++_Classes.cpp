#include <iostream>

//defining the class player
class Player
{
    public:
    int x, y;
    int speed;

    void Move(int xa, int ya){
        x += xa * speed;
        y += ya * speed;

    // Code above is a function for the movement of the player -> takes in the player by ..
    // reference so that it can be modified.
    // This function is now in an object and therefore called a METHOD.
    // Also, no need for the "player." bcos its already in the class object.
    }
};

// Move function if it were outside the class
// void Move(Player& player0, int xa, int ya){
        // player.x += xa * player.speed;
        // player.y += ya * player.speed;
    // }

// Main function
int main(){
    Player player0;
    player0.x = 5;
    // Move(player0, 1, -1)
    player0.Move(1,-1)
}
