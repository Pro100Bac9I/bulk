#include "LineProcessor.h"
#include "CommandBlock.h"
#include "Metrics.h"


LineProcessor::LineProcessor(std::shared_ptr<CommandBlock> i_block)
  : d_block(i_block)
{}

void LineProcessor::processLine(const std::string &line)
{
  if (line == "{")
  {
    ++d_bracketCounter;
    if (d_bracketCounter == 1)
      d_block->setStatus(Status::openBracket);
  }
  else if (line == "}")
  {
    --d_bracketCounter;
    if (d_bracketCounter == 0)
      d_block->setStatus(Status::closeBracket);
  }
  else
    d_block->append(line);
}
