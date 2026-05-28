# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rsysmsg:msg/Fighting.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'pone'
# Member 'ptwo'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Fighting(type):
    """Metaclass of message 'Fighting'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rsysmsg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rsysmsg.msg.Fighting')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fighting
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fighting
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fighting
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fighting
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fighting

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Fighting(metaclass=Metaclass_Fighting):
    """Message class 'Fighting'."""

    __slots__ = [
        '_pone',
        '_ptwo',
    ]

    _fields_and_field_types = {
        'pone': 'sequence<int32>',
        'ptwo': 'sequence<int32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pone = array.array('i', kwargs.get('pone', []))
        self.ptwo = array.array('i', kwargs.get('ptwo', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pone != other.pone:
            return False
        if self.ptwo != other.ptwo:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pone(self):
        """Message field 'pone'."""
        return self._pone

    @pone.setter
    def pone(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'pone' array.array() must have the type code of 'i'"
            self._pone = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'pone' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._pone = array.array('i', value)

    @builtins.property
    def ptwo(self):
        """Message field 'ptwo'."""
        return self._ptwo

    @ptwo.setter
    def ptwo(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'ptwo' array.array() must have the type code of 'i'"
            self._ptwo = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'ptwo' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._ptwo = array.array('i', value)
