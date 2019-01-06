#include <Python.h>

static PyObject *
greet_name(PyObject *self, PyObject *args)
{
    const char *name;
    double a;
    double b;
    double c;
    a = 0.1;
    b = 0.2;
    c = 0.0;

    if (!PyArg_ParseTuple(args, "s", &name))
    {
        return NULL;
    }

    for (unsigned int i = 0; i < 100500; ++i)
    {
        c = c + (a + b);
        printf("num is  %d!\n", i);
    }

    printf("Hello %s!\n", name);
    printf("Sum is %f\n", c);

    Py_RETURN_NONE;
}

static PyMethodDef GreetMethods[] = {
    {"greet", greet_name, METH_VARARGS, "Greet an entity."},
    {NULL, NULL, 0, NULL}};

PyMODINIT_FUNC initgreet(void)
{
    (void)Py_InitModule("greet", GreetMethods);
}