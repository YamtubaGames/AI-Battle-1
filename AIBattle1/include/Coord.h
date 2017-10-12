#ifndef COORD_H
#define COORD_H


struct Coord
{
    public:
        int x, y;
        int operator-(Coord b) {
            Coord c;
            c.x = this->x - b.x;
            if ((c.x) < 0)
                c.x = -c.x;
            c.y = this->y - b.y;
            if ((c.y) < 0)
                c.y = -c.y;
            return c.x + c.y;
        }

};

#endif // COORD_H
