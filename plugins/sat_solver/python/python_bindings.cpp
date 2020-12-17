#include "hal_core/netlist/netlist.h"
#include "hal_core/netlist/gate.h"
#include "sat_solver/plugin_sat_solver.h"
#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "pybind11/stl_bind.h"

#include "hal_core/python_bindings/python_bindings.h"

#include <map>
namespace py = pybind11;

namespace hal
{
    // the name in PYBIND11_MODULE/PYBIND11_PLUGIN *MUST* match the filename of the output library (without extension),
    // otherwise you will get "ImportError: dynamic module does not define module export function" when importing the module

#ifdef PYBIND11_MODULE
    PYBIND11_MODULE(sat_solver, m)
    {
        m.doc() = "hal SATSolver python bindings";
#else
    PYBIND11_PLUGIN(sat_solver)
    {
        py::module m("sat_solver", "hal SATSolver python bindings");
#endif    // ifdef PYBIND11_MODULE

        py::class_<SATSolver, RawPtrWrapper<SATSolver>, BasePluginInterface>(m, "SATSolver")
            .def_property_readonly("name", &SATSolver::get_name)
            .def("get_name", &SATSolver::get_name)
            .def_property_readonly("version", &SATSolver::get_version)
            .def("get_version", &SATSolver::get_version)
            .def("find_key_configuration", &SATSolver::find_key_configuration);

#ifndef PYBIND11_MODULE
        return m.ptr();
#endif    // PYBIND11_MODULE
    }
}    // namespace hal
