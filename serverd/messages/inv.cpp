#include "inv.hpp"

using  namespace messages;

payload_t& 
operator<<(payload_t& payload, const inv_vect& obj)
{
  for (const auto& byte : itobl(static_cast<uint32_t>(obj.type)))
    payload.push_back(byte);
  for (const auto& byte : obj.hash)
    payload.push_back(byte);
  return payload;
}

std::istream& 
operator>>(std::istream& is, inv_vect& obj)
{
  is.read(reinterpret_cast<char*>(&obj.type), sizeof(obj.type));
  obj.hash = hash_t(32);
  for (size_t i = 0; i < obj.hash.size(); ++i)
    {
      uint8_t byte;
      is >> byte;
      obj.hash[i] = byte;
    }
  return is;
}

payload_t& 
operator<<(payload_t& payload, const inv& obj)
{
  for (const auto& byte : itobl(obj.inventory.size()))
    payload.push_back(byte);
  for (const auto& elem : obj.inventory)
    payload << elem;
  return payload;
}

std::istream& 
operator>>(std::istream& is, inv& obj)
{
  uint32_t size;
  is.read(reinterpret_cast<char*>(&size), sizeof(size));
  obj.inventory = std::vector<inv_vect>(32);
  for (size_t i = 0; i < obj.inventory.size(); ++i)
    {
      inv_vect elem;
      is >> elem;
      obj.inventory[i] = elem;
    }
  return is;
}

payload_t& 
operator<<(payload_t& payload, const getdata& obj)
{
  for (const auto& byte : itobl(obj.inventory.size()))
    payload.push_back(byte);
  for (const auto& elem : obj.inventory)
    payload << elem;
  return payload;
}

std::istream& 
operator>>(std::istream& is, getdata& obj)
{
  uint32_t size;
  is.read(reinterpret_cast<char*>(&size), sizeof(size));
  obj.inventory = std::vector<inv_vect>(32);
  for (size_t i = 0; i < obj.inventory.size(); ++i)
    {
      inv_vect elem;
      is >> elem;
      obj.inventory[i] = elem;
    }
  return is;
}