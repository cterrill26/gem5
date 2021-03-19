#ifndef __MATRIX_UNIT_HH__
#define __MATRIX_UNIT_HH__

#include <cstdio>

class Mat{
public:
  int vals[16];
};

class Vec{
public:
  int vals[4];
};

class MatrixUnit{
public:
  Mat a;
  Mat b;
  Mat c;
  //int scalar;
  //int vector[4];

  void multiply(){
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        int sum = 0;
        for (int k = 0; k < 4; ++k) {
          sum += a.vals[i * 4 + k] * b.vals[k * 4 + j];
        }
        c.vals[i * 4 + j] += sum;
      }
    }
  }

  void add(){
    for (int i = 0; i < 4; ++i) {
      int row = i * 4;
      for (int j = 0; j < 4; ++j) {
        int index = row + j;
        c.vals[index] = a.vals[index] + b.vals[index];
      }
    }
  }

  void transposea(){
        for (int i = 0; i < 4; ++i) {
          for (int j = 0; j < 4; ++j) {
            c.vals[i * 4 + j] = a.vals[j * 4 + i];
            c.vals[j * 4 + i] = a.vals[i * 4 + j];
          }
        }
  }


  void transposeb(){
        for (int i = 0; i < 4; ++i) {
          for (int j = 0; j < 4; ++j) {
            c.vals[i * 4 + j] = b.vals[j * 4 + i];
            c.vals[j * 4 + i] = b.vals[i * 4 + j];
          }
        }
  }


  void matrix_vector_product(){
    for (int i = 0; i < 4; ++i) {
        int sum = 0;
        int row = i * 4;
        for (int j = 0; j < 4; ++j) {
           sum += a.vals[row + j] * b.vals[j];
        }
        c.vals[i] += sum;
    }
  }

  void matrix_scalar_multiplya(int param) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          c.vals[i * 4 + j] = a.vals[i * 4 + j] * param;
        }
      }
  }

  void matrix_scalar_multiplyb(int param) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          c.vals[i * 4 + j] = b.vals[i * 4 + j] * param;
        }
      }
  }

};

#endif //__MATRIX_UNIT_HH__
