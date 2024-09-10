// NECESSARY LIBRARIES
#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Bubble.h"
#include <ctime>
#include <vector>
using namespace std;
using namespace sf;

// Start of Main Program
int main() {
    // Set up randomizer
    srand(time(0));
    rand();
    // Create an event to be able to quit the program and window
    Event event;
    // Set up time variables for animation1
    Clock programClock;
    Time lastTime = programClock.getElapsedTime();

    // Create a RenderWindow object to display the program
    RenderWindow window( VideoMode(1000, 1000), "Bubble Bobble" );

    // Set up vector for stored bubbles
    vector<Bubble> storedBubbles;
    // Initialize the default parameters for our bubbles
    float initX = 0, initY = 0, randX = 0, randY = 0, mouseX = 0, mouseY = 0;
    int newRadius = 0, red = 0, green = 0, blue = 0;
    
    // Make the initial five bubbles with all attributes being randomized then add to storedBubbles vector
    for (int i = 0; i < 5; i++) {
        initX = float(rand() % 301 + 100);
        initY = float(rand() % 301 + 100);
        randX = ((float)rand() / RAND_MAX) * 0.3334 - 0.1667;
        randY = ((float)rand() / RAND_MAX) * 0.3334 - 0.1667;
        newRadius = rand() % 41 + 10;
        red = rand() % 256;
        green = rand() % 256;
        blue = rand() % 256;
        storedBubbles.push_back(Bubble(initX, initY, newRadius, randX, randY, red, green, blue));

    }

    // Set the window's icon
    while (window.isOpen()) {
        // Clean the window before updating the window
        window.clear();

        // Draw initial 5 bubbles from vector
        for (unsigned int j = 0; j < storedBubbles.size(); j++) {
            storedBubbles.at(j).draw(window);
        }
        
        // Display current bubbles
        window.display();

        // Check time frame to see if we need to update the position of the bubbles
        Time currTime = programClock.getElapsedTime();
        if ((currTime - lastTime).asSeconds() > (1.0f/60.0f)) {
            for (unsigned int k = 0; k < storedBubbles.size(); k++) {
                storedBubbles.at(k).updatePosition(1000, 1000);
            }
            // Update the last time checked
            lastTime = currTime;
        }
    
        // Handle events on the window
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // If the mouse is left clicked in the window, then make a new bubble at the position of the mouse and randomize everything else and add to storedBubbles vector
            else if(event.type == Event::MouseButtonPressed){
                mouseX = event.mouseButton.x;
                mouseY = event.mouseButton.y;
                randX = ((float)rand() / RAND_MAX) * 0.3334 - 0.1667;
                randY = ((float)rand() / RAND_MAX) * 0.3334 - 0.1667;
                newRadius = rand() % 41 + 10;
                red = rand() % 256;
                green = rand() % 256;
                blue = rand() % 256;
                Bubble pressedBubble(mouseX, mouseY, newRadius, randX, randY, red, green, blue);
                storedBubbles.push_back(pressedBubble);
            }
            // If the 'D' key is pressed then make a new bubble at the position of the mouse
            else if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::D){
                    if(storedBubbles.size() == 0){
                        break;
                    }
                    else{
                        storedBubbles.pop_back();
                        break;
                    }
                }
            }
            // If Q or the Esc button are pressed, end the program and close the window.
            else if(event.key.code == Keyboard::Q || event.key.code == Keyboard::Escape){
                    window.close();
                    break;
                }
            // check addition event types to handle additional events
        }
    }

    return 0;
}
