#include "app.hpp"

void App::run() {

  while (window->isOpen()) {
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window->close();
    }
  }

  window->clear(sf::Color::Black);
  window->display();
}
