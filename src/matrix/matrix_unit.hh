#include <cfloat>

#ifndef __MATRIX_UNIT_HH__
#define __MATRIX_UNIT_HH__

class MatrixUnit{
public:
  int a[16];
  int b[16];
  int c[16];
  //int scalar;
  //int vector[4];

  void multiply(){
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        int sum = 0;
        for (int k = 0; k < 4; ++k) {
          sum += a[i * 4 + k] * b[k * 4 + j];
        }
        c[i * 4 + j] += sum;
      }
    }
  }

  void add(){
    for (int i = 0; i < 4; ++i) {
      int row = i * 4;
      for (int j = 0; j < 4; ++j) {
        int index = row + j;
        c[index] = a[index] + b[index];
      }
    }
  }

  void transposea(){
        for (int i = 0; i < 4; ++i) {
          for (int j = 0; j < 4; ++j) {
            c[i * 4 + j] = a[j * 4 + i];
            c[j * 4 + i] = a[i * 4 + j];
          }
        }
  }


  void transposeb(){
        for (int i = 0; i < 4; ++i) {
          for (int j = 0; j < 4; ++j) {
            c[i * 4 + j] = b[j * 4 + i];
            c[j * 4 + i] = b[i * 4 + j];
          }
        }
  }


  void matrix_vector_product(){
    for (int i = 0; i < 4; ++i) {
        int sum = 0;
        int row = i * 4;
        for (int j = 0; j < 4; ++j) {
           sum += a[row + j] * b[j];
        }
        c[i] += sum;
    }
  }

  void matrix_scalar_multiplya(int param) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          c[i * 4 + j] = a[i * 4 + j] * param;
        }
      }
  }

  void matrix_scalar_multiplyb(int param) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          c[i * 4 + j] = b[i * 4 + j] * param;
        }
      }
  }

};

#endif //__MATRIX_UNIT_HH__
