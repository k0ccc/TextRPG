#include "entity.hpp"

Entity::Entity(int hp, int atk, std::string name, std::string description) : hp_(hp), atk_(atk), name_(name), description_(std::make_unique<std::string>(description)) {}

// Buff methods

inline void Buff::applyBuff(Entity &Entity)
{
  switch (type)
  {
  case BuffType::Health:
    Entity.increaseHealth(value);
    break;
  case BuffType::Attack:
    Entity.increaseAttack(value);
    break;
  }
}

// Entity methods

inline void Entity::increaseHealth(int value) { hp_ += value; }
inline void Entity::increaseAttack(int value) { atk_ += value; }

inline void Entity::Print() const
{
  std::cout << hp_ << " " << atk_ << " " << name_ << " " << *description_ << std::endl;
}

inline void Entity::Attack(Entity &target)
{
  target.hp_ -= atk_;
}

inline void Entity::AddBuff(Buff buff)
{
  buffs_.push_back(buff);
}