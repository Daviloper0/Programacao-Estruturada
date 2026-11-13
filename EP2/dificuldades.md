# Indices
## Inicializa indice
Pelo que eu tinha entendido, devo fazer algo do tipo
```c
void inicializa_indice(Indice *indice) {
    indice -> entradas = NULL;
    indice -> n = 0;
    indice -> capacidade = 0;
}
```
para inicializar. O ep fala algo sobre a capacidade sempre dobrar, e que o campo n indica quantas posições estão sendo utilizadas, mas ainda não foi utilizada nenhuma posição, então faz sentido inicializar tudo com 0

## Busca palavra
Eu ia fazer esse depois de fazer a inserção, só que pra inserir, tem que ver se a palavra já não existe. Hashmap seria bom kkkkk

Então, o índice, ele tem um vetor de entradas, então se eu quero acessar a palavra dentro de um certo indice, eu tenho que fazer indice -> entradas -> palavra? É como se o índice fosse um "objeto" que guardasse uma informação sobre um array de entradas!? kkkk

Esqueci que a ordem importa, então o certo é eu verificar primeiro se i < (indice -> n)