#pragma once

#include <memory>
#include <string>
#include <vector>

struct TimedBlock;
enum class Status;
class Observer;

class CommandBlock
{
public:
  CommandBlock(int i_len);

  void setStatus(Status i_status);
  
  void subscribe(std::unique_ptr<Observer> i_observer);

  void notify();

  void append(const std::string & i_command);

public:
  std::shared_ptr<TimedBlock> d_timedBlock;

private:
  Status d_status;
  size_t d_blockLen;
  std::vector<std::unique_ptr<Observer>> d_subscribers;
};
