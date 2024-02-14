import ply.lex as lex
    

tokens = (
    # comments
    'ML_COMMENT','SL_COMMENT',
    # "brackets"
    'L_BRACKET', 'R_BRACKET', 'L_BRACE', 'R_BRACE', 'L_PARENT', 'R_PARENT',
    # types
    'INT', 'CHAR', 'FLOAT', 'NUM', 'REAL',
    # loops
    'WHILE', 'FOR',
    # operations / assignments
    'SUM', 'SUB', 'MUL', 'DIV', 'RANGE', 'ASSIGN',
    # conditions
    'IF', 'GREATER', 'LESS', 'IN',
    # key words
    'FUNCTION', 'PROGRAM', 'PRINT',
    # punctuation
    'COMMA', 'SEMICOLON',
    # registered
    'REGISTERED'
    )


t_ML_COMMENT = r'\/\*[\w\W]*\*\/'
t_SL_COMMENT = r'\/\/.*'


t_L_BRACKET = r'\['
t_R_BRACKET = r'\]'
t_L_BRACE = r'\{'
t_R_BRACE = r'\}'
t_L_PARENT = r'\('
t_R_PARENT = r'\)'


def t_INT(t):
    r'int\s\w+'
    t.value = t.value[4:]
    lexer.cache.append(t.value)
    return t

def t_CHAR(t):
    r'char\s\w+'
    t.value = t.value[5:]
    lexer.cache.append(t.value)
    return t

def t_FLOAT(t):
    r'float\s\w+'
    t.value = t.value[6:]
    lexer.cache.append(t.value)
    return t

def t_NUM(t):
    r'-?\d+'
    t.value = int(t.value)
    return t

def t_REAL(t):
    r'-?\d+\.\d+'
    t.value = float(t.value)
    return t


def t_WHILE(t): 
    r'while'
    return t

def t_FOR(t): 
    r'for'
    return t


t_SUM = r'\+'
t_SUB = r'\-'
t_MUL = r'\*'
t_DIV = r'\/'
t_RANGE = r'\.\.'
t_ASSIGN = r'='


def t_IF(t): 
    r'if'
    return t

t_GREATER = r'>'
t_LESS = r'<'

def t_IN(t): 
    r'in'
    return t


def t_FUNCTION(t):
    r'function\s\w+'
    t.value = t.value[9:]
    lexer.cache.append(t.value)
    return t

def t_PROGRAM(t):
    r'program\s\w+'
    t.value = t.value[8:]
    lexer.cache.append(t.value)
    return t

def t_PRINT(t):
    r'print'
    return t


t_COMMA = r'\,'
t_SEMICOLON = r'\;'


def t_REGISTERED(t):
    r'\w+'
    if not t.value in lexer.cache:
        print(f"Can't recognize: {t.value}")



t_ignore = ' \t\n'

def t_error(t):
    print(f'Invalid token: {t.value}')
    t.lexer.skip(1)

lexer = lex.lex()

data1 = '''/* factorial.p
-- 2023-03-20 
-- by jcr
*/

int i;

// Função que calcula o factorial dum número n
function fact(n){
  int res = 1;
  while res > 1 {
    res = res * n;
    res = res - 1;
  }
}

// Programa principal
program myFact{
  for i in [1..10]{
    print(i, fact(i));
  }
}'''

data2 = '''/* max.p: calcula o maior inteiro duma lista desordenada
-- 2023-03-20 
-- by jcr
*/

int i = 10, a[10] = {1,2,3,4,5,6,7,8,9,10};

// Programa principal
program myMax{
  int max = a[0];
  for i in [1..9]{
    if max < a[i] {
      max = a[i];
    }
  }
  print(max);
}'''


lexer.input(data1)
lexer.cache = list()


while tok := lexer.token():
    print(tok)