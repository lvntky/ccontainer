# -- ccontainer amalgamete helper script --
# This helper script iterates include/ccontainer directory
# Copies all header files
# And creates one single .h file which named `ccontainer_amalgamate.h` out of it
# Into the curret directory or specified directory
# By this way you can use all the container types without
# explicity including them.

import os

ccontainer_amalgamate_header = open("ccontainer_amalgamate.h", 'a') # use append
INCLUDE_PATH =  "./include/ccontainer/"

for header in os.listdir(INCLUDE_PATH):
    if header.endswith(".h"):
        # copy the content
        # write to amalgamate header
        header_content = open(INCLUDE_PATH + header, 'r')
        ccontainer_amalgamate_header.write(header_content.read())
        continue
    else :
        continue
