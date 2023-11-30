#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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
    static void set_text(const string &text)
    {
        cout << text << endl;
    }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

void load_script(const string &filename, bool show_script = false)
{
    try
    {
        ifstream file(filename);

        if (!file.is_open())
        {
            throw runtime_error("Error al abrir el archivo: " + filename);
        }

        stringstream buffer;
        buffer << file.rdbuf();
        string script = buffer.str();

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white << script << ColorConsole::reset << endl;
        }

        consoleBox->new_text();
        ConsoleBox::set_text(script);
    }
    catch (const exception &e)
    {
        throw runtime_error("Error durante la lectura del archivo: " + string(e.what()));
    }
}

void load_script()
{
    string filename;
    cout << "Archivo: ";
    cin >> filename;

    try
    {
        load_script(filename, true);
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}

int main()
{
    // Ejemplo de uso
    load_script(); // Pide el nombre del archivo al usuario y muestra el contenido
    load_script("ejemplo.txt", true); // Carga un archivo predefinido y muestra el contenido

    return 0;
}