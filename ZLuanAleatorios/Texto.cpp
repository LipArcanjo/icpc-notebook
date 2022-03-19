/*
N^e %m

Solves with euler totien function

n^e %m = n^ ( fi(m) + e%fi(m) ) %m, recursive allows, end with o(logm) steps to reach m = 1

Isso vale se: gcd(m,n) == 1 ou para qualque m,n se e ≥ log2(m) de acordo com pdf

A ideia eh basicamente que a gente tem uma equivalencia do numero de trees possiveis  e um vetor v de tamanho n-2 ( ?talvez - com os valores podendo variar no intervalo [1, N] ) .


Contar numero de triplas pitagoricas:

produtorio(2b + 1) - 1, onde b eh a potencia de um primo nao gaussiano diferente de 2 ( p%4 == 1)

Numero de pontos em um esfera de raio N:

formula: 6P*produtorio(  qr^br + 2*(qr^br-1)/(qr-1))
onde P e o produtorio dos primos nao gaussiano deferente de 2, e qr sao os primos gaussianos

Pick Theorem:

Area = i + b/2 - 1, onde i sao pontos interioes, b sao pontos da borda.

formula para R3:



Couting The number of ways of a Tree
Intuição.

Eh equivalente porque podemos gerar uma unica arvore utilizando o seguinte algoritmo →

adicione todos os elementos entre [1,N-1] que nao aparecem no vetor v a estrutura que guarda elementos candidatos a leaf, itere sobre o vetor, adione uma aresta entre v[i] e o menor elemento que esta na estruta, se eh v[i] eh a ultima ocorrencia de v[i] e v[i] ≠ N, o adicione a estrutura, no final havera apenas um elemento na estrutura, adicione uma aresta entre este elemento e N. Este processo monta apenas uma unica especifica arvore, agora vamos partir desta arvore para montar o array de volta.

Pegue a arvore atual, inicie um vetor v vazio faça esta iteração ate a arvore ter tamanho 2: pegue, entre todas as folhas da arvore, a que tiver menor indice, adicione ao final de v o "pai" da folha, remove a folha da arvore. Este processo eh exatamente o processo reverso de gerar a arvore a partir do vetor, pois como uma arvore tem ao menos 2 folhas, nós nunca adicionamos o vertice N, mesmo que ele seja uma folha,sendo semelhante ,
*/