# All about Inheritance

## Inline virtual function

explained on g4g: <https://www.geeksforgeeks.org/inline-virtual-function/>

> Whenever virtual function is called using base class reference or pointer 
> it cannot be inlined (because call is resolved at runtime), but whenever 
> called using the object (without reference or pointer) of that class, 
> can be inlined because compiler knows the exact class of the object at 
> compile time.

this "feature" is highlighted by John Lakos' talk about C++ memory arena:

<https://youtu.be/nZNd5FjSquk?t=2149>

see: inline_virtual.cpp
