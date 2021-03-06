#pragma once

#include "../GameObjects/moving_object.h"
#include "../constants.h"
/**
 * Class Animal
 */
class Animal : public MovingObject {

public:
  /**
   * todo: The constructor has to load the sdl_surface that corresponds to the
   * texture
   */
  Animal(const std::string& file_path, SDL_Surface* window_surface_ptr,
         double speed, std::set<std::string> properties);
  /**
   * todo: Use the destructor to release memory and "clean up behind you"
   *
   */
  ~Animal();

  void handle_events(SDL_Event const& event) override;
};