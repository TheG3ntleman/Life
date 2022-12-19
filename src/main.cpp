#include "app.hpp"

// APP CONFIG STUFF

const uint8_t window_x = 800, window_y = 600;
const std::string window_caption = "Physics Simulation Window";

int main() {

  App app{};
  app.run();

  return 0;
}
