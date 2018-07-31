#include "Observer.h"
#include "Metrics.h"

#include <fstream>
#include <iostream>
#include <sstream>

void CoutObserver::update(std::shared_ptr<TimedBlock> timedBlock)
{
  auto &commands = timedBlock->d_commands;
  for (auto &command : commands)
    std::cout << command << ' ';

  std::cout << std::endl;
}

void LogObserver::update(std::shared_ptr<TimedBlock> timedBlock)
{
  std::ofstream ofile(getFileName(timedBlock->d_timeStamp));

  auto &commands = timedBlock->d_commands;
  for (auto& command : commands)
    ofile << command << ' ';

  ofile << std::endl;

  ofile.close();
}

std::string LogObserver::getFileName(const std::time_t &time) const
{
  std::ostringstream oss;
  oss << "bulk" << time << ".log";
  return oss.str();
}
