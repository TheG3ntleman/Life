#include "window.hpp"
#include <SFML/Window/VideoMode.hpp>


Window::Window(unsigned int w, unsigned int h, std::string title) {
  videoMode = new sf::VideoMode(w, h);
  window = new sf::RenderWindow (*videoMode, title);
}

Window::~Window() {
  delete window;
  delete videoMode;
}

void Window::run () {
  
  while (window->isOpen()) {
   
    while (window->pollEvent(*event)) {
      if (event->type == sf::Event::Closed) 
        window->close();
    }

    window->clear(sf::Color::Black);
    draw();
    window->display();

  }

}

void Window::draw() {
  
}
