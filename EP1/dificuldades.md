# Criação das funções de desenho
## Dificuldade: Baixa
Quase não tive dificuldade para implementar as funções de desenho, só me confundi um pouco porque (x,y) se acessa com img[y][x], pois o y deve ser a altura, portanto, a linha.

# Entendimento das funções já feitas
## Dificuldade: Média
Ainda não entendi muito bem o que as funções fazem, cantor parece relativamente simples, até consegui fazer alguma imagem, como no cantor1.pbm, mas nada parecia muito certo
### Cantor
No cantor5.pbm está fazendo algum tipo de recursão, mas não tá completo, não sei o motivo de só estar fazendo na esquerda, claramente o da direita, quando eu fui ver, era porque eu não estava somando o x com o comprimento
Agora o outro problema, é que ele está criando linhas adicionais no final do programa, tem 3
Resolvi verificando que, se for a última (profundidade > 1), então faz recursão, caso contrário
### Árvore H
Vou abordar a mesma estratégia que fez dar certo na de cantor, que é fazer primeiro só para um lado, e depois fazer outro. Criei uma função de desenho que é o desenha_segmento, e essencialmente, ele só faz a escolha se vai fazer o segmento verticalmente ou horizontalmente
Só não sei como vou fazer as subárvores, talvez depois eu tenha que fazer um desenha_segmento que desenhe a continuação também