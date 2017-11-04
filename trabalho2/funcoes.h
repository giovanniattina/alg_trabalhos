#ifndef	FUNCOES_H
#define FUNCOES_H

#include "skip_list.h"


/**
 * [recebe_linha recebe ate um \n no STDIN]
 * @param  linha [ponteiro para salvar oq erecebe]
 */
#define recebe_linha(linha) {\
 fgets(linha, 1001, stdin);\
 if(linha[strlen(linha) -1] == '\n' && strlen(linha) != 2) linha[strlen(linha) -1] = '\0';\
 }


/**
* [recebe_analiza recebe a entrada do STDIN e pega a chave e o conteudo]
 * @param  linha [entrada do STDIN]
 * @return       [informacoes de entrada separada em chave e conteudo]
 */
t_data *recebe_analiza(char *linha);

/**
 * [lista recebe a operacao que o usuario entro e os dados e aplica a ista]
 * @param t        [lista para fazer operacao]
 * @param operacao [operacao a ser feita na lista]
 * @param dado     [dados de entrada]
 */
void lista(t_lista *t, char *operacao, t_data *dado);

/**
 * [add_item pega um ponteiro de char antigo, adiciona os dados do novo ponteiro ]
 * @param  antigo [ponteiros com os dados antigos]
 * @param  novo   [ponteiro com o novo dado]
 * @return        [retorna o ponteiro com os dois dados]
 */
char *add_item(char *antigo, char *novo, int sobescreve);

/**
 * [acao_lista recebe o que foi dado no STDIN e retira apensa a acao dado pelo usuario]
 * @param  analiza [dado do STDIN]
 * @param  final   [ponteiro de int para salvar onde acaba a oprecao na string]
 * @return         [retorna um ponteiro de char com a oprecao na lista]
 */
char *acao_lista(char *analiza, int *final);


#endif
