#include "ground.h"

ground::ground(SDL_Surface* window_surface_ptr) {

  // InitialiZe the window_surface_ptr_ in the class
  this->window_surface_ptr_ = window_surface_ptr;
}

ground::~ground() {
  // Free the dynamic table array
  this->animals.clear();
  // delete &animals;
}

void ground::add_animal(std::unique_ptr<Animal> animal) {
  // Add the type animal to the dynamic array
  this->animals.push_back(std::move(animal));
}



void ground::update() {
  // The ground gets repainted
  SDL_FillRect(this->window_surface_ptr_, NULL,
               SDL_MapRGB(this->window_surface_ptr_->format, 153, 255, 51));

  for (auto& a : this->animals) {
    a->draw();
    a->move();
    for (auto& b : this->animals) {

      if (a.get() == b.get())
        continue;
        
      a->interract(*b,b->get_position());
    }
  }
}