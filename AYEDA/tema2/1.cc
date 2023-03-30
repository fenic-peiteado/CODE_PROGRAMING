#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//  Suponga que un vector ordenado de mayor a menor puede tener elementos
// repetidos.Implemente un algoritmo que usando la búsqueda binaria muestre
// todas las posiciones en las que se encuentra un determinado valor,
// si está.

int bus_binaria(int x, std::vector<int>);

int main() {
  // Creamos el vector con valores aleatorios
  std::vector<int> v(20);
  for (int i = 0; i < 20; i++) {
    v[i] = rand() % 10;
  }
  // Ordenamos el vector de mayor a menor
  std::sort(v.begin(), v.end(), std::greater<int>());
  // Mostramos el vector
  for (int i = 0; i < 20; i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  // Pedimos el valor a buscar
  int valor;
  std::cout << "Introduzca el valor a buscar: ";
  std::cin >> valor;
  // Buscamos el valor con busqueda binaria
  std::cout <<"El numero fue : " <<bus_binaria(valor, v) << "\n";

  return 0;
}
//El 
int bus_binaria(int x, std::vector<int> v1) {
  int ini = 0;
  int fin = v1.size() - 1;
  int pos = (ini + fin / 2);
  while (ini < fin) {
    pos = (ini + fin) / 2;
    if (v1[pos] < x) {
      fin = pos - 1;
    } else if (v1[pos] > x) {
      ini = pos + 1;
    } else {
      ini = pos;
      fin = pos;
    }
  }
  // Buscamo a la izquierda y derecha
  int contador = 0;
  if (v1[pos] == x) {
    contador++;
    int der = pos;
    int izd = pos;
    while (der + 1 < v1.size() && v1[der + 1] == x) {
      contador++;
      der++;
    }
    while (izd - 1 >= 0 && v1[izd - 1] == x) {
      contador++;
      izd++;
    }
  }
  return contador;
}