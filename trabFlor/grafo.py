# Importa a biblioteca subprocess para executar comandos do Graphviz que geram o PNG a partir do dotfile
import subprocess

# Função que gera a representação do grafo no dotfile
def gendot(graph):
    # Abre o arquivo "grafo.dot" para escrita
    gra = open("grafo.dot", "w+")

    # Escreve o cabeçalho do dotfile
    gra.write('digraph X {\n')

    gra.write('node[shape=circle]\n')

    # Parte da função que escreve as transiçoes no dotfile
    for x in graph:
        gra.write(' {} -> {} \n'.format(x[0], x[1]))

    # Fecha o dotfile
    gra.write("}\n")


# Abre o arquivo para leitura
f = open("Lista_Adjacencias.txt", "r")

lista = []

# Coleta os vertices do grafo
tamanho = f.readline()
for i in range(int(tamanho)):
    linha_lida = f.readline()
    elementoa, elementob = map(int, linha_lida.split(','))
    resultado = [elementoa, elementob]
    lista.append(resultado)
    
# Fecha o arquivo após a coleta dos dados
f.close()

# Primeiro, chamando a função que gera o dotfile
gendot(lista)
# Em seguida, executando o comando do Graphviz que gera um arquivo PNG a partir do DOT
command = 'neato -x -Goverlap=scale -Tpng grafo.dot > graph.png'
try:
    subprocess.run(command, shell=True, check=True)
except subprocess.CalledProcessError as e:
    print(e.stderr)
