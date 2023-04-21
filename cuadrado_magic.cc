#include <iostream>
#include <vector>

#define MATRIX_V std::vector<std::vector<int>>

bool check_is_magic(MATRIX_V matrix_aux, int& magia) {
  // Suma fila
  int valor_magico = 0;
  int valor_aux_f = 0;
  int valor_aux_c = 0;
  bool flag_d = false;
  int valor_dp = 0;
  int valor_ds = 0;
  for (int i = 0; i < matrix_aux.size(); i++) valor_magico += matrix_aux[0][i];
  magia = valor_magico;
  for (int i = 0; i < matrix_aux.size(); i++) {
    valor_aux_f = 0;
    valor_aux_c = 0;
    for (int j = 0; j < matrix_aux.size(); j++) {
      valor_aux_f += matrix_aux[i][j];
      valor_aux_c += matrix_aux[j][i];
      if (flag_d == false) {
        valor_dp += matrix_aux[j][j];
        valor_ds += matrix_aux[j][matrix_aux.size() - 1 - j];
      }
    }
    flag_d = true;
    if (valor_aux_f != valor_magico || valor_aux_c != valor_magico ||
        valor_dp != valor_magico || valor_ds != valor_magico)
      return false;
  }
  return true;
}

bool check_is_esoterico(MATRIX_V matrix_aux, int magia) {
  int size_m = matrix_aux.size();
  if (size_m == 0) {
    return false;
  }
  int red = matrix_aux[0][0] + matrix_aux[0][size_m - 1] +
            matrix_aux[size_m - 1][0] + matrix_aux[size_m - 1][size_m - 1];
  int green = matrix_aux[0][size_m / 2] + matrix_aux[size_m / 2][0] +
              matrix_aux[size_m / 2][size_m - 1] +
              matrix_aux[size_m - 1][size_m / 2];
  int yellow = matrix_aux[size_m / 2][size_m / 2];
  if (matrix_aux.size() % 2 == 0) {
    green += matrix_aux[0][(size_m / 2) - 1] + matrix_aux[(size_m / 2) - 1][0] +
             matrix_aux[(size_m / 2) - 1][size_m - 1] +
             matrix_aux[size_m - 1][(size_m / 2) - 1];
    yellow += matrix_aux[(size_m / 2) - 1][(size_m / 2) - 1] +
              matrix_aux[(size_m / 2)][(size_m / 2) + 1] +
              matrix_aux[(size_m / 2) - 1][(size_m / 2)];
  } else {
    yellow *= 4;
    if (red != yellow || red != green) {
      return false;
    }
    return true;
  }
  if (red != yellow || (green * 2) != magia) {
    return false;
  }
  return true;
}

void print_vector(MATRIX_V aux) {
  for (auto i : aux) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

int main() {
  MATRIX_V matrix;
  int size_matrix;
  int value_aux;
  int magia;
  while (std::cin >> size_matrix) {
    if (size_matrix == 0) break;
    for (int i = 0; i < size_matrix; i++) {
      std::vector<int> aux_vector;
      for (int j = 0; j < size_matrix; j++) {
        std::cin >> value_aux;

        aux_vector.push_back(value_aux);
      }
      matrix.push_back(aux_vector);
    }
    if (check_is_magic(matrix,magia)) {
      if (check_is_esoterico(matrix,magia)) {
        std::cout << "ESOTERICO\n";
      } else {
        std::cout << "DIABOLICO\n";
      }
    } else {
      std::cout << "NO\n";
    }
    for (int i = 0; i < matrix.size(); i++) {
      matrix[i].clear();
    }
    matrix.clear();
  }

  return 0;
}
