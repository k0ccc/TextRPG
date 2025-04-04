#include <string>
#include <memory>
#include <iostream>

class Entity
{
protected:
  std::unique_ptr<int> hp_;
  std::unique_ptr<int> atk_;
  std::string name_;
  std::string description_;

public:
  Entity(int hp_, int atk_, std::string name, std::string description);
  void Print() const;
};

Entity::Entity(int hpI = 10, int atkI = 1, std::string name = "", std::string description = "") : name_(name), description_(description)
{
  hp_ = std::make_unique<int>(hpI);
  atk_ = std::make_unique<int>(atkI);
}

void Entity::Print() const
{
  std::cout << *hp_ << " " << *atk_ << " " << name_ << " " << description_ << std::endl;
}
