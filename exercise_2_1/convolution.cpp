#include "convolution.h"

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {
  std::vector<double> y;
  int offset = w.size() / 2;
  for (int i = 0; i < x.size(); i++) { // start convolve
    int wIndex = 0;
    double sum = 0;
    for (int j = i - offset; wIndex < w.size(); j++) {
      double xElement;
      if (j < 0 | j > x.size() - 1) {
        if (pack_with_zeros) {
          xElement = 0;
        } else {
          if (j < 0) {
            xElement = x[0];
          } else {
            xElement = x[x.size() - 1];
          }
        }
      } else {
        xElement = x[j];
      }

      double wElement = w[wIndex];
      sum += xElement * wElement;
      wIndex++;
    }
    y.push_back(sum);
  }
  return y;
}

