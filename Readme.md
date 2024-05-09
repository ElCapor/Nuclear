# Nuclear
An attempt at writing an efficient library for nuclear reactor physics calculations

# Building
- Have a working C++ Compiler (Preferrably MSVC or GCC)
- Xmake Dev installed [From Here](https://github.com/xmake-io/xmake)
- run `xmake` in your favorite terminal
  
This will generate Test.exe (Unit tests) and Reactor.exe (Demo App)

# Structure
```
- src (main code)
    - main.cpp (Reactor entry)
    - test.cpp (Test entry)

- extern
    - vendor
        - doctest (unit testing library)
        - nuclear (this library)

```

UML Diagram can be found here : [UML Diagram](https://github.com/ElCapor/ReactorUML/tree/main)


# Notes to myself
Every data should be possibly loaded at run time from lua tables

# Credit
@SrAzber - All the calculations and original lua code

@ElCapor - C++ Port