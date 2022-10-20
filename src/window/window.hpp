#include <SFML/Graphics.hpp>
#include <string>

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
  
public:

  Window(unsigned int w, unsigned int h, std::string title); 
  ~Window();

  void run();
  void draw();

private:
  sf::RenderWindow *window;
  sf::VideoMode *videoMode;
  sf::Event *event;

};

#endif
