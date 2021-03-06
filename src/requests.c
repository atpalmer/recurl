#include <Python.h>
#include "requests.h"

PyObject *
_import_obj(const char *modname, const char *objname)
{
    PyObject *mod = PyImport_ImportModule(modname);
    if (!mod)
        return NULL;
    PyObject *obj = PyObject_GetAttrString(mod, objname);
    if (!obj)
        return NULL;
    return obj;
}

PyObject *
_import_default_instance(const char *modname, const char *typename)
{
    PyObject *typeobj = _import_obj(modname, typename);
    if (!typeobj)
        return NULL;
    PyObject *new = PyObject_CallNoArgs(typeobj);
    if (!new)
        return NULL;
    return new;
}

PyObject *
RequestsMod_Response_InitNew(RequestsMod_ResponseArgs *args)
{
    /*
     * requests.Request attributes:
     * - '_content'     // TODO: support streaming content
     * - 'status_code'  // done
     * - 'headers'      // done
     * - 'url'          // done
     * - 'history',     // TODO
     * - 'encoding'     // done
     * - 'reason'       // done
     * - 'cookies'      // TODO
     * - 'elapsed'      // set by requests.Session.send
     * - 'request'      // done
     */
    PyObject *response = _import_default_instance("requests", "Response");
    if (!response)
        return NULL;

    if (PyObject_SetAttrString(response, "_content", args->content) < 0)
        return NULL;
    if (PyObject_SetAttrString(response, "status_code", args->status_code) < 0)
        return NULL;
    if (PyObject_SetAttrString(response, "headers", args->headers) < 0)
        return NULL;
    if (PyObject_SetAttrString(response, "url", args->url) < 0)
        return NULL;
    if (PyObject_SetAttrString(response, "reason", args->reason) < 0)
        return NULL;
    if (PyObject_SetAttrString(response, "request", args->request) < 0)
        return NULL;
    if (PyObject_SetAttrString(response, "encoding", args->encoding) < 0)
        return NULL;

    return response;
}

PyObject *
RequestsMod_CaseInsensitiveDict_New(void)
{
    return _import_default_instance("requests.structures", "CaseInsensitiveDict");
}

PyObject *
RequestsMod_Session_New(void)
{
    return _import_default_instance("requests", "Session");
}

PyObject *
RequestsMod_get_encoding_from_headers(PyObject *headers)
{
    PyObject *func = _import_obj("requests.utils", "get_encoding_from_headers");
    if (!func)
        return NULL;
    /* Returns encoding as PyUnicode object */
    return PyObject_CallOneArg(func, headers);
}

PyObject *
RequestsMod_select_proxy(PyObject *url, PyObject *proxies)
{
    if (!url)
        return NULL;
    if (!proxies)
        return NULL;
    PyObject *func = _import_obj("requests.utils", "select_proxy");
    if (!func)
        return NULL;
    return PyObject_CallFunctionObjArgs(func, url, proxies, NULL);
}

PyObject *
RequestsMod_exception(const char *name)
{
    return _import_obj("requests.exceptions", name);
}
