#!/usr/bin/python3
def complex_delete(a_dictionary, value):
    key_list = list(a_dictionary.keys())

    for key_val in key_list:
        if value == a_dictionary.get(key_val):
            del a_dictionary[key_val]
    return a_dictionary
