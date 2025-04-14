#include <string>
#include <vector>
#include <memory>
#include <iostream>

enum class BuffType
{
  Health,
  Attack,
};

struct Buff
{
  int duration;
  int value;
  BuffType type;

  Buff(BuffType t, float v, float d) : type(t), value(v), duration(d) {};

  void applyBuff(class Entity &Entity);
};

class Entity
{
protected:
  int hp_;
  int atk_;
  std::string name_;
  std::unique_ptr<std::string> description_;
  std::vector<Buff> buffs_;

public:
  Entity(int hp_ = 10, int atk_ = 1, std::string name = "", std::string description = "");
  void Print() const;
  void Attack(Entity &target);
  void AddBuff(Buff buff);
  void increaseHealth(int value);
  void increaseAttack(int value);
};

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