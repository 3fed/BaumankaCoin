#pragma once

#ifndef GETBLOCKS_H
#define GETBLOCKS_H

#include "./message.hpp"

#include <vector>

namespace messages
{
  struct getblocks
  {
    hash_t hash;
    const char command[command_size] = "getblocks";
  };
} // namespace messages

messages::payload_t&
operator<<(messages::payload_t&, const messages::getblocks&);

std::istream&
operator>>(std::istream&, messages::getblocks&);

#endif // GETBLOCKS_H
