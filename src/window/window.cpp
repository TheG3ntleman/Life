#include "window.hpp"

Window::Window(unsigned int w, unsigned int h, std::string title) {
  video_mode = new sf::VideoMode(w, h);
  window = new sf::RenderWindow(*video_mode, title);
}

Window::~Window() {
  delete window;
  delete video_mode;
}

void Window::run() {
  while (window->isOpen()) {
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }
    }

    // Calling updates
    
    for (unsigned int i = 0; i < draw_calls.size(); i++)
      draw_calls[i](window);

    // Calling draws
    for (unsigned int i = 0; i < update_calls.size(); i++) 
      update_calls[i]();

    window->clear(sf::Color::Black);
    window->display();
  }
}

void Window::add_draw_call (void (*draw_call)(sf::RenderWindow*)) {
  draw_calls.push_back(draw_call);
}

void Window::add_update_call(void (*update_call)()) {
  update_calls.push_back(update_call);
}
