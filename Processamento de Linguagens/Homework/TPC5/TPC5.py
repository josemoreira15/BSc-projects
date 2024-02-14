import re

def value_to_str(balance):
    result = str(balance//100) + 'e' + str(balance % 100) + 'c'

    return result


def make_return(balance):
    if balance == 0:
        return value_to_str(balance)
    
    else:
        coins = []
        def_coins = ['2e','1e','50c','20c','10c','5c','2c','1c']
        while balance > 0:
            if balance - 200 >= 0:
                coins.append("2e")
                balance -= 200
            elif balance - 100 >= 0:
                coins.append("1e")
                balance -= 100
            elif balance - 50 >= 0:
                coins.append("50c")
                balance -= 50
            elif balance - 20 >= 0:
                coins.append("20c")
                balance -= 20
            elif balance - 10 >= 0:
                coins.append("10c")
                balance -= 10
            elif balance - 5 >= 0:
                coins.append("5c")
                balance -= 5
            elif balance - 2 >= 0:
                coins.append("2c")
                balance -= 2
            elif balance - 1 >= 0:
                coins.append("1c")
                balance -= 1

        result = ''
        for coin in def_coins:
            count = coins.count(coin)
            if count > 0:
                result += str(coins.count(coin)) + 'x' + coin + ', '

        return result[:-2]

def value(money, balance):
    qt = 0
    coins = money.split(', ')
    for coin in coins:
        if re.match(r"[125]0?c",coin) or re.match(r"[12]e",coin):
            if coin[-1] == 'c':
                qt += int(coin[:-1])
            else:
                qt += int(coin[:-1])*100
        else:
            print(f'maq: "Moeda inválida: {coin}"')
    
    print(f'maq: Saldo = {value_to_str(qt + balance)}')
    
    return qt + balance


def phone_call(number, balance):
    if re.match(r"601|641",number):
        print('maq: "Chamada bloqueada!"')
    
    else:
        if re.match(r"00",number):
            if (balance - 150 >= 0):
                balance -= 150
            else:
                print('maq: "Saldo insuficiente!"')

        elif re.match(r"2",number):
            if (balance - 25 >= 0):
                balance -= 25
            else:
                print('maq: "Saldo insuficiente!"')

        elif re.match(r"800",number):
            print(f'maq: Saldo = {value_to_str(balance)}')
            return balance

        elif re.match(r"808",number):
            if (balance - 10 >= 0):
                balance -= 10
            else:
                print('maq: "Saldo insuficiente!"')
    
        else:
            print('maq: "Número inválido!"')

    print(f'maq: Saldo = {value_to_str(balance)}')

    return balance


def process(state, balance):
    if re.match(r"LEVANTAR$", state):
        print('maq: "Operação inválida... A máquina já se encontra funcional!"')
        return balance

    elif re.match(r"POUSAR$", state) or re.match(r"ABORTAR$", state):
        return balance

    elif re.match(r"MOEDA ([0-9]+c, |[0-9]+e, )*([0-9]+c|[0-9]+e)$", state):
        return value(state.split("MOEDA ")[1], balance)
    
    elif re.match(r"T=([1-9][0-9]{8})$", state) or re.match(r"T=([0-9][1-9][0-9]{7})$", state) or re.match(r"T=(00[0-9]{9})$", state):
        return phone_call(state.split("T=")[1], balance)

    else:
        print('maq: "Opção inválida!"')
        return balance

    
def main():
    state = ""
    balance = 0
    while(state != "LEVANTAR"):
        state = input('maq: "Digite "LEVANTAR" para iniciar a cabine telefónica!"\n')

    print('maq: "Introduza moedas."')
    while (state != "ABORTAR" and state != "POUSAR"):
        state = input()
        balance = process(state, balance)

    print(f'maq: "troco={make_return(balance)}; Volte sempre!"')

        
if __name__ == "__main__":
    main()