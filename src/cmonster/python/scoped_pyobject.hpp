/*
Copyright (c) 2011 Andrew Wilkins <axwalk@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _CMONSTER_PYTHON_SCOPED_PYOBJECT_HPP
#define _CMONSTER_PYTHON_SCOPED_PYOBJECT_HPP

#include <Python.h>

namespace cmonster {
namespace python {

struct ScopedPyObject
{
    ScopedPyObject(PyObject *ref) throw() : m_ref(ref) {}
    ~ScopedPyObject() throw() {Py_XDECREF(m_ref);}
    operator PyObject* () const throw() {return m_ref;}

    PyObject* get() throw()
    {
        return m_ref;
    }

    // Release the return object.
    PyObject* release() throw()
    {
        PyObject *ref = m_ref;
        m_ref = NULL;
        return ref;
    }

private:
    PyObject *m_ref;
};

}}

#endif

