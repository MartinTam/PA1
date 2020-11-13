g++ -Wall -pedantic main.c -g -fsanitize=address    # pametovy debugger 01 #
./main.out 'wrongInput'


valgrind ./main.out 'wrongInput'                    # pametovy debugger 02 #


export ASAN_OPTIONS= 'abort_on_error=1'             # debugger #
cgdb main.out
->('wrongInput')
->(p variable1)
->(p variable1 * variable2)
