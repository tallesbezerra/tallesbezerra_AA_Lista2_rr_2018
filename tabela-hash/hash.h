struct Lista{
    int valor;
    struct Lista* proximo;
};
typedef struct Lista lista;

int hashing(int v, int tam){
	return (v%tam);
}

lista *criarlista(void){
    return NULL;
}

lista* inserir(lista *l, int v){
	lista* novo = (lista*)malloc(sizeof(lista));
	novo->valor = v;
    novo->proximo = NULL;
	if (l==NULL)
		l = novo;
	else{
        novo->proximo = l;
        l = novo;
	}
    return l;
}

int buscarValor(lista *l[], int v, int tam){
	int i;
	i = hashing(v,tam);
    if (l[i]==NULL)
    	return 0;
    else{
        lista *aux;
    	for (aux=l[i]; aux!=NULL; aux=aux->proximo){
    		if (aux->valor==v)
    			return 1;
    	}
    	return 0;
    }
}

void mostrar(lista *l[], int tam){
	for (int i = 0; i < tam; ++i){
        printf("%d:\n", i);
        lista *aux;
		for (aux = l[i]; aux!=NULL; aux=aux->proximo){
			printf("%d ", aux->valor);
		}
		printf("\n\n");
	}
}

int listavazia(lista *l){
    if(l == NULL)
        return 1;
    else
        return 0;
}

void liberarlista(lista *l){
    lista *p = l;
    while(p!=NULL){
        lista *aux = p->proximo;
        free(p);
        p=aux;
    }
}