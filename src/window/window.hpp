#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string.h>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

class Window {

public:
  Window(unsigned int w, unsigned int h, std::string title);
  ~Window();

  void run();

  void add_draw_call (void (*draw_call)(sf::RenderWindow*));
  void add_update_call(void (*update_call)());

private:
  sf::RenderWindow *window;
  sf::VideoMode *video_mode;
  sf::Event event;

  std::vector<void (*)(sf::RenderWindow*)> draw_calls;
  std::vector<void (*)()> update_calls;

};

#endif
