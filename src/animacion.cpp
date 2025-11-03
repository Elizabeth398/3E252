#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
using namespace ftxui;

int main()
{
    // Crear la ventana
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

    // Agregar código de los elementos de la granja
    const std::vector<std::u32string> sol1 = {
        U"    |    ",
        U" \\ | /  ",
        U"  \\*/   ",
        U"--**O**--",
        U"   /*\\   ",
        U"  / | \\  ",
        U"    |   "};
      
    const std::vector<std::u32string> nube1 = {
        U"    __   _   ",
        U"  _(  )_( )_ ",
        U" (_   _    _)",
        U"   (_) (__)  "};
 
    const std::vector<std::u32string> flor1 = {
        U"   _  ",
        U".\\ /.",
        U"< ~O~ >",
        U" '/_\\' ",
        U"\\ | / ",
        U" \\|/ "};

    const std::vector<std::u32string> venado1 = {
        U"         { }    ",
        U"         {^^,   ",
        U"         (   `-;",
        U"    _     `;;~~ ",
        U"   /(______);   ",
        U"  (         (   ",
        U"   |:------( )  ",
        U" _//         \\ ",
        U"/ /          vv "};

    const std::vector<std::u32string> cactus1 = {
        U"  |  ",
        U"(_|_)",
        U"  |  "}; 


    GestorDibujos gestor;
    gestor.Agregar(Dibujo(2, 1, sol1, ftxui::Color::Yellow2));     // sol amarillo
    gestor.Agregar(Dibujo(15, 2, nube1, ftxui::Color::White));     // nube blanca
    gestor.Agregar(Dibujo(40, 4, nube1, ftxui::Color::White));     // nube blanca
    gestor.Agregar(Dibujo(60, 4, nube1, ftxui::Color::White));     // nube blanca
    
    gestor.Agregar(Dibujo(12, 9, venado1, ftxui::Color::Red));     // venado rojo

    gestor.Agregar(Dibujo(70, 10, cactus1, ftxui::Color::Green));      // cactus verde
    gestor.Agregar(Dibujo(60, 13, flor1, ftxui::Color::Magenta2));      // flor rosa
    gestor.Agregar(Dibujo(50, 11, cactus1, ftxui::Color::Green));      // cactus verde
    gestor.Agregar(Dibujo(35, 13, flor1, ftxui::Color::Magenta2));      // flor rosa
    gestor.Agregar(Dibujo(20, 10, cactus1, ftxui::Color::Green));      // cactus verde
    gestor.Agregar(Dibujo(8, 13, flor1, ftxui::Color::Magenta2));      // flor rosa
 
  


    int frames = 120;
    for (int frame = 0; frame < frames; ++frame)
    {
        // Limpia la pantalla
        screen.Clear();

        // Animación: mover vacas y tractor (índices actualizados)
        gestor.dibujos[0].x = 2 + (frame % 2);  // sol1

        gestor.dibujos[1].x = 15 + (frame % 8); // nube
        gestor.dibujos[2].x = 40 + (frame % 8); // nube
        gestor.dibujos[3].x = 60 + (frame % 8); // nube

        gestor.dibujos[4].x = 12 + (frame % 12); // venado hacia la derecha

        gestor.dibujos[5].x = 70 - (frame % 10); // flora hacia la izquierda
        gestor.dibujos[6].x = 60 - (frame % 10); // flora hacia la izquierda
        gestor.dibujos[7].x = 50 - (frame % 10); // flora hacia la izquierda
        gestor.dibujos[8].x = 35 - (frame % 10); // flora hacia la izquierda
        gestor.dibujos[9].x = 20 - (frame % 10); // flora hacia la izquierda
        gestor.dibujos[10].x = 8 - (frame % 10); // flora hacia la izquierda
        gestor.DibujarTodos(screen);

        // Imprime la pantalla y resetea el cursor
        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
    return 0;
}