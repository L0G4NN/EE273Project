/* move.h
 * Antichess
 * Elias and Logan
 * Logic for the pieces to move around the board
*/


class Pieces {
public:
    Pieces();
    ~Pieces();

    Pieces(int x, int y);

    int getCords(int x, int y);
    void setCords(int x, int y); //for initial game setup

    move();
    check_move();
    take_piece();

private:
    int x;
    int y;

};



