#include<iostream>
#include "Grid.h"
#include <SFML/Graphics.hpp>

/*void tab(sf::RenderWindow window) {
    float posX = 0;
    float posY = 0;
    //std::vector<
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sf::RectangleShape oRectangle(sf::Vector2f(50.f,50.f));
            oRectangle.setPosition(posX, posY);
            if (i % 2 == 0 && j % 2 == 0) {
                oRectangle.setFillColor(sf::Color::Red);
            }
            else{ oRectangle.setFillColor(sf::Color::Green); }
            window.draw(oRectangle);
            posX += 50;
            posY += 50;
        }
    }

}*/


int main( int argc, char** argv )
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow( sf::VideoMode( 640, 480 ), "SFML" );
   
    ////Création d'un cercle de radius 100
    //sf::CircleShape oCircle( 100.f );
    ////A la position 0, 0
    //oCircle.setPosition( 0.f, 0.f );
    ////Et de couleur verte
    //oCircle.setFillColor( sf::Color::Green );


    ////Création d'un rectangle de taille 50, 50
    //sf::RectangleShape oRectangle( sf::Vector2f( 50.f, 50.f ) );
    ////A la position 100, 100
    //oCircle.setPosition( 100.f, 100.f );
    ////Et de couleur rouge
    //oRectangle.setFillColor( sf::Color::Red );

    //std::vector<
    int player = 1;
    Grid* oGrid = new Grid();
    //GameLoop
    while( oWindow.isOpen() )
    {
        //EVENT
        sf::Event oEvent;
        while( oWindow.pollEvent( oEvent ) )
        {
            if( oEvent.type == sf::Event::Closed )
                oWindow.close();
            if (oEvent.type == sf::Event::MouseButtonPressed)
            {
                player = oGrid->play(player,oWindow);
            }
        }

        //UPDATE
        
        //DRAW
        //oWindow.clear();
        ////Création d'un cercle de radius 100
        /*oWindow.draw(oRectangle); */
        //oGrid->Show(oWindow);
        oWindow.display();
    }

    return 0;
}


