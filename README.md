# Block-LoadLibrary
code that replaces the first opcode of all functions related to ```LoadLibrary``` with ```0xC3``` (return), this means that no dlls can be loaded/injected using the loadlibrary injection method
