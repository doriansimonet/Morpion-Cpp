#include "Grid.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector> //Ne pas oublier !
#include <Windows.h>
Grid::Grid() {
    m_rows = 3;
    m_cols = 3;
    std::vector<int> ligne;
    ligne.resize(3);
    ligne[0] = 0;
    ligne[1] = 0;
    ligne[2] = 0;
    m_grid.resize(3);
    m_grid[0] = ligne;
    m_grid[1] = ligne;
    m_grid[2] = ligne;
}

void Grid::Show(sf::RenderWindow& window) {
    int posX = 0;
    int posY = 0;
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {

            sf::RectangleShape oRectangle(sf::Vector2f(100.f, 100.f));
            oRectangle.setPosition(posX, posY);
            if (m_grid[i][j] == 0) {
                oRectangle.setFillColor(sf::Color::Green);
            }
            if (m_grid[i][j] == 1) {
                oRectangle.setFillColor(sf::Color::Magenta);
            }
            if (m_grid[i][j] == 2) {
                oRectangle.setFillColor(sf::Color::Blue);
            }
            window.draw(oRectangle);
            //std::cout << "heu";
            posX += 100;

        }
        posY += 100;
        posX = 0;
    }
}

bool Grid::checkWin(int player) {
    // Vérifier les lignes et la victoire sur une ligne
    for (int i = 0; i < m_rows; i++) {
        if (m_grid[i][0] == player && m_grid[i][1] == player && m_grid[i][2] == player) {
            return true; 
        }
    }

    // Vérifier les colonnes et la victoire sur une colonne
    for (int j = 0; j < m_cols; j++) {
        if (m_grid[0][j] == player && m_grid[1][j] == player && m_grid[2][j] == player) {
            return true; 
        }
    }

    // Vérifier les diagonales et la victoire sur une diagonale
    if (m_grid[0][0] == player && m_grid[1][1] == player && m_grid[2][2] == player) {
        return true; 
    }
    // Vérifier l'autre diagonale
    if (m_grid[0][2] == player && m_grid[1][1] == player && m_grid[2][0] == player) {
        return true; 
    }

    return false; // Aucune victoire
}



int Grid::play(int player, sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::RectangleShape oRectangle(sf::Vector2f(100.f, 100.f));

    ;
    //1ere ligne
    if (mousePos.x <= 100) {
        if (mousePos.y <= 100) {
            //1ère case
            //std::cout << "hey";
            if (m_grid[0][0] == 0) {
                m_grid[0][0] = player;
                checkWin(player);

                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }

        }
    }
    if (mousePos.x > 100 && mousePos.x < 200) {
        if (mousePos.y <= 100) {
            //2ère case
            if (m_grid[0][1] == 0) {
                m_grid[0][1] = player;
                checkWin(player);

                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }
        }
    }
    if (mousePos.x > 200 && mousePos.x < 300) {
        if (mousePos.y <= 100) {
            //3ère case
            if (m_grid[0][2] == 0) {
                m_grid[0][2] = player;
                checkWin(player);

                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }
        }
    }
    //2eme ligne
    if (mousePos.x <= 100) {
        if (mousePos.y > 100 && mousePos.y < 200) {
            //1ère case
            if (m_grid[1][0] == 0) {
                m_grid[1][0] = player;
                checkWin(player);
                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }
        }
    }
    if (mousePos.x > 100 && mousePos.x < 200) {
        if (mousePos.y > 100 && mousePos.y < 200) {
            //2ère case
            if (m_grid[1][1] == 0) {
                m_grid[1][1] = player;
                checkWin(player);
                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }
        }
    }
    if (mousePos.x > 200 && mousePos.x < 300) {
        if (mousePos.y > 100 && mousePos.y < 200) {
            //3ère case
            if (m_grid[1][2] == 0) {
                m_grid[1][2] = player;
                checkWin(player);
                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }
        }
    }
    //3eme ligne
    if (mousePos.x <= 100) {
        if (mousePos.y > 200 && mousePos.y < 300) {
            //1ère case
            if (m_grid[2][0] == 0) {
                m_grid[2][0] = player;
                checkWin(player);
                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }
        }
    }
    if (mousePos.x > 100 && mousePos.x < 200) {
        if (mousePos.y > 200 && mousePos.y < 300) {
            //2ère case
            if (m_grid[2][1] == 0) {
                m_grid[2][1] = player;
                checkWin(player);
                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }
        }
    }
    if (mousePos.x > 200 && mousePos.x < 300) {
        if (mousePos.y > 200 && mousePos.y < 300) {
            //3ère case
            if (m_grid[2][2] == 0) {
                m_grid[2][2] = player;
                checkWin(player);
                if (player == 1) {
                    player++;
                }
                else if (player == 2) {
                    player--;
                }

            }
        }
    }
    
    // Maj de la grille avec le coup du joueur
    m_grid[mousePos.y / 100][mousePos.x / 100] = player;

    // Vérifiez la victoire
    if (checkWin(player)) {
        std::cout << "Joueur " << player << " a gagné !" << std::endl;
        // Ajoutez ici le code pour gérer la fin du jeu
    }

    return player;
}

void Grid::checkWin(int player) {
    // Vérifier les lignes et la victoire sur une ligne
    for (int i = 0; i < m_rows; i++) {
        if (m_grid[i][0] == player && m_grid[i][1] == player && m_grid[i][2] == player) {
            std::cout << "Joueur " << player << " a gagné !" << std::endl;
        }
    }

    // Vérifier les colonnes et la victoire sur une colonne
    for (int j = 0; j < m_cols; j++) {
        if (m_grid[0][j] == player && m_grid[1][j] == player && m_grid[2][j] == player) {
            std::cout << "Joueur " << player << " a gagné !" << std::endl;
        }
    }

    // Vérifier les diagonales et la victoire sur une diagonale
    if (m_grid[0][0] == player && m_grid[1][1] == player && m_grid[2][2] == player) {
        std::cout << "Joueur " << player << " a gagné !" << std::endl;
    }
    // Vérifier l'autre diagonale
    if (m_grid[0][2] == player && m_grid[1][1] == player && m_grid[2][0] == player) {
        std::cout << "Joueur " << player << " a gagné !" << std::endl;
    }

}