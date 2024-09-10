// BUBBLE IMPLEMENTATION
#include "Bubble.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System/Clock.hpp>

using namespace sf;


// Default constructor
Bubble::Bubble() {
    xDir = 0.2;
    yDir = 0.2;
    xPos = 0;
    yPos = 0;
    radius = 100.0;
    bubbleShape.setRadius(radius);
    bubbleShape.setPosition(xPos, yPos);
}

// Modifiable constructor
Bubble::Bubble(const double INITX, const double INITY, const double RADIUS, const double RANDX, const double RANDY, const int RED, const int BLUE, const int GREEN) {
    xPos = INITX;
    yPos = INITY;
    xDir = RANDX;
    yDir = RANDY;
    radius = RADIUS;  
    bubbleShape.setRadius(radius);
    bubbleShape.setFillColor(Color(RED, GREEN, BLUE));
    bubbleShape.setPosition(xPos, yPos);
}

// Draw bubbles to the window
void Bubble::draw(RenderWindow& window) {
    window.draw(bubbleShape);

}

// Update the position of our bubbles
void Bubble::updatePosition (const int WIDTH, const int HEIGHT) {
    // Get current position of our bubble objects
    Vector2f currPosition = bubbleShape.getPosition();
    // Set X and Y coordinates of position
    double currX = currPosition.x, currY = currPosition.y;

    // Check if the current position of X has collided with the right and left walls, if they have, reverse the direction
    if ((currX + (2*radius)) >= WIDTH) {
        xDir = -xDir;
    }
    if (currX <= 0) {
        xDir = -xDir;
    }

    // Check if the current position of Y has collided with the top and bottom walls, if so, reverse the direction
    if ((currY + (2*radius)) >= HEIGHT) {
        yDir = -yDir;
    }
    if (currY <= 0) {
        yDir = -yDir;
    }

    // Update the position of our bubble objects
    currX += xDir;
    currY += yDir;
    bubbleShape.setPosition(currX, currY);
    
    
    
}

// Never used these getters and setters but they would be useful if we were to implement them if the user wanted specific parameters for their bubbles
/*
void Bubble::setX(const double NEWX) {
    xDir = NEWX;
}

void Bubble::setY(const double NEWY) {
    yDir = NEWY;
}

void Bubble::setRadius(const double NEWR) {
    radius = NEWR;
}

double Bubble::getX() {
    return xDir;
}

double Bubble::getY() {
    return yDir;
}

double Bubble::getRadius() {
    return radius;
}
*/
