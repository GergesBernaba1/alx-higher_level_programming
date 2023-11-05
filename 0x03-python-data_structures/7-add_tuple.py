#!/usr/bin/python3
def add_tuple(tuple_a=(), tuple_b=()):
    # Ensure that the tuples have at least two elements, and if not, use 0 as the default value.
    a = tuple_a + (0, 0)
    b = tuple_b + (0, 0)
    
    # Add the elements of the tuples and create a new tuple with the results.
    result_tuple = (a[0] + b[0], a[1] + b[1])
    
    return result_tuple
