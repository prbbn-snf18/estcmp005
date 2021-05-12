#Init
import random
objetivo = list("METHINKS IT IS LIKE A WEASEL")
alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "            #O espaço também deve ser considerado
n_filhos = 50
r_mut = 0.2
melhor_filho = []
pos_bloq = []                                   #lista com as posições que não precisam mais ser alteradas
pos_alt = []                                    #contém as posições que devem ser alteradas

#Faz uma string com o mesmo tamanho do objetivo
pai = []
for i in range(len(objetivo)):
    pai.append(random.choice(alfa))

#Loop
#Gera filho com mutação, escolhe o melhor para próxima geração
#para quando chega no objetivo
ger = 0
while melhor_filho != objetivo:
    ger = ger+1

    #Acompanha o número de mutações ruins, boas e neutras
    nf_bom = nf_ruim = nf_neutra = total_mut = 0.0

    #Acompanha quantos filhos são iguais os pais
    nf_igual = n_filhos

    #Gera filhos com mutações aleatórias
    lista_filhos = []
    for i in range(n_filhos):

        filho = pai[:]                      #Copia o conteúdo do pai para o filho
        
        filho_mudou = False
        for pos in pos_alt:

            if random.random() < r_mut:
                filho_mudou = True
                total_mut += 1

                letra_ant = pai[pos]
                letras_validas = set(alfa) - set(letra_ant)
                #Aleatoriamente seleciona uma nova letra
                letra_nova = random.choice(list(letras_validas))

                filho[pos] = letra_nova     #Altera o filho na posição

                if letra_ant == objetivo[pos]:  #Letra cetra foi alterada
                    nf_ruim += 1
                elif letra_nova == objetivo[pos]:   #Letra errada mudou para certa
                    nf_bom += 1
                else:                               #Letra errada mudou para outra errada
                    nf_neutra += 1

        if filho_mudou:
            nf_igual -= 1       #Acompanha mutações dos filhos

        lista_filhos.append(filho)          #adiciona filho na lista
    
    #Encontra filho mais parecido com o objetivo nesta geração
    menor_dif = len(objetivo) + 1
    for filho in lista_filhos:
        dif = 0.0
        for pos in range(len(objetivo)):
            if filho[pos] != objetivo[pos]:
                dif += 1

        if dif < menor_dif:
            menor_dif = dif
            melhor_filho = filho            #Guarda o melhor filho

    #Remove posição certa da lista de posições para serem alteradas
    lista_tmp = pos_alt[:]
    for pos in lista_tmp:
        if melhor_filho[pos] == objetivo[pos]:
            pos_alt.remove(pos)
    
    pai = melhor_filho          #O melhor filho se torna pai

    #Mostra o melhor filho dessa geração e
    #destaca diferenças com o objetivo, se houverem
    str_result = ""
    for pos in range(len(objetivo)):
        if melhor_filho[pos] == objetivo[pos]:
            str_result += melhor_filho[pos]
        else:
            str_result += melhor_filho[pos].lower() #Destaca as diferenças em minúsculo
    
    "%s\n" % (str_result)