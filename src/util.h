#ifndef UTIL_H
#define UTIL_H

#include <Python.h>

PyObject *util_dict_pop(PyObject *dict, const char *key);
PyObject *util_dict_pick_off(PyObject *dict, const char *keys[]);
PyObject *util_pick_off_keywords(PyObject *kwargs, const char *kwlist[], ...);

#endif