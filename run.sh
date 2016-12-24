yacc -d new.y
lex new.l
gcc lex.yy.c y.tab.c -w
./a.out input
