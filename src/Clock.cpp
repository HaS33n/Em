#include "..\include\Clock.h"

void Clock::Init(sf::Font& fnt, float scale) { //font poza scopem
    updateClock();
    content.setFont(fnt);
    
    content.setCharacterSize(30*scale);
    content.setStyle(sf::Text::Regular);
    content.setFillColor(sf::Color::Black);
    content.setPosition(sf::VideoMode::getDesktopMode().width - (content.getLocalBounds().width+10), sf::VideoMode::getDesktopMode().height - (content.getLocalBounds().height * 1.7));

}

void Clock::updateClock() {
    //auto now = std::chrono::system_clock::now();
    //std::time_t current_time = std::chrono::system_clock::to_time_t(now);

    auto t = std::time(nullptr);
    tm lct;
    ::localtime_s(&lct,&t); //deprecated w release

    std::ostringstream oss;
    oss << std::put_time(&lct, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();

    content.setString(str);
}

void Clock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(content); //tu sie wypierdala, problem z RM
}
/*
stack::

 auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;
 */