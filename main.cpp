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

void load_script(const std::string &filename, bool show_script = false)
{
    try
    {
        std::ifstream file(filename);

        if (!file.is_open())
        {
            throw std::runtime_error("Error al abrir el archivo: " + filename);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string script = buffer.str();

        if (show_script)
        {
            std::cout << ColorConsole::fg_blue << ColorConsole::bg_white << script << ColorConsole::reset << std::endl;
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Error durante la lectura del archivo: " + std::string(e.what()));
    }
}
