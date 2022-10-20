#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
  
public:

  Window(unsigned int w, unsigned int h, std::string title); 
  ~Window();

  void run();
  void draw();

  void addDrawCall(void (*)(sf::RenderWindow*));

private:
  sf::RenderWindow *window;
  sf::VideoMode *videoMode;
  sf::Event *event;

  std::vector<void (*)(sf::RenderWindow*)> drawCalls; 
};

#endif
