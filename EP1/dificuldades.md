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
No caso era só ler melhor o que o exercício estava pedindo, fazer isso provavelmente complica desnecessariamente
Mas como eu gosto de complicar mesmo, o desenha_segmento foi útil. Quando fiz o código que já estava executando corretamente, percebi que a estrutura de if else estava repetida, e vi que no fim, a orientação, na verdade, era como se fosse um if else, no fim, a lógica de if else que estava antes:
```c
if (orientacao == H_HORIZONTAL) {
    linha_horizontal(img, x - tamanho, y, 2 * tamanho + 1, 1);
    arvore_h_rec(img, x - tamanho, y, tamanho, profundidade - 1, H_VERTICAL);
    arvore_h_rec(img, x + tamanho, y, tamanho, profundidade - 1, H_VERTICAL);
} else {
    linha_vertical(img, x, y - tamanho, 2 * tamanho + 1, 1);
    arvore_h_rec(img, x, y - tamanho, tamanho / 2, profundidade - 1, H_HORIZONTAL);
    arvore_h_rec(img, x, y + tamanho, tamanho / 2, profundidade - 1, H_HORIZONTAL);
}
```
Poderia ser substituida para uma lógica do seguinte sentido:
```c
//desenha o que tiver que desenhar
//tamanho -> tamanho - ((1/2)tamanho)*orientacao
//flippar H_HORIZONTAL -> H_VERTICAL
//x - (tamanho * orientacao), y - (tamanho * !orientacao)
//x + (tamanho * orientacao), y + (tamanho * !orientacao)
```
E aí o problema que eu estava tendo (como pode ser visto na árvore 4), é que eu estava atribuindo o tamanho como o jeito que estava acima, na mesma variável, só que, apesar de que quando vamos de vertical -> horizontal, o tamanho da linha diminuir, a distância (que é baseada no tamanho) continua a mesma, então é necessário, ou criar uma variável, como novo_tamanho ou adicionar o código que calcula o novo tamanho diretamente na chamada de função, e aí nesse segundo caso, deve-se flippar a orientação dentro do próprio código também.

Particularmente, não acho que essa solução seja fácil de ler, ou entender, não faria isso em um código real, mas ficou elegante o suficiente

O árvore 6 foi quando eu flippei todas as orientações dentro da chamada recursiva, mas esqueci de tirar o operacao = !operacao kkkkk, ficou bonitinho