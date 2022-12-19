#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <string.h>

class App {

public:
  App(unsigned int window_width, unsigned int window_height,
      std::string window_caption)
      : w{window_width}, h{window_height}, caption{window_caption} {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), caption);
  }

  ~App() { delete window; }

  void run();

private:
  unsigned int w, h;
  std::string caption;
  sf::RenderWindow *window;
  sf::Event event;
};
