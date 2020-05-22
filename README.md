# Author: Gaurav Dawra
# Rollno.: 2019039

This project is an OOP implemetaion of the various cache types. 
It provides an API 
to declare a cache structure of one of the following types:
    1. Associative cache
    2. Directive cache
    3. n-way Associative cache 

# NOTE : It has been assumed that the machine is 1 32-bit machine
# We can change the word size by changing the value of the constant `WORD_SIZE` 
# in "resources.cpp"


# The cache "class" has the following prototype:
#    template<type T> cache<T>

`type` is is an enum which can take three values:
    1. associative = 0,
    2. directive,
    3. n_wayAssociative

The cache class is intialized with the parameters 
 - CL : number of lines
 - B : block size

The size of the cache is CL * B
In case of n-way Associative cache, the input also requires 'n' as an input

The cache class derives from the following three classes publically:
    1. associativeCache
    2. directiveCache
    3. n_wayAssociativeCache

The following are the functionalities provided by the cache<T> class:

 - **read <address>** : this command reads the content at the address if the address if    
 present in the cache (that is in the case of a cache HIT). Otherwise, in case of 
 cache MISS, no replacement takes place (since main memory has not been maintained, 
 and the original contents cannot be read).

 - **write <address> <data>** : this command writes the contents of data (of type int) at 
 the address if the address is present in the cache (that is, in case of a cache HIT). 
 Otherwise, in case of a MISS, it loads the particular address in the cache. If an empty 
 slot is present, it loads the new address in this neempty slot. Otherwise, it replaces 
 a slot in the cache with the new address.

# NOTE: all replacements take place in FIFO order

# USER INTERFACE:

The user interface is implemented in _"main.cpp"_. To compile and run the files, 
we have to run the command _"./compile"_. _"compile.ssh"_ is a bash file which takes 
care of the compilation.
The exe file asks for an input for the choice of cache to be used.
The program then takes the required inputs as described above.

The two functionalities of `read` and `write` function as described above. In case of 
MISS while wrting or reading, the program prompts the same in the console.

# Note that the replacements take place only in case of a `WRITE MISS` and not in case 
# of a `READ MISS`.