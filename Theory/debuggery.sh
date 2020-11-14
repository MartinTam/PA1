g++ -Wall -pedantic main.c -g -fsanitize=address    # === PAMETOVY DEBUGGER 01 === #
./main.out 'wrongInput'


valgrind ./main.out 'wrongInput'                    # === PAMETOVY DEBUGGER 02 === #
                                                    # neni potreba pouzit prepinac '-g' pri kompilaci #


export ASAN_OPTIONS= 'abort_on_error=1'             # === DEBUGGER === #
cgdb main.out
->('wrongInput')
->(p variable1)                                     # vypsat hodnotu promenne v danou chvili #
->(p variable1 * variable2)



g++ -Wall -pedantic main.c -g                       # === DEBUGGER === #
gdb ./main.out
->(break main.c:18)                                 # zastavit program na radce 18 #
->(r)                                               # spustit program #
->('wrongInput')                                    # zadat vstup s vadnym vystupem #
->(print variable)                                  # vypsat hodnotu promenne v danou chvili #
->(display variable)                                # sledovat hodnotu promenne v case #
->(n)                                               # 'next' dalsi krok programu #
->(q)                                               # 'quit' debugger #
