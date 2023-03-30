#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <functional>
#include <map>

//declara una map con numeros enteros como clave y cadenas como valor que 
//se llama traducciones
std::map<int, std::string> traducciones;

struct numero {
    std::vector<int> digitos;
    numero(int n) {
        while (n > 0) {
            digitos.push_back(n % 10);
            n /= 10;
        }
        std::reverse(digitos.begin(), digitos.end());
    }
    std::string traducir() {
        std::string resultado;
        for (int i = 0; i < digitos.size(); i++) {
            if (digitos[i] == 0) {
                continue;
            }
            if (i == digitos.size() - 1) {
                resultado += traducciones[digitos[i]];
            } else if (i == digitos.size() - 2) {
                if (digitos[i] == 1) {
                    resultado += traducciones[digitos[i] * 10 + digitos[i + 1]];
                    break;
                } else {
                    resultado += traducciones[digitos[i] * 10];
                }
            } else if (i == digitos.size() - 3) {
                resultado += traducciones[digitos[i]]  + traducciones[100];
                if (digitos[i + 1] != 0 || digitos[i + 2] != 0) {
                    resultado += "and";
                }
            } else if (i == digitos.size() - 4) {
                resultado += traducciones[digitos[i]]  + traducciones[1000];
            }
        }
        return resultado;
    }
};
int main(int argc, char *argv[]) {
traducciones[1] = "one";
traducciones[2] = "two";
traducciones[3] = "three";
traducciones[4] = "four";
traducciones[5] = "five";
traducciones[6] = "six";
traducciones[7] = "seven";
traducciones[8] = "eight";
traducciones[9] = "nine";
traducciones[10] = "ten";
traducciones[11] = "eleven";
traducciones[12] = "twelve";
traducciones[13] = "thirteen";
traducciones[14] = "fourteen";
traducciones[15] = "fifteen";
traducciones[16] = "sixteen";
traducciones[17] = "seventeen";
traducciones[18] = "eighteen";
traducciones[19] = "nineteen";
traducciones[20] = "twenty";
traducciones[30] = "thirty";
traducciones[40] = "forty";
traducciones[50] = "fifty";
traducciones[60] = "sixty";
traducciones[70] = "seventy";
traducciones[80] = "eighty";
traducciones[90] = "ninety";
traducciones[100] = "hundred";
traducciones[1000] = "thousand";

    int valor = 545;
    numero n(valor);
    std::cout << n.traducir() << std::endl;

    //sumar los caracteres desde 1 hasta 1000
    int suma = 0;
    for (int i = 1; i <= 1000; i++) {
        numero n(i);
        suma += n.traducir().size();
    }
    std::cout << suma << std::endl;
    //...
    return 0;   
}
