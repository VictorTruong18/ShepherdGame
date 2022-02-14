#pragma once
#include "animal.h"
#include "../constants.h"


/**
 * Class Sheep - derived from Animal
 */
class Sheep : public Animal {
public:
  /**
   * Method - contructor
   * @param window_surface_ptr_ pointer to SDL_Surface
   */
  Sheep(SDL_Surface* window_surface_ptr_);
  /**
   * Method - detroyer
   */
  ~Sheep();
  // implement functions that are purely virtual in base class

  void interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition) override;

  void update_status() override;
};