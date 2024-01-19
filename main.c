// A função recebe o nó raiz, um endereço de vetor,
// e constrói um vetor crescente usando realloc.
void cria_vetor (noh *raiz, int vetor[]) {
 if (raiz != NULL) {
 cria_vetor (raiz -> esq, vetor);
 vetor = (int *) realloc (vetor, ++n * sizeof(int));
 vetor[n - 1] = raiz -> chave;
 cria_vetor (raiz -> dir, vetor);
 }
}
void insere_esquerda (noh *raiz, noh *esq) {
 noh *r = raiz;
 while (r -> esq != NULL) {
 r = r -> esq;
 }
 r -> esq = esq;
}
// recebe a raiz e insere o nó à direita da árvore
void insere_direita (noh *raiz, noh *dir) {
 noh *r = raiz;
 while (r -> dir != NULL) {
 r = r -> dir;
 }
 r -> esq = dir;
}
// recebe o vetor e tamanho e, a partir dele constrói a árvore
//balanceada.
noh cria_arv (int *vetor, int n) {
int meio = n/2;
noh raiz;
raiz.esq = raiz.dir = NULL;
raiz.chave = vetor[meio];
int i = meio - 1 ;
while (i >= 0) {
noh esq; esq.chave = vetor[i];
esq.esq = esq.dir = NULL;
insere_esquerda(&raiz, &esq);
i--;
}
int j = meio + 1;
while (j < n) {
noh dir;
dir.chave = vetor[j];
dir.esq = dir.dir = NULL;
insere_direita(&raiz, &dir);
j++;
}
return raiz;
}
