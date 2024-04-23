#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <string>
#include <fstream>
#include <Dibujo.hpp>

using namespace std;
using namespace ftxui;

int main (int argc, char const *argv[])
{
    Dibujo moto("./assets/images/moto.txt");
    Dibujo bloque("./assets/images/bloque.txt");

    int fotograma=0;
    while(true)
    {
        this_thread::sleep_for(0.1s);
        fotograma++;
        Element personaje = spinner (21,fotograma)| bold | color(Color::Purple) | bgcolor(Color::White);
        Element dibujo = hbox({personaje, moto.GetElement(), bloque.GetElement()});
        Screen pantalla= Screen::Create(Dimension::Full());
        Render(pantalla,dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }
    
    return EXIT_SUCCESS;
}