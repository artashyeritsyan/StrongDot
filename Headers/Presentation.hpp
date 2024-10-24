#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "Slide.hpp"

class Presentation {
public:
    Presentation();
    Presentation(const std::string& name, const std::vector<Slide>& slides)
        : name(name), slides(slides) {}


    // Command functions
    // TODO: Write an implementation for this functions 
    int slidesCount();
    void addSlide(int index = NULL);
    void removeSlide(int slideId);
    void nextSlide();
    void prevSlide();
    void slideById(int slideId);
    void moveSlide(int slideId, int newPosition);
    std::vector<Slide> allSlides() const;
    void copySlide(int slideId, int copiedSlideId);

    std::string getName() const;
    void setName(const std::string& value);
    int getCurrentSlideIndex();

private:
    std::string name;
    std::vector<Slide> slides;
    int currentSlideIndex = 0;
};