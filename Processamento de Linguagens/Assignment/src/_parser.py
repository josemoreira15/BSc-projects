import ply.yacc as yacc
from _lexer import tokens

tag_stack = []
second_stack = []
indent_level = 0
min_indent = 0
vars = {}
state = 'normal'
state_indent = -1
tag_state = ''
var_stack = []
space = ' '
comment = 0



def p_html(p):
    '''
    html : content
    '''
    global tag_stack
    global space
    p[0] = ''
    if len(tag_stack) > 0:
        p[0] += p[1] + f'</{tag_stack.pop()[0]}>'
        while len(tag_stack) > 0:
            last_tag = tag_stack.pop()
            spaces = last_tag[1] * space
            p[0] += '\n' + spaces + f'</{last_tag[0]}>'
    else:
        p[0] += p[1]



def p_content(p):
    '''
    content : element content
            | element
    '''
    p[0] = p[1]
    if len(p) == 3:
        p[0] += p[2]



def p_element_doctype(p):
    '''
    element : DOCTYPE
    '''
    if 'html' in p[1]:
        p[0] = '<!DOCTYPE html>'
    else:
        p[0] = '<?xml version="1.0" encoding="utf-8" ?>'



def p_element_normal_id(p):
    '''
    element : elem
            | INDENT elem
    '''
    global indent_level
    global min_indent
    global state
    global state_indent
    global tag_state
    global var_stack
    global space
    p[0] = ''

    var = ('','')
    if len(var_stack) > 0:
        var = var_stack.pop()

    if p[1] != '':
        if state != 'no':
            if var[0] != '':
                vars[var[0]] = var[1]
            if len(p) == 2:
                if p[1] == '<>':
                    p[1] = ''
                p[0] += p[1]
                if min_indent != 0:
                    elem = p[1].split('>')[0][1:]
                    p[0] += f'</{elem}>'
                    if len(second_stack) > 0:
                        second_stack.pop()
            else:
                if p[2] != '':
                    if state in ['if','else']:
                        p[1] = p[1].replace(' ','',4)
                    if p[2] == '<>':
                        p[2] = ''
                    p[0] += p[1] + p[2]
                    if min_indent == 0:
                        min_indent = len(p[1]) - 1
                        #space = p[1][1:]
        
                    indent_level = len(p[1]) - 1
    
    
            if len(second_stack) > 0:
                tag_stack.append((second_stack.pop(),indent_level))

    if state in ['if','no'] and state_indent == -1:
        state_indent = indent_level + min_indent
    if tag_state == 'if':
        tag_state = ''



def p_element_normal_dd(p):
    '''
    element : DEDENT elem
    '''
    global indent_level
    global min_indent
    global state
    global state_indent
    global tag_state
    global comment
    p[0] = ''

    var = ('','')
    if len(var_stack) > 0:
        var = var_stack.pop()

    indent = len(p[1]) - 1
    if state in ['if','else']:
        indent -= min_indent
    
    if state in ['no','if','else'] and indent <= state_indent:
        if tag_state == 'else' or tag_state == 'if':
            tag_state = ''
        else:
            state = 'normal'
            state_indent = -1
            indent += min_indent


    if state != 'no':
        if var[0] != '':
            vars[var[0]] = var[1]
        if p[2] != '' and len(tag_stack) > 0:
            if state in ['if','else']:
                p[1] = p[1].replace(' ','',4)
            if p[2] == '<>':
                p[2] = ''
            
            if comment == 0:
                cl_tag = tag_stack.pop()
                p[0] += f'</{cl_tag[0]}>'
                if len(tag_stack) > 0:
                    while tag_stack[-1][1] >= indent:
                        last_tag = tag_stack.pop()
                        spaces = last_tag[1] * space
                        p[0] += '\n' + spaces + f'</{last_tag[0]}>'
                        if len(tag_stack) == 0:
                            break
            elif comment == 1:
                comment = 2
            else:
                comment = 0
                    
            p[0] += p[1] + p[2]


        indent_level = len(p[1]) - 1
        if len(second_stack) > 0:
            tag_stack.append((second_stack.pop(),indent_level))
    

    if state == 'else' and state_indent == -1:
        state_indent = indent_level

    

def p_element_normal_sd(p):
    '''
    element : SAMEDENT elem
    '''
    global indent_level
    global state
    global vars
    global var_stack
    global comment
    p[0] = ''

    var = ('','')
    if len(var_stack) > 0:
        var = var_stack.pop()

    if state != 'no':
        if p[2] != '':
            if var[0] != '':
                vars[var[0]] = var[1]
            if state in ['if','else']:
                p[1] = p[1].replace(' ','',4)
            if p[2] == '<>':
                p[2] = ''
            
            if len(tag_stack) > 0 and '<!' not in p[2]:
                if comment == 0:
                    p[0] += f'</{tag_stack.pop()[0]}>'
                elif comment == 1:
                    comment = 2
                elif comment == 2:
                    comment = 0
                    p[0] += f'</{tag_stack.pop()[0]}>'

            p[0] += p[1] + p[2]


        indent_level = len(p[1]) - 1
        if len(second_stack) > 0:
            tag_stack.append((second_stack.pop(),indent_level))

    

def p_element_text_id(p):
    '''
    element : TEXT_INDENT elem
    '''
    p[0] = ''
    global state
    if state != 'no':
        if state in ['if','else']:
            p[1] = p[1].replace(' ','',4)
        p[0] = p[1] + p[2]

    

def p_element_text_dd(p):
    '''
    element : TEXT_DEDENT elem
    '''
    p[0] = ''
    global state
    if state != 'no':
        if state in ['if','else']:
            p[1] = p[1].replace(' ','',4)
        p[0] = p[1] + p[2]

    

def p_element_text_sd(p):
    '''
    element : TEXT_SAMEDENT elem
    '''
    p[0] = ''
    global state
    if state != 'no':
        if state in ['if','else']:
            p[1] = p[1].replace(' ','',4)
        p[0] = p[1] + p[2]



def p_elem_if(p):
    '''
    elem : ifClause
    '''
    p[0] = p[1]



def p_ifClause_if(p):
    '''
    ifClause : IF VAR
             | ELSE
    '''
    global state
    global vars
    global tag_state
    p[0] = ''
    if len(p) == 3:
        if p[2] in vars and vars[p[2]] != 'false':
            state = 'if'
        else:
            state = 'no'
        tag_state = 'if'
    else:
        if state == 'if':
            state = 'no'
        else:
            state = 'else'
        tag_state = 'else'



def p_ifClause_unless(p):
    '''
    ifClause : UNLESS VAR
    '''
    global state
    global vars
    global tag_state
    p[0] = ''
    if p[2] not in vars or (p[2] in vars and vars[p[2]] == 'false'):
        state = 'if'
    else:
        state = 'no'
    tag_state = 'if'



def p_elem_stuff(p):
    '''
    elem : stuff components   
    '''
    p[0] = p[1] + p[2]



def p_stuff(p):
    '''
    stuff : keyLine
          | keyLine attLine
    '''
    p[0] = f'<{p[1]}'
    if len(p) == 3:
        p[0] += f' {p[2]}'
    p[0] += f'>'



def p_keyLine_tag(p):
    '''
    keyLine : TAG
            | TAG classListLine
            | TAG idLine
    '''
    global second_stack
    p[0] = ''
    if p[1][-1] != '/':
        p[0] = f'{p[1]}'
        if len(p) == 3:
            p[0] += f' {p[2]}'
    else:
        p[1] = p[1].replace('/','')
    if state != 'no':
        second_stack.append(p[1])



def p_keyLine_class_id(p):
    '''
    keyLine : classListLine
            | idLine
    '''
    global second_stack
    p[0] = f'div {p[1]}'
    if state != 'no':
        second_stack.append('div')
    


def p_classListLine(p):
    '''
    classListLine : classList
                  | classList ID
    '''
    if len(p) == 2:
        p[0] = f'class="{p[1]}"'
    else:
        p[0] = f'class="{p[1]}" id="{p[2][1:]}"'



def p_classList(p):
    '''
    classList : CLASS classList
              | CLASS
    '''
    if len(p) == 3:
        p[0] = p[1][1:] + ' ' + p[2]
    else:
        p[0] = p[1][1:]



def p_idLine(p):
    '''
    idLine : ID
           | ID classList
    '''
    if len(p) == 2:
        p[0] = f'id="{p[1][1:]}"'
    else:
        p[0] = f'class="{p[2]}" id="{p[1][1:]}"'



def p_attLine(p):
    '''
    attLine : atts attLine
            | atts
    '''
    p[0] = p[1]
    if len(p) == 3:
        p[0] += f' {p[2]}'



def p_atts(p):
    '''
    atts : LPAR ATTS RPAR
         | S_C_ATTS LPAR ATTS RPAR
    '''
    if len(p) == 4:
        p[0] = p[2]
    else:
        p[0] = p[3]



def p_components_dds(p):
    '''
    components : D_DOT
               | SPACE textLine
               |
    '''
    p[0] = ''

    if len(p) == 3:
        p[0] += p[2]



def p_components_da(p):
    '''
    components : DOT
               | ASSIGN VAR
    '''
    global vars
    
    p[0] = ''
    if len(p) == (3):
        if p[2] in vars:
            p[0] += vars[p[2]]
    


def p_elem_text(p):
    '''
    elem : textLine
    '''
    p[0] = p[1]



def p_textLine_interpol(p):
    '''
    textLine : INTERPOL
             | INTERPOL TEXT
             | TEXT INTERPOL TEXT
    '''
    p[0] = ''
    if len(p) < 4:
        var = p[1][2:-1]
        if var in vars:
            add = vars[var].replace('"','')
            p[0] += f'{add}'
        if len(p) == 3:
            p[0] += p[2]
    else:
        var = p[2][2:-1]
        if var in vars:
            add = vars[var].replace('"','')
            p[0] += f'{p[1]}{add}{p[3]}'
        else:
            p[0] += f'{p[1]}{p[3]}'



def p_textLine_text(p):
    '''
    textLine : TEXT
             | TEXT INTERPOL
    '''
    p[0] = p[1]
    if len(p) == 3:
        var = p[2][2:-1]
        if var in vars:
            p[0] += vars[var].replace('"','')



def p_elem_comment(p):
    '''
    elem : COMMENT textLine
    '''
    global state
    global indent_level
    global comment
    if len(p[1]) == 3:
        p[0] = ''
    else:
        p[0] = f'<!--{p[2]}-->'
    comment = 1



def p_elem_var(p):
    '''
    elem : S_VAR VAR
    '''
    global var_stack
    global comment
    p[0] = ''
    split_var = p[2].split('=')
    var_stack.append((split_var[0].strip(),split_var[1].strip()))
    comment = 1




def p_error(p):
    print("Syntax error in input: ", p)

parser = yacc.yacc(debug=True)