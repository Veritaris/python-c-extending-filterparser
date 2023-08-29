#include <Python.h>

typedef struct parsed_filter_s parsed_filter_t;

extern int filter_type;
extern char *filter_value;
extern char *filter_key;

static PyObject *parse(PyObject *self, PyObject *args);

struct parsed_filter_s {
    PyObject_HEAD
    int filter_type;
    char *filter_value;
    char *filter_key;
};