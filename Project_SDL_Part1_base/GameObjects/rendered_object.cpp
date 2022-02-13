#include "rendered_object.h"

namespace game {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.

SDL_Surface* load_surface_for(const std::string& path,
                              SDL_Surface* window_surface_ptr) {

  // Helper function to load a png for a specific surface
  // See SDL_ConvertSurface
  window_surface_ptr = IMG_Load(path.c_str());
  return window_surface_ptr;
}
} // namespace game

RenderedObject::RenderedObject(const std::string& file_path,SDL_Surface* window_surface_ptr,std::set<std::string> properties) : 
    InterractingObject(properties){
   // InitialiZe the window_surface_ptr_ in the class
  this->window_surface_ptr_ = window_surface_ptr;
  // Load the texture of the animal
  this->image_ptr_ = game::load_surface_for(file_path, this->image_ptr_);
  if (!this->image_ptr_)
    throw std::runtime_error("Could not load image");
  // Give the animal an intial postion
  // in the range of 0 to the frame_width
  this->image_position_.x =
      rand() % (frame_width - frame_boundary - this->image_ptr_->w) +
      frame_boundary;

  // in the range of 0 to the frame_height
  this->image_position_.y =
      rand() % (frame_height - frame_boundary - this->image_ptr_->h) +
      frame_boundary;
  // Give the size of the rectangle
  // the width of the rectangle will be the same as width of the image
  this->image_position_.w = this->image_ptr_->w;
  // the height of the rectangle will be the same as height of the image
  this->image_position_.h = this->image_ptr_->h;
  
}

RenderedObject::~RenderedObject() {
  // Free the surface that has the texture for animals
  SDL_FreeSurface(this->image_ptr_);
}

void RenderedObject::draw() {
  // Put the animal's image surface on the window surface
  SDL_Rect crop, positionFond;
  crop.x = 0;
  crop.y = 0;
  crop.h = this->image_ptr_->h;
  crop.w = this->image_ptr_->w;

  SDL_BlitSurface(this->image_ptr_, &crop, this->window_surface_ptr_,
                  &image_position_);
}