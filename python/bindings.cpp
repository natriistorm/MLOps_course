#include "pearson.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(corellations_core, m) {
  m.doc() = R"doc(
    Python bindings for Correlations library
  )doc";

  py::class_<Correlations>(m, "Correlations")
      .def_static("pearsonCorrelation", &Correlations::pearsonCorrelation, R"doc(
          Compute pearson correlation using pure C++.

          Parameters:
            a : list of float
                The first vector.
            b : list of float
                The second vector.

          Returns:
            float
                The pearson correlation of the two vectors.
      )doc")
}