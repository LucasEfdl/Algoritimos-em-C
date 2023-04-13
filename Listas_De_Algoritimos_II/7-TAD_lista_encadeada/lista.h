

typedef struct lista Lista;

Lista * lst_criar(void);

void lst_libera(Lista* l);

Lista* lst_insere(Lista* l, int i);

Lista* lst_retira(Lista* l, int v);

int lst_vazia(Lista* l);

Lista* lst_busca(Lista* l, int v);

void lst_imprime(Lista* l);

void lst_libera(Lista* l);

Lista * lst_insere_ordenado(Lista* l, int v);