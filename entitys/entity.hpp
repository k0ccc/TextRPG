#include <string>
#include <memory>
#include <iostream>

class Entity
{
protected:
  int hp_;
  int atk_;
  std::string name_;
  std::unique_ptr<std::string> description_;

public:
  Entity(int hp_ = 10, int atk_ = 1, std::string name = "", std::string description = "");
  void Print() const;
};

Entity::Entity(int hp, int atk, std::string name, std::string description) : hp_(hp), atk_(atk), name_(name), description_(std::make_unique<std::string>(description)) {}

void Entity::Print() const
{
  std::cout << hp_ << " " << atk_ << " " << name_ << " " << *description_ << std::endl;
}
