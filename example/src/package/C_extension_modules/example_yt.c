#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

static PyObject *add(PyObject *self, PyObject *args)
{
    int x;
    int y;

    if (!PyArg_ParseTuple(args, "ii", &x, &y))
        return NULL;

    return PyLong_FromLong((long)(x + y));
}

static PyMethodDef AddMethods[] = {
    {"add", add, METH_VARARGS,
     "Add two numbers"},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef addmodule = {
    PyModuleDef_HEAD_INIT,
    "c_add",           /* name of module */
    "Adds to numbers", /* module documentation, may be NULL */
    -1,                /* size of per-interpreter state of the module,
                          or -1 if the module keeps state in global variables. */
    AddMethods};

PyMODINIT_FUNC PyInit_c_add(void)
{
    printf("Hello world\n");
    return PyModule_Create(&addmodule);
}