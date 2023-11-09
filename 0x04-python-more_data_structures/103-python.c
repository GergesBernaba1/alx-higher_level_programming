#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
void print_python_list(PyObject *p)
{
	Py_ssize_t size, allocated, i;
	PyObject *element;
	size = PyList_Size(p);
	allocated = ((PyListObject *)p)->allocated;
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", allocated);
	for (i = 0; i < size; i++)
	{
		element = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, element->ob_type->tp_name);
		if (PyBytes_Check(element))
			print_python_bytes(element);
	}
}
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *string;
	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = ((PyVarObject *)p)->ob_size;
	string = PyBytes_AsString(p);
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", string);
	if (size < 10)
	{
		printf("  first %ld bytes: ", size + 1);
		for (i = 0; i <= size; i++)
		{
			printf("%02x", string[i] & 0xff);
			if (i < size)
				printf(" ");
		}
		printf("\n");
	}
	else
	{
		printf("  first 10 bytes: ");
		for (i = 0; i < 10; i++)
		{
			printf("%02x", string[i] & 0xff);
			if (i < 9)
				printf(" ");
		}
		printf("\n");
	}
}

