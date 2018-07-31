#pragma once

#include <memory>
#include <string>

class CommandBlock;

class LineProcessor
{
public:
  LineProcessor(std::shared_ptr<CommandBlock> i_block);

  void processLine(const std::string &i_line);

private:
  std::shared_ptr<CommandBlock> d_block;
  int d_bracketCounter = 0;
};
