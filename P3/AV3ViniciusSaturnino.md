% Aluno *Vinicius de Sousa Saturnino*, Matrícula *180132245*

# Enunciados
 - https://moj.naquadah.com.br/contests/bcr-FSO-2020_2-avaliacao-3/prova.pdf

# Questãoo 1

A rotina de page faults deve ficar sempre residente na memória principal não podendo ser removida então. Caso contrário quando necessário não será possível fazer o page-in.

# Questão 2

## Item A

### Subitem 1

0001 0000 0000 0111

### Subitem 2

0011 0000 1010 0000

### Subitem 3

0110 0000 0000 0101

### Subitem 4

Daria page fault

### Subitem 5

0010 0000 0000 0000

## Item B

Se a arquitetura for a de paginação pode ocorrer somente a fragmentação interna, pois o minimo sempre será alocado. A externa só seria possível com a arquitetura de segmentação. Isso ocorre por conta dos espaços livres deixados entre os segmentos que foram alocados na memória principal.

# Questão 3

Seria possível mas não seria viável e diminuiria o desempenho, pois seria necessário que o sistema operacional fizesse todo o trabalho a cada processo que teria que percorrer um caminho grande entre o processo ter que sair do processador para o sistema operacional fazer a tradução e retornar a memória convertida.

# Questão 4

## Item A

A função A seria a mais rápida.

## Item B

A função "A" faz o uso de registradores associativos (TLB).

Além disso função "A" percorre página por página ja preenchendo antes de ir para a próxima página e a função "B" preenche uma coluna por iteração. 
