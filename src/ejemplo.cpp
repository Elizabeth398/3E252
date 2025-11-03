    #include <iostream>
    #include <ftxui/screen/screen.hpp>
    #include <thread>
    #include <chrono>

    using namespace std;
    using namespace ftxui;

    #include <Dibujo.hpp>

    int main(int argc, char const *argv[])
    {
        Screen pantalla = Screen ::Create(
            Dimension::Full(),
            Dimension::Fixed(20)
        );

        Dibujo vaca({
            string("       (__) "), 
            string("`------(oo) "),
            string(" ||    (__) "),
            string(" ||w--||    ")
        });

        Dibujo nave(Color::Green1, Color::Black,
        {
        string(" ___/   \\___  "),
        string("/   '---'   \\ "),
        string("'--_______--' ")    
        }
        );

         while(true){

            nave.MoverDerecha();
            vaca.MoverAbajo();
            vaca.imprimir(pantalla);
            nave.imprimir(pantalla);
            pantalla.Print();

            pantalla.Print();
            
            this_thread::sleep_for(chrono::milliseconds(100));
            
            pantalla.Clear();
            cout << pantalla.ResetPosition();

        }

        return 0;
    }
    