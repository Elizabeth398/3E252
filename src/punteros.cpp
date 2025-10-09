    #include <iostream>

    using namespace std;

    int main(int argc, char const *argv[])
    {
        int *pNumero = NULL;
        pNumero = new int;
        *pNumero = 25;

        sizeof(pNumero);

        std:: cout << "Direccion: " << pNumero << '\n';
        std:: cout << "Valor: " << *pNumero << '\n';
        std:: cout << "Direccion: " << &pNumero << '\n';

        cout << "Tipos de datos: "<< endl;

        cout << "Tamaño : " << sizeof(int) << endl;
        cout << "Tamaño : " << sizeof(long) << endl;
        cout << "Tamaño : " << sizeof(float) << endl;
        cout << "Tamaño : " << sizeof(double) << endl;
        cout << "Tamaño : " << sizeof(char) << endl;
        cout << "Tamaño : " << sizeof(bool) << endl;
        cout << "Tamaño : " << sizeof(byte) << endl;
        return 0;
    }