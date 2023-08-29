#include <structmember.h>
#include "Python.h"
#include "library.h"

static void
parsed_filter_dealloc(parsed_filter_t *self) {
    Py_TYPE(self)->tp_free((PyObject *) self);
};

static PyObject *
parsed_filter_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    parsed_filter_t *self;
    self = (parsed_filter_t *) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->filter_type = 0;
        self->filter_value = "";
        self->filter_key = "";
    }

    return (PyObject *) self;
};

static int
parsed_filter_init(parsed_filter_t *self, PyObject *args, PyObject *kwds) {
    static char *kwlist[] = {"filter_type", "filter_value", "filter_key", NULL};
    if (!PyArg_ParseTupleAndKeywords(
            args,
            kwds,
            "|idb",
            kwlist, &self->filter_type, &self->filter_value,
                                     &self->filter_key)) {
        return -1;
    }
    return 0;
};

static PyMemberDef parsed_filter_t_members[] = {
        {"filter_type",  T_INT,    offsetof(parsed_filter_t, filter_type),  0, "int"},
        {"filter_value", T_STRING, offsetof(parsed_filter_t, filter_value), 0, "str"},
        {"filter_key",   T_STRING, offsetof(parsed_filter_t, filter_key),   0, "str"},
        {NULL}
};

static PyObject *parsed_filter_s_print(PyObject *self, PyObject *args) {
    parsed_filter_t *st;

    if (!PyArg_ParseTuple(args, "O", &st)) {
        Py_RETURN_NONE;
    }

    printf("method: filter_type: %d, filter_value: %s, filter_key: %s\n", st->filter_type, st->filter_value,
           st->filter_key);
    Py_RETURN_NONE;
};

static PyMethodDef parsed_filter_t_methods[] = {
        {"print", parsed_filter_s_print, METH_VARARGS, "test print"},
        {NULL}
};

PyTypeObject parsed_filter_t_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
        "filterparser.parsed_filter",
        sizeof(parsed_filter_t),
        0,
        (destructor) parsed_filter_dealloc,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        parsed_filter_t_methods,
        parsed_filter_t_members,
        0,
        0,
        0,
        0,
        0,
        0,
        (initproc) parsed_filter_init,
        0,
        parsed_filter_new
};
