import ply.lex as lex


tokens = ('TAG', 'INDENT', 'CLASS', 'ID', 'ATTS', 
          'COMMENT', 'TEXT', 'LPAR', 'RPAR', 'DOT', 'SPACE','S_VAR', 'VAR',
          'D_DOT', 'S_C_ATTS', 'INTERPOL', 'ASSIGN', 'IF', 'ELSE', 'DEDENT', 'SAMEDENT',
          'TEXT_INDENT', 'TEXT_DEDENT', 'TEXT_SAMEDENT', 'UNLESS', 'DOCTYPE')


states = (
    ('content', 'exclusive'),
    ('atts', 'exclusive'),
    ('text', 'exclusive'),
    ('multiline', 'exclusive'),
    ('var', 'exclusive'),
    ('assignment', 'exclusive')
)

indent_level = 0
text_indent = 0


def t_DOCTYPE(t):
    r'doctype[ \s]+ (html|xml)'
    return t


def t_IF(t):
    r'if'
    t.lexer.begin('var')
    return t


def t_ELSE(t):
    r'else'
    return t


def t_UNLESS(t):
    r'unless'
    t.lexer.begin('var')
    return t


def t_TAG(t):
    r'[a-z0-9]+\/?'
    t.lexer.begin('content')
    return t


def t_content_ASSIGN(t):
    r'\='
    t.lexer.begin('assignment')
    return t


def t_var_assignment_VAR(t):
    r'[^\n]+'
    t.value = t.value.replace("'",'"')
    t.lexer.begin('INITIAL')
    return t


def t_text_multiline_INTERPOL(t):
    r'\#\{[^\{]+\}'
    return t


def t_content_S_C_ATTS(t):
    r'&attributes'
    return t


def t_content_LPAR(t):
    r'\('
    t.lexer.begin('atts')
    return t


def t_atts_RPAR(t):
    r'\)'
    t.lexer.begin('content')
    return t


def t_atts_ATTS(t):
    r'[^\)]+'
    if '\n' in t.value:
        t.value = t.value.replace(" ","").replace("\n"," ").replace("'",'"').strip()
    else:
        if t.value[0] == '{':
            t.value = t.value.replace('{"','').replace("{'",'').replace('"}','"').replace("'}",'"')
            t.value = t.value.replace('": \'','="').replace('": "','="').replace("': \"",'="').replace("': \'",'="')
            t.value = t.value.replace("', '",'" ').replace("', \"",'" ').replace('", \'','" ').replace('", "','" ')
    return t


def t_INITIAL_content_text_newline(t):
    r'\n[ \t]*'
    t.lexer.begin('INITIAL')
    global indent_level
    if len(t.value) - 1 > indent_level:
        t.type = 'INDENT'
    elif len(t.value) - 1 < indent_level:
        t.type = 'DEDENT'
    else:
        t.type = 'SAMEDENT'

    indent_level = len(t.value) - 1
    return t


def t_multiline_newline(t):
    r'\n[ \t]*'
    global indent_level
    global text_indent
    if len(t.value) - 1 < indent_level:
        if len(t.value) - 1 <= text_indent:
            t.lexer.begin('INITIAL')
            t.type = 'DEDENT'
        else:
            t.type = 'TEXT_DEDENT'
    elif len(t.value) - 1 > indent_level:
        t.type = 'TEXT_INDENT'
    else:
        t.type = 'TEXT_SAMEDENT'
    indent_level = len(t.value) - 1
    return t


def t_S_VAR(t):
    r'\-[ \s]*var[ \s]+'
    t.lexer.begin('var')
    return t


def t_INITIAL_content_ID(t):
    r'\#[a-z][a-zA-Z0-9\-]*'
    t.lexer.begin('content')
    return t


def t_INITIAL_content_CLASS(t):
    r'\.[a-z][a-zA-Z0-9\-]*'
    t.lexer.begin('content')
    return t


def t_content_D_DOT(t):
    r'\:'
    t.lexer.begin('INITIAL')
    return t


def t_content_DOT(t):
    r'\.'
    global indent_level
    global text_indent
    text_indent = indent_level
    t.lexer.begin('multiline')
    return t


def t_content_SPACE(t):
    r'[ \s]'
    t.lexer.begin('text')
    return t 


def t_COMMENT(t):
    r'\/\/\-?'
    t.lexer.begin('text')
    return t


def t_text_multiline_TEXT(t):
    r'[^\n\#]+'
    return t




t_INITIAL_assignment_var_ignore = ' '

t_content_atts_text_multiline_ignore = ''

def t_ANY_error(t):
    print(f"Invalid token: {t.value[0]}")
    t.lexer.skip(1)

lexer = lex.lex()