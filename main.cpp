#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void load_script(const char* filename, bool show_script = false)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return;
    }

    string script((istreambuf_iterator<char>(file)), {});

    file.close();

    if (show_script)
    {
        cout << "Contenido del archivo " << filename << ":\n";
        cout << script << endl;
    }
}

void load_script()
{
    string filename;
    cout << "Ingrese el nombre del archivo: ";
    cin >> filename;

    load_script(filename.c_str(), true);
}

int main()
{
    // Uso de las funciones load_script
    load_script(); // Pide el nombre del archivo al usuario y muestra el contenido
    // Puedes probar también con load_script("nombre_archivo.txt", true);

    return 0;
}

