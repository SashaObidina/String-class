# This file was automatically generated by SWIG (http://www.swig.org).
# Version 4.0.2
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info < (2, 7, 0):
    raise RuntimeError("Python 2.7 or later required")

# Import the low-level C/C++ module
if __package__ or "." in __name__:
    from . import _mystring
else:
    import _mystring

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "thisown":
            self.this.own(value)
        elif name == "this":
            set(self, name, value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass"""
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """Meta class to enforce nondynamic attributes (no new attributes) for a class"""
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)


UNIT = _mystring.UNIT
class MyString(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def __init__(self, *args):
        _mystring.MyString_swiginit(self, _mystring.new_MyString(*args))
    __swig_destroy__ = _mystring.delete_MyString

    def __add__(self, *args):
        return _mystring.MyString___add__(self, *args)

    def __iadd__(self, *args):
        return _mystring.MyString___iadd__(self, *args)

    def __gt__(self, *args):
        return _mystring.MyString___gt__(self, *args)

    def __lt__(self, *args):
        return _mystring.MyString___lt__(self, *args)

    def __ge__(self, *args):
        return _mystring.MyString___ge__(self, *args)

    def __le__(self, *args):
        return _mystring.MyString___le__(self, *args)

    def __eq__(self, *args):
        return _mystring.MyString___eq__(self, *args)

    def __ne__(self, *args):
        return _mystring.MyString___ne__(self, *args)

    def C_str(self):
        return _mystring.MyString_C_str(self)

    def c_str(self, str):
        return _mystring.MyString_c_str(self, str)

    def data(self):
        return _mystring.MyString_data(self)

    def length(self):
        return _mystring.MyString_length(self)

    def Size(self):
        return _mystring.MyString_Size(self)

    def empty(self):
        return _mystring.MyString_empty(self)

    def capacity(self):
        return _mystring.MyString_capacity(self)

    def shrink_to_fit(self, new_size):
        return _mystring.MyString_shrink_to_fit(self, new_size)

    def clear(self):
        return _mystring.MyString_clear(self)

    def capacity_set(self, size):
        return _mystring.MyString_capacity_set(self, size)

    def strlen(self, str):
        return _mystring.MyString_strlen(self, str)

    def insert(self, *args):
        return _mystring.MyString_insert(self, *args)

    def erase(self, index, count):
        return _mystring.MyString_erase(self, index, count)

    def append(self, *args):
        return _mystring.MyString_append(self, *args)

    def replace(self, *args):
        return _mystring.MyString_replace(self, *args)

    def substr(self, *args):
        return _mystring.MyString_substr(self, *args)

    def find(self, *args):
        return _mystring.MyString_find(self, *args)

# Register MyString in _mystring:
_mystring.MyString_swigregister(MyString)


