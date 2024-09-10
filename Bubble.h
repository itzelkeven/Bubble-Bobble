#ifndef BUBBLE_H
#define BUBBLE_H

#include <SFML/Graphics.hpp>

class Bubble {
private:
    sf::CircleShape bubbleShape;
    double xDir, yDir;
    int xPos, yPos;
    double radius;
public:
    Bubble ();
    Bubble (const double INITX, const double INITY, const double RADIUS, const double RANDX, const double RANDY, const int RED, const int BLUE, const int GREEN);
    void draw(sf::RenderWindow& window);
    void updatePosition(const int WIDTH, const int HEIGHT);  
    /*
    void setX(double newXDir);
    void setY(double newYDir);
    void setRadius(double newRadius);
    double getX();
    double getY();
    double getRadius();

    */
};



#endif // BUBBLE_H
