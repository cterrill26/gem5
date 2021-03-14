#ifndef __MATRIX_UNIT_HH__
#define __MATRIX_UNIT_HH__

class MatrixUnit{
public:
  float a[16];
  float b[16];
  float c[16];

  void multiply(){
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        float sum = 0;
        for (int k = 0; k < 4; ++k) {
          sum += a[i * 4 + k] * b[k * 4 + j];
        }
        c[i * 4 + j] += sum;
      }
    }
  }
};

#endif //__MATRIX_UNIT_HH__
