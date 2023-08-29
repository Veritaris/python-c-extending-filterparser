#include <Python.h>
#include "struct.c"

static PyObject *
parse(PyObject *self, PyObject *args) {
    const char *command;
    int sts = 0;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;


    return PyLong_FromLong(sts);
}

static PyMethodDef filterparserMethods[] = {
        {
                "parse",
                parse,
                METH_VARARGS,
                "Parse filter input into {filter_type, filter_value, filter_key} struct"
        },
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef filterparsermodule = {
        PyModuleDef_HEAD_INIT,
        "parse",
        "filter parser",
        -1,
        filterparserMethods
};

PyMODINIT_FUNC
PyInit_filterparser(void) {
    PyObject *module = PyModule_Create(&filterparsermodule);

    if (PyType_Ready(&parsed_filter_t_Type) < 0) {
        return NULL;
    }

    Py_INCREF(&parsed_filter_t_Type);
    PyModule_AddObject(
            module,
            "parsed_filter",
            (PyObject *) &parsed_filter_t_Type
    );

    return module;
}