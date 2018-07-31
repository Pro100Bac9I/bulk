#pragma once

#include <vector>
#include <ctime>

enum class Status
{
  startBlock, endBlock,
  openBracket, closeBracket
};

using Commands = std::vector<std::string>;

struct TimedBlock
{
  Commands d_commands;
  std::time_t d_timeStamp;

  bool empty() const
  {
  	return d_commands.empty();
  }
};
