#include <string>
#include <vector>
#include <memory>
#include <iostream>

enum class BuffType
{
  Health,
  Attack,
};

enum class StateEntity
{
  Attack,
  Defence,
  Talk,
  Waiting,
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
  StateEntity State;
  void Print() const;
  void Attack(Entity &target);
  void AddBuff(Buff buff);
  void increaseHealth(int value);
  void increaseAttack(int value);
};
