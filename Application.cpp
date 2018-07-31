#include "Application.h"
#include "CommandBlock.h"
#include "Observer.h"
#include "LineProcessor.h"
#include "Metrics.h"

#include <string>
#include <iostream>

Application::Application(int i_blockLen)
  : d_blockLen(i_blockLen)
{
}

void Application::run()
{
  auto cb = std::make_shared<CommandBlock>(d_blockLen);

  cb->subscribe(std::make_unique<CoutObserver>());
  cb->subscribe(std::make_unique<LogObserver>());

  LineProcessor processor(cb);

  std::string line;
  
  while (std::getline(std::cin, line))
    processor.processLine(line);

  cb->setStatus(Status::endBlock);
}
