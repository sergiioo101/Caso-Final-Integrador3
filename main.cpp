#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
    static constexpr auto reset = "\033[0m";
};

class ConsoleBox
{
public:
    void new_text() {/*...*/}
    void set_text(const std::string &text)
    {
        std::cout << text << std::endl;
    }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado