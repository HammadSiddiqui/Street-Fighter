#pragma once
#include "Fighter.h"
class Enemy : public Fighter {
public:
  Enemy();
  Enemy(BITMAP *, float, float);
  virtual ~Enemy();
  void Draw(BITMAP *);
  void AI();
  void SetTarget(Fighter *);

protected:
  Fighter *target;
  unsigned int delay;

private:
};
