#include "app.hpp"

// APP CONFIG STUFF

const unsigned int windowWidth = 800, windowHeight = 600;
const std::string windowCaption = "Physics Simulation Window";

int main() {

  App app{windowWidth, windowHeight, windowCaption};
  app.run();

  return 0;
}
