#include "Editor.hpp"

void Editor::openNextSlide()
{
    if (currSlideIndex < _presentation->getSlidesSize() - 2) {
        ++currSlideIndex;
    }
}

void Editor::openPrevSlide()
{
    if (currSlideIndex > 0) {
        --currSlideIndex;
    }
}

void Editor::addSlide(int slideId)
{
    std::shared_ptr<Slide> slide = std::make_unique<Slide>();
    if(slideId == 0) {
        _presentation->addSlide(_presentation->getSlidesSize(), std::move(slide));
    }
    else {
        _presentation->addSlide(--slideId, std::move(slide));
    }
}

void Editor::removeSlide(int slideId)
{ 
    if(slideId == 0) {
        _presentation->removeSlide(_presentation->getSlidesSize() - 1);
    }
    else {
        _presentation->removeSlide(--slideId);
    }
}

// std::vector<Item> Editor::itemsList()
// {
//     return std::vector<Item>();
// }

// void Editor::printSlides()
// {
//     int slideIndex = 0;

//     for (const auto& slide : _presentation.getAllSlides()) {
//         std::cout << "Slide " << slideIndex 
//                   << ": Item count = " << slide->getAllItems().size() 
//                   << std::endl;
//         ++slideIndex;
//     }
// }

void Editor::printSlides() {
    int slideIndex = 0;
    
    const auto& slides = _presentation->getAllSlides();
    for (const auto& slidePtr : slides) {
        if (slidePtr) {
            std::cout << "Slide " << slideIndex 
                        << ": Items count = " << slidePtr->getAllItems().size()
                        << std::endl;
        }
        ++slideIndex;
    }
}


void Editor::printItems()
{
    const auto &slide = _presentation->getSlideByIndex(currSlideIndex);

    for (const auto& item : slide->getAllItems()) {
        auto pos = item->getPosition();
        std::cout << "Item ID: " << item->getId() 
                  << ", X: " << pos.first
                  << ", Y: " << pos.second
                  << std::endl;
    }
}
