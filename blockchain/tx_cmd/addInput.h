#pragma once

#ifndef ADDINPUT_H
#define ADDINPUT_H

#include "./command.h"

#include <vector>

class AddInput : public Command
{
public:
  AddInput(Output out, size_t tail, std::vector<uint8_t> hashInfo)
  : output(out), tailNum(tail), hash(hashInfo)
  {
  }
  
  void
  Execute()
  {
    txe.addInput(output, tailNum, hash);
  }

  void
  unExecute()
  {
    txe.removeInput(output, tailNum, hash);
  }

private:
  Output output;
  size_t tailNum;
  std::vector<uint8_t> hash;
};

#endif // ADDINPUT_H
