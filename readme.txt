Lucas Paire e Miguel Brondani
- Chave hash composta, formada pela concatenação do cálculo do cnpj + nome. Linhas do arquivo são usadas como endereço.
- hash.c: funções para calcular chave hash
- novoArquivo.c: funções para inserir na linha correta (ou próxima disponível) no arquivo o registro.
- utilidades.c: funções de suporte para testar colisões