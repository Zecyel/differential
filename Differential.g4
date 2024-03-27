grammar Differential;

prog: expr EOF;

expr: NUMBER                    # number
    | expr '^' expr             # power
    | expr op=('*' | '/') expr  # mul_div
    | expr op=('+' | '-') expr  # add_sub
    | '(' expr ')'              # brackets
    | NAME '(' expr ')'         # func
    | NAME                      # var
    ;

NUMBER: [0-9]+;
NAME: [a-z]+;
NEWLINE : [\r\n]+ -> skip;