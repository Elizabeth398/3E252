    #include <iostream>

    int main(int argc, char const *argv[])
    {
        int *pNumero = NULL;
        pNumero = new int;
        *pNumero = 25;

        sizeof(pNumero);

        std:: cout << "Direccion: " << pNumero << '\n';
        std:: cout << "Valor: " << *pNumero << '\n';
        std:: cout << "Direccion: " << &pNumero << '\n';

        return 0;
    }

    