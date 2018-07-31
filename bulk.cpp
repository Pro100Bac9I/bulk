#include "Application.h"

#include <string>

int main(int argc, char **argv)
{
  if (argc < 2)
    return 1;
  
  Application app(std::stoi(argv[1]));
  app.run();

  return 0;
}
