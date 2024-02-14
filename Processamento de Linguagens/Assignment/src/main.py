from _parser import parser

def main():
    file_name = input('Type the file name: ')
    with open('../pug_files/' + file_name) as file:
        content = file.read()

    html_file = file_name.replace('.pug','.html')
    with open('../converted_html_files/' + html_file,'w') as result:
        result.write(parser.parse(content))

if __name__ == '__main__':
    main()