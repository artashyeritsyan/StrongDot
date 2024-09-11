#pragma once
#include <vector>
#include <string>

#include "Slide.hpp"

class Presentation {
public:
public:
    std::string getName() const;
    std::string getCreateDate() const;
    std::string getChangedDate() const;
    std::vector<Slide> getSlides() const;

    void setName(const std::string& value);
    void setCreateDate(const std::string& value);
    void setChangedDate(const std::string& value);
    void setSlides(const std::vector<Slide>& value);

private:
    std::string name;
    std::string createDate;
    std::string changedDate;
    std::vector<Slide> slides;
};