#include <pybind11/pybind11.h>
#include <lib/PerformaxCom.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(py_performax, m) {
    m.doc() = R"pbdoc(
        Pybind11 performax
        -----------------------

        .. currentmodule:: py_performax

        .. autosummary::
           :toctree: _generate

           fnPerformaxComGetNumDevices
    )pbdoc";

    // BOOL fnPerformaxComGetNumDevices(OUT LPDWORD lpNumDevices);

    m.def("get_num_devices", &fnPerformaxComGetNumDevices, R"pbdoc(
        Get performax devices

        This function is used to get total number of all types of Performax and
        Performax USB modules connected to the PC.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
